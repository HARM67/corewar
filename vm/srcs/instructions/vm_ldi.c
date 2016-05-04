/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 03:56:52 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/10 08:29:15 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_ldi(t_app *app, t_instance *inst)
{
	t_arg	arg;
	t_arg	*tmp;

	tmp = vm_read_encoding_args(app);
	ft_memcpy(&arg, tmp, sizeof(t_arg));
	free(tmp);
	if (arg.arg[0].size == 0 || arg.arg[1].type == INDIRECT ||
		arg.arg[2].type != REGISTRE || arg.arg[3].size != 0 ||
		arg.arg[1].size == 0 || arg.arg[2].size == 0)
		return (vm_calculate_move(&arg, 2, 3));
	if (arg.arg[0].type == INDIRECT)
		arg.arg[0].data = vm_get_mem(app, inst->pc + (arg.arg[0].data % IDX_MOD)
				, 4).data;
	*arg.arg[2].r = vm_get_mem(app, inst->pc +
		((arg.arg[0].data + arg.arg[1].data) % IDX_MOD), 4).data;
	ft_memcpy(&inst->arg, &arg, sizeof(t_arg));
	vm_print_current_instr(app, inst);
	if (app->flag_v5)
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
			arg.arg[0].data, arg.arg[1].data, arg.arg[0].data + arg.arg[1].data,
			inst->pc + ((arg.arg[0].data + arg.arg[1].data) % IDX_MOD));
	return (arg.pos);
}
