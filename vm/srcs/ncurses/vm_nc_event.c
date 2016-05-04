/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_nc_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 00:49:24 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/10 00:49:25 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	vm_nc_hook_cts(t_render *r, int key)
{
	if (key == KEY_DOWN_10)
	{
		r->cts -= 10;
		if (r->cts <= 0)
			r->cts = 1;
	}
	else if (key == KEY_DOWN_1)
	{
		r->cts -= 1;
		if (r->cts <= 0)
			r->cts = 1;
	}
	else if (key == KEY_UP_10)
	{
		r->cts += 10;
		if (r->cts >= 1000)
			r->cts = 1000;
	}
	else if (key == KEY_UP_1)
	{
		r->cts += 1;
		if (r->cts >= 1000)
			r->cts = 1000;
	}
}

static int	vm_nc_event(void)
{
	int		ch;

	ch = getch();
	if (ch != ERR)
	{
		ungetch(ch);
		return (1);
	}
	else
		return (0);
}

void		vm_nc_hook(t_render *r)
{
	int		key;
	int		ch;

	key = 0;
	ch = 0;
	if (vm_nc_event())
	{
		key = wgetch(r->w_left);
		wattron(r->w_right, COLOR_PAIR(30));
		if (key == KEY_SPACE && !r->run)
		{
			nodelay(stdscr, TRUE);
			mvwprintw(r->w_right, 2, 3, "** RUNNING **  ");
			r->run = 1;
		}
		else if (key == KEY_SPACE && r->run)
		{
			nodelay(stdscr, FALSE);
			mvwprintw(r->w_right, 2, 3, "** PAUSED **   ");
			r->run = 0;
		}
		vm_nc_hook_cts(r, key);
		wattron(r->w_right, COLOR_PAIR(30));
		refresh();
	}
}
