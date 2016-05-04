/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_read_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:53:22 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/10 07:27:53 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_type	vm_read_registre(t_app *app, unsigned char *addr)
{
	unsigned char	data;
	t_type			rt;

	ft_bzero(&rt, sizeof(t_type));
	data = vm_get_mem(app, addr - app->arena.memory, 1).data;
	rt.reg_nbr = data;
	if (data > REG_NUMBER || data <= 0)
		return (rt);
	rt.data = app->current_instance->reg[data - 1];
	rt.r = &app->current_instance->reg[data - 1];
	rt.type = REGISTRE;
	rt.size = 4;
	return (rt);
}

static void		vm_set_encoding_arg_dir_ind(t_app *app, t_arg *rt, int token)
{
	if (token == DIRECT)
	{
		rt->arg[rt->current_arg].size =
			app->instr[app->current_instr - 1].nbr_octet[rt->current_arg];
		if (rt->arg[rt->current_arg].size == 0)
			return ;
		rt->arg[rt->current_arg].data =
			vm_get_mem(app, rt->addr + rt->pos - app->arena.memory,
				rt->arg[rt->current_arg].size).data;
		rt->pos += rt->arg[rt->current_arg].size;
		rt->arg[rt->current_arg].type = DIRECT;
	}
	else if (token == INDIRECT)
	{
		rt->arg[rt->current_arg].size = 2;
		rt->arg[rt->current_arg].data =
			vm_get_mem(app, rt->addr + rt->pos - app->arena.memory,
				rt->arg[rt->current_arg].size).data;
		rt->pos += rt->arg[rt->current_arg].size;
		rt->arg[rt->current_arg].type = INDIRECT;
	}
}

static void		vm_read_encoding_arg(t_app *app, t_arg *rt)
{
	if (!app->instr[app->current_instr - 1].nbr_octet[rt->current_arg])
		return ;
	if (((rt->code << rt->current_arg * 2) & 0xc0) == 0x40)
	{
		rt->arg[rt->current_arg] = vm_read_registre(app, rt->addr + rt->pos);
		rt->pos++;
	}
	else if (((rt->code << rt->current_arg * 2) & 0xc0) == 0x80)
		vm_set_encoding_arg_dir_ind(app, rt, DIRECT);
	else if (((rt->code << rt->current_arg * 2) & 0xc0) == 0xc0)
		vm_set_encoding_arg_dir_ind(app, rt, INDIRECT);
}

void			vm_print_arg(t_arg *arg)
{
	unsigned int	i;

	i = 0;
	while (i < 4)
	{
		if (arg->arg[i].type == REGISTRE)
			ft_printf("r%d", arg->arg[i].reg_nbr);
		i++;
	}
}

t_arg			*vm_read_encoding_args(t_app *app)
{
	t_arg			*rt;

	rt = malloc(sizeof(t_arg));
	ft_bzero(rt, sizeof(t_arg));
	rt->current_arg = 0;
	rt->pos = 2;
	rt->addr = &app->arena.memory[app->current_instance->pc];
	rt->code = app->arena.memory[(app->current_instance->pc + 1) % MEM_SIZE];
	while (rt->current_arg < 4)
	{
		vm_read_encoding_arg(app, rt);
		rt->current_arg++;
	}
	ft_memcpy(&app->current_instance->arg, rt, sizeof(t_arg));
	return (rt);
}
