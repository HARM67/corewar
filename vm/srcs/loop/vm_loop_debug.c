/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 04:23:22 by atrupin           #+#    #+#             */
/*   Updated: 2016/03/10 04:34:42 by atrupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_loop_dump(t_app *app)
{
	if (!app->fl.g)
	{
		while (app->cycle <= app->start_cycle)
		{
			if (app->cycle_to_die > CYCLE_TO_DIE)
				break ;
			vm_exec_player(app);
			app->cycle++;
		}
		vm_print_arena2(app);
	}
}
