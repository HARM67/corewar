/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 04:27:06 by atrupin           #+#    #+#             */
/*   Updated: 2016/03/13 05:01:04 by atrupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#ifdef BONUS
# define ACTION_BONUS() vm_loop_ncurses(&app)
#else
# define ACTION_BONUS() ft_printf("Bonus non compile. Faites \"make bonus\"\n")
#endif

int		main(int ac, char **av)
{
	t_app	app;

	if (ac == 1)
		vm_print_help();
	ft_bzero(&app, sizeof(t_app));
	app.ac = ac;
	app.av = av;
	vm_init_app(&app);
	if (app.flag_v5)
		vm_loop_verbose(&app);
	else if (app.fl.g)
		ACTION_BONUS();
	else if (app.fl.d)
		vm_loop_dump(&app);
	else
		vm_loop_verbose(&app);
	return (0);
}
