/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:58:48 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/23 00:35:10 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_forward_pc(t_app *app)
{
	t_player	*player;
	t_instance	*inst;
	unsigned int	i;

	i = 0;
	while (i < app->nbr_player)
	{
		player = &app->players[i];
		inst = player->first_instance;
		while (inst)
		{
			inst->pc++;
			inst = inst->next;
		}
		i++;
	}
}

void	vm_loop(t_app *app)
{
	while (1)
	{
		vm_forward_pc(app);
		read(0, 0, 1);
		vm_print_arena(app);
	}
}
