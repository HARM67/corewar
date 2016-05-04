/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_instance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 22:41:42 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/10 02:39:13 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	vm_insert_instance(t_app *app, t_instance *inst,
		unsigned int pos, unsigned int player_nbr)
{
	unsigned int	i;
	t_player		*player;
	t_arena			*arena;

	i = 0;
	arena = &app->arena;
	player = &app->player[player_nbr];
	inst->pc = pos;
	while (i < app->player[player_nbr].header.prog_size)
	{
		arena->memory[pos + i] = player->prog[i];
		arena->access[pos + i] = player_nbr + 1;
		i++;
	}
}

void		vm_first_instantiation(t_app *app)
{
	t_instance		*inst;
	unsigned int	i;

	i = 0;
	inst = app->first_instance;
	while (inst && i < app->nbr_player)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i + 1,
			app->player[i].header.prog_size, app->player[i].header.prog_name,
			app->player[i].header.comment);
		inst->reg[0] = app->player[i].id;
		inst->creator = i;
		vm_insert_instance(app, inst, i * MEM_SIZE / app->nbr_player, i);
		inst = inst->next;
		i++;
	}
}
