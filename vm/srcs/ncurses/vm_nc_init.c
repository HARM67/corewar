/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_nc_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 01:42:56 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/13 01:12:25 by atrupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	vm_nc_init_menu_define(t_render *r)
{
	mvwprintw(r->w_right, 38, 3, "Cycle before cycle to die : ");
	mvwprintw(r->w_right, 40, 3, "CYCLE_TO_DIE : ");
	mvwprintw(r->w_right, 42, 3, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvwprintw(r->w_right, 44, 3, "NBR_LIVE : %d", NBR_LIVE);
	mvwprintw(r->w_right, 46, 3, "MAX_CHECKS : %d", MAX_CHECKS);
}

static void	vm_nc_init_menu_player(t_app *app, t_render *r)
{
	int		i;
	int		l;
	int		j;

	i = 0;
	l = 11;
	while (i < (int)app->nbr_player)
	{
		mvwprintw(r->w_right, l, 3, "Player %d : ", (int)app->player[i].id);
		wattron(r->w_right, COLOR_PAIR(i + 6));
		app->player[i].header.prog_name[38] = '\0';
		j = 0;
		while (app->player[i].header.prog_name[j] != '\n' && j < 38)
			j++;
		app->player[i].header.prog_name[j] = '\0';
		mvwprintw(r->w_right, l, 15, "%s",
			(char *)app->player[i].header.prog_name);
		wattron(r->w_right, COLOR_PAIR(30));
		mvwprintw(r->w_right, l + 1, 5,
			"Last live :                     ");
		mvwprintw(r->w_right, l + 2, 5,
			"Lives in current period :       ");
		i++;
		l += 4;
	}
}

static void	vm_init_const_text(t_app *app, t_render *r)
{
	int		i;

	wattron(r->w_right, COLOR_PAIR(30));
	if (!r->run)
		mvwprintw(r->w_right, 2, 3, "** PAUSED **	");
	else if (r->run)
		mvwprintw(r->w_right, 2, 3, "** RUNNING **	");
	mvwprintw(r->w_right, 32, 3, "Live breakdown for last period : ");
	i = 0;
	while (i < 50)
	{
		wattron(r->w_right, COLOR_PAIR(10));
		mvwprintw(r->w_right, 34, 3 + i, "%c", ' ');
		mvwprintw(r->w_right, 29, 3 + i, "%c", ' ');
		wattroff(r->w_right, COLOR_PAIR(10));
		i++;
	}
	wattron(r->w_right, COLOR_PAIR(30));
	vm_nc_init_menu_define(r);
	mvwprintw(r->w_right, 27, 3, "Live breakdown for current period :");
	mvwprintw(r->w_right, 4, 3, "Cycles/second limit : ");
	mvwprintw(r->w_right, 7, 3, "Cycle : ");
	mvwprintw(r->w_right, 9, 3, "Processes : ");
	vm_nc_init_menu_player(app, r);
	wattroff(r->w_right, COLOR_PAIR(30));
}

void		vm_nc_init_window(t_app *app, t_render *r)
{
	r->w_left = subwin(stdscr, 68, 196, 0, 0);
	r->w_right = subwin(stdscr, 68, 55, 0, 198);
	r->size_x = COLS;
	r->size_y = LINES;
	box(r->w_left, ACS_VLINE, ACS_HLINE);
	box(r->w_right, ACS_VLINE, ACS_HLINE);
	vm_init_const_text(app, r);
}

void		vm_nc_init(t_app *app, t_render *r)
{
	initscr();
	start_color();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	vm_nc_init_color();
	vm_nc_init_window(app, r);
}
