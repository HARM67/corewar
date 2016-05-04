/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_nc_init_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 02:42:10 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/10 02:42:17 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	vm_nc_init_pair(void)
{
	init_pair(1, COL_GREY, COLOR_BLACK);
	init_pair(2, COL_RED, COLOR_BLACK);
	init_pair(3, COL_GREEN, COLOR_BLACK);
	init_pair(4, COL_BLUE, COLOR_BLACK);
	init_pair(5, COL_YELLOW, COLOR_BLACK);
	init_pair(6, COL_LIGHT_RED, COLOR_BLACK);
	init_pair(7, COL_LIGHT_GREEN, COLOR_BLACK);
	init_pair(8, COL_LIGHT_BLUE, COLOR_BLACK);
	init_pair(9, COL_LIGHT_YELLOW, COLOR_BLACK);
	init_pair(10, COLOR_BLACK, COL_GREY);
	init_pair(11, COLOR_BLACK, COL_RED);
	init_pair(12, COLOR_BLACK, COL_GREEN);
	init_pair(13, COLOR_BLACK, COL_BLUE);
	init_pair(14, COLOR_BLACK, COL_YELLOW);
	init_pair(15, COL_WHITE, COL_RED);
	init_pair(16, COL_WHITE, COL_GREEN);
	init_pair(17, COL_WHITE, COL_BLUE);
	init_pair(18, COL_WHITE, COL_YELLOW);
	init_pair(30, COL_WHITE, COLOR_BLACK);
}

void		vm_nc_init_color(void)
{
	init_color(COL_GREY, 300, 300, 300);
	init_color(COL_RED, 600, 0, 0);
	init_color(COL_LIGHT_RED, 1000, 300, 300);
	init_color(COL_GREEN, 0, 600, 0);
	init_color(COL_LIGHT_GREEN, 300, 1000, 300);
	init_color(COL_BLUE, 0, 0, 600);
	init_color(COL_LIGHT_BLUE, 300, 300, 1000);
	init_color(COL_YELLOW, 600, 600, 0);
	init_color(COL_LIGHT_YELLOW, 1000, 1000, 300);
	init_color(COL_WHITE, 1000, 1000, 1000);
	vm_nc_init_pair();
}
