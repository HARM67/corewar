CC = gcc -Werror -Wextra -Wall

SRCPATH = ./srcs
UTILPATH = $(SRCPATH)/util
SETDATA = $(SRCPATH)/set_data
PRINT = $(SRCPATH)/print
PARSING = $(SRCPATH)/parsing
ERROR = $(SRCPATH)/error

LIBFT = ./../libft
FTPRINTF = ./../ft_printf

INCPATH = -I $(LIBFT)/includes -I $(FTPRINTF)/includes -I./includes

HEADER = ./includes/asm.h ./includes/op.h

LIB	= -L$(LIBFT) -lft -L$(FTPRINTF) -lftprintf -o $(NAME)

SRC = $(SRCPATH)/main.c\
	  $(UTILPATH)/asm_util.c\
	  $(UTILPATH)/asm_cursor.c\
	  $(SETDATA)/asm_set_btcode.c\
	  $(SETDATA)/asm_read_file.c\
	  $(SETDATA)/asm_push_data.c\
	  $(SETDATA)/asm_init.c\
	  $(PRINT)/asm_write.c\
	  $(PARSING)/asm_parsing.c\
	  $(PARSING)/asm_parsing_header.c\
	  $(ERROR)/asm_util_error.c\
	  $(ERROR)/asm_error_param.c\
	  $(ERROR)/asm_error_param_syntax.c\
	  $(ERROR)/asm_error_param_syntax_ind.c\
	  $(ERROR)/asm_error_label.c\
	  $(ERROR)/asm_error_instr.c\
	  $(ERROR)/asm_error.c\

OBJ = $(SRC:.c=.o)

NAME = asm

all : $(NAME)

$(NAME) : make_general return

return :
	@echo ""

make_general : make_libft make_ft_printf $(OBJ)
	@$(CC) $(INCPATH) $(OBJ) $(LIB) -o $(NAME)

make_libft:
	@make -C $(LIBFT)

make_ft_printf:
	@make -C $(FTPRINTF)

%.o: %.c $(HEADER)
	@$(CC) $(INCPATH) -o $@ -c $<
	@echo "\033[33m█\033[0m\c"

clean :
	@make -C $(LIBFT) fclean
	@make -C $(FTPRINTF) fclean
	@rm -rf $(OBJ)
	@echo "Tout les .o de l'asm ont ete supprime."

fclean : clean
	@make -C $(LIBFT) fclean
	@make -C $(FTPRINTF) fclean
	@rm -rf $(NAME)
	@echo "L'asm a ete supprime."

re : fclean all

syscall : $(NAME)
	@echo "Syscall asm :"
	@nm $(NAME) | grep " U " | grep -v ___stack_chk_fail | grep -v ___stack_chk_guard | grep -v dyld_stub_binder | cut -f 19 -d ' ' | sed 's/^_/        /g'

test : $(NAME)
	@make -C test

.PHONY: all clean fclean re test
