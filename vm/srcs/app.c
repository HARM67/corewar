/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:18:44 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/23 04:06:33 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_app(t_app *app)
{
	init_arena(app);
	app->nbr_player = 4;

	app->players[0] = *read_player(app, "zork.cor");
	app->players[1] = *read_player(app, "helltrain.cor");
	app->players[2] = *read_player(app, "zork.cor");
	app->players[3] = *read_player(app, "zork.cor");
	app->players[0].id = 1;
	app->players[1].id = 2;
	app->players[2].id = 3;
	app->players[3].id = 4;
	app->players[0].first_instance->reg[0] = 1;
	app->players[1].first_instance->reg[0] = 2;
	app->players[2].first_instance->reg[0] = 3;
	app->players[3].first_instance->reg[0] = 4;
	/*
	print_player(app, &app->players[0]);
	print_player(app, &app->players[1]);
	print_player(app, &app->players[2]);
	print_player(app, &app->players[3]);
	*/
	vm_first_instantiation(app);
	init_instruction(app);
}

void	run_app(t_app *app)
{
	vm_loop(app);
}
