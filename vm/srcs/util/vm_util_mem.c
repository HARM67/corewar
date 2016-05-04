/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_util_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 03:24:46 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/08 10:39:46 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_type	vm_get_mem(t_app *app, int pos, unsigned int size)
{
	t_type			rt;
	unsigned char	*p;
	unsigned int	i;
	unsigned char	*addr;

	pos = (pos >= 0) ? pos : pos + MEM_SIZE;
	addr = app->arena.memory;
	ft_bzero(&rt, sizeof(t_type));
	rt.size = size;
	i = 0;
	p = (unsigned char*)&rt.data;
	while (i < size)
	{
		p[i] = addr[(pos + (size - i - 1)) % MEM_SIZE];
		i++;
	}
	if (p[size - 1] & 0x80)
	{
		while (i < 4)
		{
			p[i] = 0xff;
			i++;
		}
	}
	return (rt);
}

void	vm_put_mem(t_app *app, int pos, t_type t)
{
	unsigned char	*p;
	unsigned int	i;
	unsigned char	*addr;
	unsigned char	*addr_acces;

	pos = (pos >= 0) ? pos : pos + MEM_SIZE;
	addr = app->arena.memory;
	addr_acces = app->arena.access;
	i = 0;
	p = (unsigned char*)&t.data;
	while (i < t.size)
	{
		addr[((i + pos) % MEM_SIZE)] = p[t.size - i - 1];
		addr_acces[((i + pos) % MEM_SIZE)] = app->current_instance->creator + 1;
		addr_acces[((i + pos) % MEM_SIZE)] |= 0xf0;
		i++;
	}
}
