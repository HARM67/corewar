/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 00:01:42 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/23 04:14:52 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	vm_exec_instance(t_app *app, t_player *player)
{
	t_instance *inst;
	unsigned char	c;

	inst = player->current_instance;
	if (app->arena.memory[inst->pc] == 1 || app->arena.memory[inst->pc] == 9 || app->arena.memory[inst->pc] == 11)
		inst->pc += app->instr[app->arena.memory[inst->pc] - 1].action(app, inst) % MEM_SIZE;
	else
		inst->pc = (inst->pc + 1) % MEM_SIZE;
	/*
	player->current_instance = (player->current_instance->next) ?
			player->current_instance->next : player->first_instance;
*/}

void		vm_exec_player(t_app *app)
{
	unsigned int	i;

	i = 0;
	while (i < app->nbr_player)
		vm_exec_instance(app, &app->players[i++]);
}
