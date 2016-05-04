/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 07:47:32 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/22 18:48:32 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			vm_put_error(char *str)
{
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\033[0m\n", 2);
	exit(1);
}

void			vm_put_error_line(char *str, int line)
{
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("[", 2);
	ft_putnbr_fd(line, 2);
	ft_putstr_fd("]", 2);
	ft_putstr_fd("\033[0m\n", 2);
	exit(1);
}

void			vm_put_error_str(char *str1, char *str2)
{
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd("[", 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd("]", 2);
	ft_putstr_fd("\033[0m\n", 2);
	exit(1);
}

void			vm_put_error_char_int_int(char *str, char c, int line, int col)
{
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("[", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("]", 2);
	ft_putstr_fd("[", 2);
	ft_putnbr_fd(line, 2);
	ft_putstr_fd(":", 2);
	ft_putnbr_fd(col, 2);
	ft_putstr_fd("]", 2);
	ft_putstr_fd("\033[0m\n", 2);
	exit(1);
}

void			vm_put_error_str_int_int(char *str1, char *str2,
		int line, int col)
{
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(str1, 2);
	if (str2 && str2[0])
	{
		ft_putstr_fd("[", 2);
		ft_putstr_fd(str2, 2);
		ft_putstr_fd("]", 2);
	}
	ft_putstr_fd("[", 2);
	ft_putnbr_fd(line, 2);
	ft_putstr_fd(":", 2);
	ft_putnbr_fd(col, 2);
	ft_putstr_fd("]", 2);
	ft_putstr_fd("\033[0m\n", 2);
	exit(1);
}
