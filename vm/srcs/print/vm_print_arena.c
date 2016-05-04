/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 21:14:21 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/10 12:24:16 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_print_arena_line(t_app *app, unsigned char *memory,
	unsigned char *access, int j)
{
	unsigned int	i;

	i = 0;
	if (app)
		;
	while (i < 64)
	{
		vm_print_hex(memory[j * 64 + i]);
		if (access[j * 64 + i] & 0xf0)
			access[j * 64 + i] -= 0x10;
		access[j * 64 + i] &= 0xf7;
		i++;
		if (i != 64)
			write(1, " ", 1);
	}
}

void	vm_print_arena2(t_app *app)
{
	unsigned char	*memory;
	unsigned char	*access;
	unsigned int	j;

	j = 0;
	memory = app->arena.memory;
	access = app->arena.access;
	while (j < 64)
	{
		write(1, "0x", 2);
		vm_print_hex((j * 64) / 256);
		vm_print_hex((j * 64) % 256);
		write(1, " : ", 3);
		vm_print_arena_line(app, memory, access, j);
		write(1, "\n", 1);
		j++;
	}
}
