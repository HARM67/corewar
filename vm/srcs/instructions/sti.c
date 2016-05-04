/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 03:50:29 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/23 04:20:26 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_sti(t_app *app, t_instance *inst)
{
	unsigned char	codage;

	codage = app->arena.memory[inst->pc + 1];
	if ((codage & 0xc0) == 0x40)
		ft_putstr("1 registre\n");
	return (1);
}
