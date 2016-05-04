/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:14:57 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/10 13:49:57 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_live(t_app *app, t_instance *inst)
{
	unsigned int	for_player;
	int				i;

	i = -1;
	for_player = vm_get_mem(app, inst->pc + 1, 4).data;
	if (app->flag_v5)
		ft_printf("P %4d | %s %d\n", inst->pid + 1,
			app->instr[app->current_instr - 1].name, for_player);
	app->total_live++;
	inst->last_live = app->cycle;
	app->arena.live[inst->pc] = 50;
	while (++i < (int)app->nbr_player)
	{
		if (app->player[i].id == for_player)
		{
			if (app->fl.v == 1)
				ft_printf("Player %d (%s) is said to be alive\n",
					i + 1, app->player[i].header.prog_name);
			app->last_player_live = (unsigned int)i;
			app->player[i].live_count++;
			app->player[i].last_live = app->cycle;
			return (5);
		}
	}
	return (5);
}
