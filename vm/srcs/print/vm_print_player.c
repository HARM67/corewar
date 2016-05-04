/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:58:54 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/10 02:41:24 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_put_winner(t_app *app)
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
			app->player[app->last_player_live].id,
			app->player[app->last_player_live].header.prog_name);
}

void	print_instance(t_app *app, t_instance *inst)
{
	unsigned int	i;

	i = 0;
	while (i < REG_NUMBER)
	{
		ft_putstr("r");
		ft_putnbr(i + 1);
		ft_putstr(" : ");
		ft_putnbr(inst->reg[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("carry : ");
	ft_putnbr(inst->carry);
	ft_putstr("\n");
	if (app)
		;
}

void	print_instances(t_app *app)
{
	t_instance	*inst;

	inst = app->first_instance;
	while (inst)
	{
		print_instance(app, inst);
		inst = inst->next;
	}
}

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
	write(1, "\nPlayer live : ", 15);
	ft_putnbr(player->live_count);
	write(1, "\n", 1);
	write(1, "\n", 1);
	if (app)
		;
}
