/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 06:52:26 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/10 08:34:57 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_fork(t_app *app, t_instance *inst)
{
	t_instance		*new_inst;
	t_instance		tmp;

	vm_create_instance(app);
	new_inst = app->last_instance;
	ft_memcpy(&tmp, new_inst, sizeof(t_instance));
	ft_memcpy(new_inst, app->current_instance, sizeof(t_instance));
	new_inst->pid = tmp.pid;
	new_inst->next = tmp.next;
	new_inst->previous = tmp.previous;
	new_inst->pc += vm_get_mem(app, inst->pc + 1, 2).data % IDX_MOD;
	new_inst->tmp_instr = 0;
	new_inst->cycle = app->cycle;
	if (app->flag_v5)
		ft_printf("P %4d | %s %d (%d)\n", inst->pid + 1,
			app->instr[app->current_instr - 1].name,
			vm_get_mem(app, inst->pc + 1, 2).data, new_inst->pc);
	new_inst->pc %= MEM_SIZE;
	return (3);
}
