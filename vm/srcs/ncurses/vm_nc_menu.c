/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_nc_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 02:37:50 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/13 07:17:48 by atrupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	vm_nc_menu_last_period(t_app *app, t_render *r)
{
	int		i;
	int		j;
	int		last;
	float	percent;

	last = 0;
	i = 0;
	percent = 0;
	while (i < (int)app->nbr_player)
	{
		percent = app->player[i].live_count * 50;
		if (r->total_live_current_period)
			percent /= r->total_live_current_period;
		j = 0;
		while (j < percent && j + last < 50)
		{
			wattron(r->w_right, COLOR_PAIR(i + 11));
			mvwprintw(r->w_right, 34, 3 + j + last, "%c", ' ');
			wattroff(r->w_right, COLOR_PAIR(i + 11));
			j++;
		}
		last += j;
		i++;
	}
	r->current_cycle_to_die = app->cycle_to_die;
}

static void	vm_nc_menu_current_period(t_app *app, t_render *r)
{
	int		i;
	int		j;
	int		last;
	float	percent;

	i = 0;
	percent = 0;
	last = 0;
	r->total_live_current_period = vm_nc_get_current_live(app);
	while (i < (int)app->nbr_player)
	{
		percent = app->player[i].live_count * 50;
		if (r->total_live_current_period)
			percent /= r->total_live_current_period;
		j = 0;
		while (j < percent && j + last < 50)
		{
			wattron(r->w_right, COLOR_PAIR(i + 11));
			mvwprintw(r->w_right, 29, 3 + j + last, "%c", ' ');
			wattroff(r->w_right, COLOR_PAIR(i + 11));
			j++;
		}
		last += j;
		i++;
	}
}

static void	vm_nc_menu_player(t_app *app, t_render *r)
{
	int		i;
	int		l;

	i = 0;
	l = 11;
	while (i < (int)app->nbr_player)
	{
		mvwprintw(r->w_right, l + 1, 37, "%d     ",
			((int)app->player[i].last_live > 0) ?
				(int)app->player[i].last_live : 0);
		mvwprintw(r->w_right, l + 2, 37, "%d     ",
			(int)app->player[i].live_count);
		i++;
		l += 4;
	}
}

void		vm_nc_menu(t_app *app, t_render *r)
{
	wattron(r->w_right, COLOR_PAIR(30));
	mvwprintw(r->w_right, 4, 26, "%d         ", r->cts);
	mvwprintw(r->w_right, 7, 11, "%d         ", app->cycle - 1);
	mvwprintw(r->w_right, 9, 15, "%d         ", app->nb_processes);
	mvwprintw(r->w_right, 40, 18, "%d      ", app->cycle_to_die);
	mvwprintw(r->w_right, 38, 31, "%d      ",
		app->cycle_to_die - (app->cycle - app->last_check));
	vm_nc_menu_player(app, r);
	vm_nc_menu_current_period(app, r);
	if (app->cycle - app->last_check + 1 == app->cycle_to_die)
		vm_nc_menu_last_period(app, r);
	wattroff(r->w_right, COLOR_PAIR(30));
}
