CC =  gcc -Werror -Wextra -Wall

SRCPATH = ./srcs
INSTRPATH = $(SRCPATH)/instructions
PRINTPATH = $(SRCPATH)/print
LOOPPATH = $(SRCPATH)/loop
READPATH = $(SRCPATH)/read
UTILPATH = $(SRCPATH)/util
NCURSESPATH = $(SRCPATH)/ncurses

INCPATH = ./includes

LIBFT = ./../libft
FT_PRINTF = ./../ft_printf

HEADER = -I $(LIBFT)/includes -I $(INCPATH) -I $(FT_PRINTF)/includes

LIB =  -L$(FT_PRINTF) -L$(LIBFT) -lftprintf -lft -lncurses

SRC =	$(SRCPATH)/main.c\
		$(PRINTPATH)/vm_print_error.c\
		$(PRINTPATH)/vm_print_arg.c\
		$(PRINTPATH)/vm_print_player.c\
		$(PRINTPATH)/vm_print_arena.c\
		$(LOOPPATH)/vm_loop_verbose.c\
		$(LOOPPATH)/vm_loop_debug.c\
		$(LOOPPATH)/vm_exec.c\
		$(READPATH)/vm_read_player.c\
		$(READPATH)/vm_read_arg.c\
		$(UTILPATH)/vm_check_init.c\
		$(UTILPATH)/vm_util.c\
		$(UTILPATH)/vm_util_mem.c\
		$(UTILPATH)/vm_util_instance.c\
		$(UTILPATH)/vm_init.c\
		$(UTILPATH)/vm_init_instance.c\
		$(INSTRPATH)/vm_live.c\
		$(INSTRPATH)/vm_add.c\
		$(INSTRPATH)/vm_sub.c\
		$(INSTRPATH)/vm_and.c\
		$(INSTRPATH)/vm_or.c\
		$(INSTRPATH)/vm_xor.c\
		$(INSTRPATH)/vm_zjmp.c\
		$(INSTRPATH)/vm_sti.c\
		$(INSTRPATH)/vm_st.c\
		$(INSTRPATH)/vm_ld.c\
		$(INSTRPATH)/vm_lld.c\
		$(INSTRPATH)/vm_ldi.c\
		$(INSTRPATH)/vm_lldi.c\
		$(INSTRPATH)/vm_fork.c\
		$(INSTRPATH)/vm_lfork.c\
		$(INSTRPATH)/vm_aff.c\

SRC_BONUS = $(LOOPPATH)/vm_loop_ncurses.c\
		$(NCURSESPATH)/vm_nc_init.c\
		$(NCURSESPATH)/vm_nc_util.c\
		$(NCURSESPATH)/vm_nc_menu.c\
		$(NCURSESPATH)/vm_nc_event.c\
		$(NCURSESPATH)/vm_nc_init_color.c\

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = corewar

all : $(NAME)

$(NAME) : make_general return

return :
	@echo ""

make_general : make_libft make_ft_printf $(OBJ)
	@$(CC) $(HEADER) $(OBJ) $(LIB) -o $(NAME)

bonus : fclean make_libft make_ft_printf $(SRC_BONUS) $(SRC)
	@echo ""
	@echo "Compilation de la partie bonus... \c"
	@$(CC) $(HEADER) $(SRC) $(SRC_BONUS) $(LIB) -DBONUS -o $(NAME)
	@echo "OK. Faites \"make syscall_bonus\" pour afficher les syscall du bonus graphique"

make_libft :
	@make -C $(LIBFT)

make_ft_printf :
	@make -C $(FT_PRINTF)

%.o: %.c
	@$(CC) $(HEADER) -o $@ -c $<
	@echo "\033[31m█\033[0m\c"

clean : 
	@make -C $(LIBFT) fclean
	@make -C $(FT_PRINTF) fclean
	@rm -rf $(OBJ)
	@echo "Tout les .o de la vm ont ete supprime."

fclean : clean
	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)
	@echo "La vm a ete supprime."

re : fclean all

syscall : $(NAME)
	@echo "Syscall vm :"
	@nm $(NAME) | grep " U " | grep -v ___stack_chk_fail | grep -v ___stack_chk_guard | grep -v dyld_stub_binder | cut -f 19 -d ' ' | sed 's/^_/        /g'

syscall_bonus : bonus
	@echo "Syscall bonus vm :"
	@nm $(NAME) | grep " U " | grep -v ___stack_chk_fail | grep -v ___stack_chk_guard | grep -v dyld_stub_binder | cut -f 19 -d ' ' | sed 's/^_/        /g'

.PHONY: all clean fclean re syscall
