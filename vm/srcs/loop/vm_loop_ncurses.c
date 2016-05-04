/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop_ncurses.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 06:53:50 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/10 06:53:52 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_nc_print_arena_line(t_app *app, int y, int i, WINDOW *w_left)
{
	int		id_color;
	char	ret[3];
	int		ty;

	ty = y * 64 + i;
	vm_nc_set_hex(app->arena.memory[ty], ret);
	if (app->arena.live[ty])
		id_color = 14;
	else if (app->arena.access[ty] & 0x8)
		id_color = 10;
	else if (app->arena.access[ty] & 0xf0)
		id_color = 5;
	else
		id_color = 1;
	wattron(w_left, COLOR_PAIR((app->arena.access[ty] & 0x7) + id_color));
	mvwprintw(w_left, y + 2, (i * 3) + 2, ret);
	wattroff(w_left, COLOR_PAIR((app->arena.access[ty] & 0x7) + id_color));
	if (app->arena.access[ty] & 0xf0)
		app->arena.access[ty] -= 0x10;
	app->arena.access[ty] &= 0xf7;
	if (app->arena.live[ty])
		app->arena.live[ty]--;
}

void	vm_nc_print_arena(t_app *app, WINDOW *w_left)
{
	unsigned char	*access;
	unsigned int	y;
	unsigned int	x;
	unsigned int	i;

	y = 0;
	access = app->arena.access;
	while (y < 64)
	{
		x = 2;
		i = 0;
		while (x < 194)
		{
			vm_nc_print_arena_line(app, y, i, w_left);
			x += 3;
			i++;
		}
		y++;
	}
	wrefresh(w_left);
}

void	vm_nc_run(t_app *app, t_render *r)
{
	while (app->cycle_to_die <= CYCLE_TO_DIE && app->nb_processes > 0)
	{
		if (r->run || app->cycle == app->start_cycle)
		{
			app->cycle++;
			usleep(1000000 / r->cts);
			vm_nc_print_arena(app, r->w_left);
			vm_exec_player(app);
		}
		vm_nc_check_size_term(app, r);
		vm_nc_menu(app, r);
		vm_nc_hook(r);
		wrefresh(r->w_right);
		wrefresh(r->w_left);
	}
}

void	vm_nc_print_winner(t_app *app, t_render *r)
{
	int			id_win;
	int			ch;

	id_win = app->last_player_live;
	wattron(r->w_right, COLOR_PAIR(30));
	mvwprintw(r->w_right, 52, 3, "The winner is :");
	wattron(r->w_right, COLOR_PAIR(id_win + 6));
	app->player[app->last_player_live].header.prog_name[34] = '\0';
	mvwprintw(r->w_right, 52, 19, "%s",
		app->player[app->last_player_live].header.prog_name);
	wattroff(r->w_right, COLOR_PAIR(id_win + 6));
	wattron(r->w_right, COLOR_PAIR(30));
	mvwprintw(r->w_right, 54, 3, "Press any key to finish");
	wattroff(r->w_right, COLOR_PAIR(30));
	wrefresh(r->w_right);
	ch = -1;
	while (ch == -1)
		ch = getch();
}

void	vm_loop_ncurses(t_app *app)
{
	t_render	r;

	ft_bzero(&r, sizeof(t_render));
	r.run = IS_RUN;
	r.cts = CYCLE_TO_SECOND;
	if (!app->fl.d)
		app->start_cycle = 1;
	r.cycle_start = app->start_cycle;
	vm_nc_init(app, &r);
	vm_nc_start_cycle(app);
	vm_nc_run(app, &r);
	vm_nc_print_winner(app, &r);
	endwin();
}
