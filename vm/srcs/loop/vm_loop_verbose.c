/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop_verbose.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 05:23:13 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/08 10:32:25 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_loop_verbose(t_app *app)
{
	while (app->cycle_to_die <= CYCLE_TO_DIE)
	{
		app->cycle++;
		vm_exec_player(app);
	}
	app->cycle++;
	vm_exec_player(app);
	vm_put_winner(app);
}
