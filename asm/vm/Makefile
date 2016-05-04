CC = gcc -Wextra -Wall

SRCPATH = ./srcs
INSTRPATH = $(SRCPATH)/instructions

INCPATH = ./includes

LIBFT = ./libft

HEADER = -I $(LIBFT)/includes -I $(INCPATH)

LIB = $(LIBFT)/libft.a 

SRC =	$(SRCPATH)/main.c\
		$(SRCPATH)/app.c\
		$(SRCPATH)/vm_error.c\
		$(SRCPATH)/read_player.c\
		$(SRCPATH)/util.c\
		$(SRCPATH)/init_arena.c\
		$(SRCPATH)/vm_print_arena.c\
		$(SRCPATH)/create_instance.c\
		$(SRCPATH)/init_instruction.c\
		$(SRCPATH)/loop.c\
		$(INSTRPATH)/live.c\
		$(SRCPATH)/print_player.c

OBJ = $(SRC:.c=.o)

NAME = corewar

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@$(CC) $(HEADER) $(LIB) -o $(NAME) $(OBJ)
	@echo " "
	@echo "   \033[33m                                         \033[043m        \033[0m"
	@echo "   \033[33m                      \033[41m              \033[0m     \033[043m        \033[0m"
	@echo "   \033[33m                    \033[41m                        \033[043m     \033[0m"
	@echo "   \033[33m                    \033[100m        \033[43m     \033[0m\033[100m   \033[0m\033[43m   \033[0m  \033[100m        \033[0m"
	@echo "   \033[33m                  \033[100m  \033[43m   \033[0m\033[100m   \033[0m\033[43m       \033[0m\033[100m   \033[0m\033[43m     \033[0m\033[100m        \033[0m"
	@echo "   \033[33m                  \033[100m  \033[43m░░░\033[0m\033[100m      \033[0m\033[43m       \033[0m\033[100m   \033[0m\033[43m        \033[0m\033[100m  \033[0m"
	@echo "   \033[33m                  \033[100m     \033[43m░░░░░░░░░░\033[0m\033[100m              \033[0m"
	@echo "   \033[33m                       \033[43m░░░░░░░░░░░░░░░░░░\033[0m\033[100m   \033[0m"
	@echo "   \033[33m             \033[100m             \033[41m   \033[0m\033[100m       \033[0m\033[41m   \033[0m\033[100m  \033[0m"
	@echo "   \033[33m           \033[100m                  \033[41m   \033[0m\033[100m       \033[0m\033[41m  \033[0m     \033[100m  \033[0m"
	@echo "   \033[33m         \033[043m    \033[0m\033[100m                \033[41m            \033[0m     \033[100m  \033[0m"
	@echo "   \033[33m         \033[043m      \033[0m   \033[041m     \033[0m\033[100m   \033[41m      \033[0m\033[043m  \033[0m\033[041m     \033[0m\033[043m  \033[0m\033[041m   \033[0m\033[100m    \033[0m"
	@echo "   \033[33m           \033[043m░░\033[0m  \033[100m   \033[0m\033[041m                          \033[0m\033[100m    \033[0m"
	@echo "   \033[33m             \033[100m       \033[0m\033[041m                        \033[0m\033[100m    \033[0m"
	@echo "   \033[33m           \033[100m       \033[0m\033[041m                  \033[0m"
	@echo "   \033[33m           \033[100m  \033[0m     \033[041m          \033[0m"
	@echo " "
	@echo " "
	@echo "\033[043m                                                              \033[0m"
	@echo "\033[043m                         \033[030mC O R E W A R                        \033[0m"
	@echo "\033[043m                           \033[035mTeam DAMN                          \033[0m"
	@echo "\033[043m           \033[030mdlouise    atrupin    mfroehly    nle-bret         \033[0m"
	@echo "\033[043m                                                              \033[0m"
	@echo " "

%.o: %.c
	@$(CC) $(HEADER) -o $@ -c $<
	@echo "\033[33m█\033[0m\c"

clean : 
#	@make -C $(LIBFT) clean
	rm -rf $(OBJ)

fclean : clean
#	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
