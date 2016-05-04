NAME = libftprintf.a
FLAG = -Wall -Werror -Wextra
COMPILER = gcc
SRCS_PATH = ./srcs/
SRC = ft_printf.c itoa_4.c itoa_2.c itoa_1.c itoa_8.c \
		uitoa_base_1.c uitoa_base_2.c uitoa_base_4.c uitoa_base_8.c \
		insert_flag.c argtoa.c read_flag.c print_arg.c \
		unicode.c ft_strncon.c ftoa.c flag_tool.c stoa.c make_str.c \
		printf_loop.c n_base.c color.c ft_islower.c ft_isupper.c
INCLUDES  = ./includes
OBJ = $(SRC:%.c=%.o)

all : $(NAME)
	@echo "\c"

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: $(SRCS_PATH)%.c
	@echo "\033[34m█\033[0m\c"
	@$(COMPILER) -c $(FLAG) $< -I$(INCLUDES)

clean :
	@rm -f $(OBJ)
	@echo "Tout les .o du ft_printf ont ete supprime."

fclean : clean
	@rm -f $(NAME)
	@echo "ft_printf.a a ete supprime."

re: fclean all
