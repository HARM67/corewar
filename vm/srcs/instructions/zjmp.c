/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 02:52:21 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/23 04:06:22 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_zjmp(t_app *app, t_instance *inst)
{
	short int		jmp;
	unsigned char	*p;

	if (inst->carry != 1)
		return (1);
	p = (unsigned char *)&jmp;
	p[0] = app->arena.memory[inst->pc + 2];
	p[1] = app->arena.memory[inst->pc + 1];
	return (jmp);
}
