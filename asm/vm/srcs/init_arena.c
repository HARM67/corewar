/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:53:46 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/23 00:30:15 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	vm_insert_player(t_app *app, t_player *player, unsigned int pos)
{
	unsigned int	i;
	t_arena			*arena;

	i = 0;
	arena = &app->arena;
	player->first_instance->pc = pos;
	while (i < player->header.prog_size)
	{
		arena->memory[pos + i] = player->prog[i];
		arena->access[pos + i] = player->id;
		i++;
	}
}

void	vm_first_instantiation(t_app *app)
{
	unsigned int	i;

	i = 0;
	while (i < app->nbr_player)
	{
		vm_insert_player(app, &app->players[i], i * MEM_SIZE / app->nbr_player);
//		insert_instance_in_arena(app, vm_create_instance(app, &app->players[i]),
//				i * MEM_SIZE / app->nbr_player);
		i++;
	}
}

void	init_arena(t_app *app)
{
	t_arena	*arena;

	arena = &app->arena;
	arena->memory = (unsigned char *)ft_memalloc(sizeof(unsigned char) *
			MEM_SIZE);
	if (!arena->memory)
		vm_put_error("Error : can't create arena memory");
	arena->access = (unsigned char *)ft_memalloc(sizeof(unsigned char) *
			MEM_SIZE);
	if (!arena->access)
		vm_put_error("Error : can't create arena access memory");
}
