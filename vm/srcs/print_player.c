/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:58:54 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/22 20:06:51 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_program(unsigned char *program, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		vm_print_hex(program[i++]);
		if (i < size)
			write(1, " ", 1);
	}
}

void	print_player(t_app *app, t_player *player)
{
	write(1, "Player name : ", 14);
	write(1, &player->header.prog_name, 128);
	write(1, "\nPlayer Size : ", 15);
	ft_putnbr(player->header.prog_size);
	write(1, "\nPlayer Comment : ", 18);
	write(1, &player->header.comment, 2048);
	write(1, "\n", 1);
	print_program(player->prog, player->header.prog_size);
	write(1, "\n", 1);
}
