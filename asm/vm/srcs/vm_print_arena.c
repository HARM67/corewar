/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 21:14:21 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/23 00:33:28 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_print_pc(t_app *app, unsigned int pos)
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
			if (pos == inst->pc)
				write(1, "\033[7m", 4);
			inst = inst->next;
		}
		i++;
	}
}

void	vm_print_color(unsigned char id)
{
	if (id == 0)
		write(1, "\033[40m", 5);
	else if (id == 1)
		write(1, "\033[32m", 5);
	else if (id == 2)
		write(1, "\033[34m", 5);
	else if (id == 3)
		write(1, "\033[31m", 5);
	else if (id == 4)
		write(1, "\033[36m", 5);
}

void	vm_print_arena(t_app *app)
{
	unsigned char	*memory;
	unsigned char	*access;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	memory = app->arena.memory;
	access = app->arena.access;
	while (j < 64)
	{
		write(1, "0x", 2);
		vm_print_hex((j * 64 + i) / 256);
		vm_print_hex((j * 64 + i) % 256);
		write(1, " : ", 3);
		while (i < 64)
		{
			vm_print_color(access[j * 64 + i]);
			vm_print_pc(app, j * 64 + i);
			vm_print_hex(memory[j * 64 + i]);
			i++;
			if (i != 64)
				write(1, " ", 1);
			write(1, "\033[0m", 5);
		}
				write(1, "\n", 1);
		i = 0;
		j++;
	}
}
