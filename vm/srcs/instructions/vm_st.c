/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 02:48:26 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/10 08:28:56 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_st(t_app *app, t_instance *inst)
{
	unsigned long	tmp;
	t_arg			arg;
	t_arg			*temp;

	tmp = 0;
	temp = vm_read_encoding_args(app);
	ft_memcpy(&arg, temp, sizeof(t_arg));
	free(temp);
	if (arg.arg[0].type != REGISTRE || arg.arg[1].type == DIRECT ||
		arg.arg[2].size != 0 || arg.arg[3].size != 0 ||
		arg.arg[0].size == 0 || arg.arg[1].size == 0)
		return (vm_calculate_move(&arg, 4, 2));
	ft_memcpy(&inst->arg, &arg, sizeof(t_arg));
	vm_print_current_instr(app, inst);
	if (arg.arg[1].type == REGISTRE)
		*arg.arg[1].r = arg.arg[0].data;
	else if (arg.arg[1].type == INDIRECT)
	{
		tmp = inst->pc + (arg.arg[1].data % IDX_MOD);
		vm_put_mem(app, tmp, arg.arg[0]);
	}
	return (arg.pos);
}
