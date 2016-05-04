/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:26:14 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/10 02:49:00 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_print_hex(unsigned char nbr)
{
	unsigned char	c;

	c = nbr / 16;
	c = (c <= 9) ? c + '0' : c + 'a' - 10;
	write(1, &c, 1);
	c = nbr % 16;
	c = (c <= 9) ? c + '0' : c + 'a' - 10;
	write(1, &c, 1);
}

void	vm_cpy_data(unsigned char *dest, unsigned char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

void	vm_swap_bytes_4(unsigned int *nbr)
{
	unsigned int	tmp;
	unsigned char	*pnbr;
	unsigned char	*ptmp;

	tmp = *nbr;
	pnbr = (unsigned char*)nbr;
	ptmp = (unsigned char*)&tmp;
	pnbr[0] = ptmp[3];
	pnbr[1] = ptmp[2];
	pnbr[2] = ptmp[1];
	pnbr[3] = ptmp[0];
}

int		vm_calculate_move(t_arg *arg, unsigned int max, unsigned int size)
{
	int				rt;
	unsigned int	i;

	i = 0;
	rt = 2;
	while (i < size)
	{
		if (((arg->code << (i * 2)) & 0xc0) == 0x40)
			rt += 1;
		else if (((arg->code << (i * 2)) & 0xc0) == 0x80)
			rt += max;
		else if (((arg->code << (i * 2)) & 0xc0) == 0xc0)
			rt += 2;
		i++;
	}
	return (rt);
}

void	vm_print_current_instr(t_app *app, t_instance *inst)
{
	unsigned int i;

	i = 0;
	if (!app->flag_v5)
		return ;
	ft_printf("P %4d | %s", inst->pid + 1,
		app->instr[app->current_instr - 1].name);
	while (i < 4)
	{
		if (app->instr[app->current_instr - 1].type_param[i] == 1)
			ft_printf(" r%d", inst->arg.arg[i].reg_nbr);
		else if (app->instr[app->current_instr - 1].type_param[i] != 0)
		{
			if (app->current_instance->arg.arg[i].type == REGISTRE &&
				app->current_instr == 3)
				ft_printf(" %d", inst->arg.arg[i].reg_nbr);
			else
				ft_printf(" %d", inst->arg.arg[i].data);
		}
		i++;
	}
	ft_printf("\n");
}
