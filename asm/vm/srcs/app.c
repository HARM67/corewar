/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:18:44 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/23 00:35:24 by mfroehly         ###   ########.fr       */
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
	print_player(app, &app->players[0]);
	print_player(app, &app->players[1]);
	print_player(app, &app->players[2]);
	print_player(app, &app->players[3]);
	vm_first_instantiation(app);
	//init_instruction(app);
	//app->instr[0].action(app, 0);
}

void	run_app(t_app *app)
{
	vm_loop(app);
}
