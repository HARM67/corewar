/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_nc_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 00:49:49 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/10 00:49:50 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_nc_check_size_term(t_app *app, t_render *r)
{
	if (r->size_x != COLS || r->size_y != LINES)
	{
		clear();
		vm_nc_init_window(app, r);
		vm_nc_print_arena(app, r->w_left);
		vm_exec_player(app);
	}
}

void	vm_nc_set_hex(unsigned char nbr, char *ret)
{
	unsigned char	c;

	c = nbr / 16;
	c = (c <= 9) ? c + '0' : c + 'a' - 10;
	ret[0] = c;
	c = nbr % 16;
	c = (c <= 9) ? c + '0' : c + 'a' - 10;
	ret[1] = c;
	ret[2] = '\0';
}

int		vm_nc_get_current_live(t_app *app)
{
	int		total_live_current_period;
	int		i;

	total_live_current_period = 0;
	i = 0;
	while (i < (int)app->nbr_player)
	{
		total_live_current_period += app->player[i].live_count;
		i++;
	}
	return (total_live_current_period);
}

void	vm_nc_move_memory(t_app *app)
{
	unsigned char	*access;
	unsigned int	y;
	unsigned int	x;
	unsigned int	i;
	int				ty;

	y = 0;
	access = app->arena.access;
	while (y < 64)
	{
		x = 2;
		i = 0;
		while (x < 194)
		{
			ty = y * 64 + i;
			if (app->arena.access[ty] & 0xf0)
				app->arena.access[ty] -= 0x10;
			app->arena.access[ty] &= 0xf7;
			if (app->arena.live[ty])
				app->arena.live[ty]--;
			x += 3;
			i++;
		}
		y++;
	}
}

void	vm_nc_start_cycle(t_app *app)
{
	vm_exec_player(app);
	while (app->cycle < app->start_cycle)
	{
		app->cycle++;
		vm_nc_move_memory(app);
		vm_exec_player(app);
		if (app->cycle_to_die > CYCLE_TO_DIE)
			break ;
	}
}
