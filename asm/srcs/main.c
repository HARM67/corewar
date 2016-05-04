/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 11:32:59 by dlouise           #+#    #+#             */
/*   Updated: 2016/03/10 05:54:50 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			main(int ac, char **av)
{
	t_app app;

	if (ac != 2)
		ERROR("Error : wrong number of arguments.\n");
	asm_init_app(&app);
	asm_check_extension(&app, av);
	asm_read_file(&app, av[1]);
	asm_parse(&app);
	asm_open_out_file(&app, av);
	if (app.byte_count == 0)
		ERROR("Error : the program has no instruction.\n");
	asm_write_data(&app);
	return (0);
}
