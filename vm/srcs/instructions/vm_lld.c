/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 06:39:58 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/10 08:29:06 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_lld(t_app *app, t_instance *inst)
{
	t_arg	arg;
	int		tmp;
	t_arg	*temp;

	temp = vm_read_encoding_args(app);
	ft_memcpy(&arg, temp, sizeof(t_arg));
	free(temp);
	if (arg.arg[0].type == REGISTRE || arg.arg[1].type != REGISTRE ||
		arg.arg[2].size != 0 || arg.arg[3].size != 0 ||
		arg.arg[0].size == 0 || arg.arg[1].size == 0)
		return (vm_calculate_move(&arg, 4, 2));
	inst->carry = 0;
	if (arg.arg[0].type == DIRECT)
		tmp = arg.arg[0].data;
	else
		tmp = vm_get_mem(app, inst->pc + arg.arg[0].data, 4).data;
	*arg.arg[1].r = tmp;
	ft_memcpy(&inst->arg, &arg, sizeof(t_arg));
	inst->arg.arg[0].data = tmp;
	inst->arg.arg[0].size = 4;
	vm_print_current_instr(app, inst);
	if ((*arg.arg[1].r) == 0)
		inst->carry = 1;
	return (arg.pos);
}
