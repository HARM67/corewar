/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 20:49:34 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/24 20:58:55 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	vm_print_type(t_type t)
{
	unsigned int	i;
	unsigned char	*p;

	i = t.size;
	p = (unsigned char*)&t.data;
	while (i > 0)
	{
		vm_print_hex(p[i - 1]);
		i--;
	}
}

void		vm_print_args(t_app *app, t_arg *arg)
{
	unsigned int	i;

	i = 0;
	while (i < 4)
	{
		ft_putstr("arg");
		ft_putnbr(i + 1);
		ft_putstr(" : ");
		vm_print_type(arg->arg[i]);
		ft_putstr("\n");
		i++;
	}
	if (app)
		;
}
