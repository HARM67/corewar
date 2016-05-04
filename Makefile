# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlouise <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 00:14:33 by dlouise           #+#    #+#              #
#    Updated: 2016/03/12 06:32:17 by dlouise          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE_ASM = asm/asm
EXE_VM = vm/corewar

NAME = $(EXE_ASM) $(EXE_VM)

all : $(NAME)

$(NAME) :
	@echo "\033[032mlibft\033[0m"
	@echo "\033[034mft_printf\033[0m"
	@echo "\033[033masm\033[0m"
	@echo "\033[031mvm\033[0m"
	@make -C asm make_general
	@make -C vm make_general
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

clean :
	@make -C asm clean
	@make -C vm clean

fclean :
	@echo "fclean de l'asm..."
	@make -C asm fclean
	@echo "fclean de la vm..."
	@make -C vm fclean

re : fclean all

libft :
	@make -C libft
	@echo ""

libft_fclean :
	@make -C libft fclean

libft_clean :
	@make -C libft clean

libft_re :
	@make -C libft re
	@echo ""

ft_printf :
	@make -C ft_printf

ft_printf_fclean :
	@make -C ft_printf fclean

ft_printf_clean :
	@make -C ft_printf clean

ft_printf_re :
	@make -C ft_printf re
	@echo ""

syscall : syscall_asm syscall_vm

syscall_vm :
	@make -C vm syscall

syscall_asm :
	@make -C asm syscall

syscall_bonus : syscall_asm
	@make -C vm syscall_bonus

bonus :
	@make -C asm
	@make -C vm bonus

.PHONY: all clean fclean re libft ft_printf
