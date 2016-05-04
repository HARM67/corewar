/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 00:01:42 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/10 02:43:05 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	vm_check_instance(t_app *app, int i)
{
	t_instance		*inst;
	t_instance		*inst2;
	unsigned int	total_live;

	total_live = 0;
	inst = app->last_instance;
	while (inst)
	{
		inst2 = inst->previous;
		if ((int)inst->last_live <= (int)app->cycle - (int)app->cycle_to_die)
		{
			inst->is_dead = 1;
			vm_remove_instance(app, inst);
		}
		inst = inst2;
	}
	total_live = app->player[i].live_count;
	app->player[i].live_count = 0;
	return (total_live);
}

static void	vm_check_cycle(t_app *app)
{
	unsigned int	i;
	unsigned int	total_live;

	i = 0;
	total_live = 0;
	app->last_check = app->cycle;
	app->check_count++;
	while (i < app->nbr_player)
	{
		total_live += vm_check_instance(app, i);
		i++;
	}
	if (app->total_live >= NBR_LIVE || app->check_count >= MAX_CHECKS)
	{
		app->cycle_to_die -= CYCLE_DELTA;
		app->check_count = 0;
	}
	app->total_live = 0;
}

static void	vm_exec_instruction(t_app *app, t_instance *inst,
	int tmp, int token)
{
	if (token == 1)
	{
		if (app->cycle - inst->cycle < app->instr[inst->tmp_instr - 1].cost)
			return ;
		tmp = inst->pc;
		tmp += app->instr[inst->tmp_instr - 1].action(app, inst);
		inst->pc = (tmp >= 0) ? tmp % MEM_SIZE : tmp + MEM_SIZE;
		inst->tmp_instr = 0;
		inst->cycle = app->cycle;
	}
	else if (token == 2)
	{
		if ((app->arena.memory[inst->pc] >= 1 &&
			app->arena.memory[inst->pc] <= 16))
			inst->tmp_instr = app->arena.memory[inst->pc];
		else
		{
			inst->pc = (inst->pc + 1) % MEM_SIZE;
			inst->cycle = app->cycle;
		}
	}
}

void		vm_exec_instance(t_app *app)
{
	t_instance	*inst;
	int			tmp;

	tmp = 0;
	inst = app->last_instance;
	while (inst)
	{
		app->current_instance = inst;
		app->current_instr = inst->tmp_instr;
		if (inst->pid + 1 == app->focus && !app->flag_v5)
			ft_printf("pid : %d, pc : %d, cycle : %d, instruction : %s\n",
				inst->pid + 1, inst->pc, inst->cycle,
				(inst->tmp_instr >= 1 && inst->tmp_instr <= 16) ?
				app->instr[inst->tmp_instr - 1].name : "null");
		if (inst->tmp_instr != 0)
			vm_exec_instruction(app, inst, tmp, 1);
		else
			vm_exec_instruction(app, inst, tmp, 2);
		app->arena.access[inst->pc] |= 0x08;
		inst = inst->previous;
	}
}

void		vm_exec_player(t_app *app)
{
	vm_exec_instance(app);
	if (app->cycle - app->last_check >= app->cycle_to_die)
		vm_check_cycle(app);
}
