/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 04:07:51 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/10 08:29:28 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_aff(t_app *app, t_instance *inst)
{
	unsigned char	c;
	t_arg			arg;
	t_arg			*tmp;

	tmp = vm_read_encoding_args(app);
	ft_memcpy(&arg, tmp, sizeof(t_arg));
	free(tmp);
	if (arg.arg[0].type != REGISTRE || arg.arg[1].size != 0 ||
			arg.arg[2].size != 0 || arg.arg[3].size != 0)
		return (vm_calculate_move(&arg, 4, 1));
	c = arg.arg[0].data % 256;
	if (!app->flag_v5 && app->fl.a == 1)
	{
		write(1, "Aff: ", 5);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	if (inst)
		;
	return (arg.pos);
}
