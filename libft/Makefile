NAME = libft.a
SRC = ft_memset.c\
	  ft_bzero.c\
	  ft_memcpy.c\
	  ft_memccpy.c\
	  ft_memmove.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_strlen.c\
	  ft_strdup.c\
	  ft_strcpy.c\
	  ft_strncpy.c\
	  ft_strcat.c\
	  ft_strncat.c\
	  ft_strlcat.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_strstr.c\
	  ft_strnstr.c\
	  ft_strcmp.c\
	  ft_strncmp.c\
	  ft_atoi.c\
	  ft_isalpha.c\
	  ft_isdigit.c\
	  ft_isalnum.c\
	  ft_isascii.c\
	  ft_isprint.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  ft_memalloc.c\
	  ft_memdel.c\
	  ft_strnew.c\
	  ft_strdel.c\
	  ft_strclr.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strsub.c\
	  ft_strjoin.c\
	  ft_strjoin_free.c\
	  ft_strtrim.c\
	  ft_strsplit.c\
	  ft_itoa.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_putendl.c\
	  ft_putnbr.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_lstnew.c\
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_lstadd.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_printbit.c\
	  ft_reversebit.c\
	  ft_itoa_base.c\
	  ft_putnbr_base.c\
	  ft_lstpush_front.c\
	  ft_lstpush_back.c\
	  ft_lstsize.c\
	  ft_lsttotab.c\
	  ft_tablen.c\
	  ft_tabjoin.c\
	  ft_strndup.c\
	  get_next_line.c

OBJ = $(SRC:.c=.o)

INC = ./includes

CC = gcc -Wall -Werror -Wextra

all : $(NAME)
	@echo "\c"

$(NAME) : $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -I$(INC) -c $^
	@echo "\033[32m█\033[0m\c"

clean :
	@rm -f $(OBJ)
	@echo "Tout les .o de la libft ont ete supprime."

fclean : clean
	@rm -f $(NAME)
	@echo "libft.a a ete supprime."

re : fclean all
