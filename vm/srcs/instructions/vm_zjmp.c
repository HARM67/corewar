/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 02:52:21 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/10 08:28:40 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_zjmp(t_app *app, t_instance *inst)
{
	short int		jmp;
	unsigned char	*p;

	p = (unsigned char *)&jmp;
	p[0] = app->arena.memory[(inst->pc + 2) % MEM_SIZE];
	p[1] = app->arena.memory[(inst->pc + 1) % MEM_SIZE];
	if (app->flag_v5)
		ft_printf("P %4d | %s %d ", inst->pid + 1,
			app->instr[app->current_instr - 1].name, jmp);
	if (inst->carry != 1)
	{
		if (app->flag_v5)
			ft_printf("FAILED\n");
		return (3);
	}
	if (app->flag_v5)
		ft_printf("OK\n");
	return (jmp % IDX_MOD);
}
