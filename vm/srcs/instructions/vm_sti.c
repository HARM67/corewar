/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 03:50:29 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/10 08:28:51 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_sti(t_app *app, t_instance *inst)
{
	unsigned long	tmp;
	t_arg			arg;
	t_arg			*temp;

	temp = vm_read_encoding_args(app);
	ft_memcpy(&arg, temp, sizeof(t_arg));
	free(temp);
	if (arg.arg[0].type != REGISTRE || arg.arg[2].type == INDIRECT ||
		arg.arg[0].size == 0 || arg.arg[1].size == 0 || arg.arg[2].size == 0)
		return (vm_calculate_move(&arg, 2, 3));
	if (arg.arg[1].type == INDIRECT)
		arg.arg[1].data = vm_get_mem(app, inst->pc +
			(arg.arg[1].data % IDX_MOD), 4).data;
	ft_memcpy(&inst->arg, &arg, sizeof(t_arg));
	vm_print_current_instr(app, inst);
	tmp = arg.addr - app->arena.memory +
	((arg.arg[1].data + arg.arg[2].data) % IDX_MOD);
	if (app->flag_v5)
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
			arg.arg[1].data, arg.arg[2].data,
			arg.arg[1].data + arg.arg[2].data, (int)tmp);
	vm_put_mem(app, tmp, arg.arg[0]);
	return (arg.pos);
}
