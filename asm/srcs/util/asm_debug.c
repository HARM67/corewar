/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 11:37:26 by dlouise           #+#    #+#             */
/*   Updated: 2016/03/09 07:31:45 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_debug_instr_init(t_app app)
{
	int		i;
	int		j;

	i = 0;
	while (i < 16)
	{
		ft_printf("[name : %5s] [opcode : %#4x] [is_encoding : %d] [",
			app.instr[i].name, app.instr[i].opcode, app.instr[i].is_encoding);
		j = 0;
		while (j < 4)
		{
			ft_printf("%2d ", app.instr[i].nbr_octet[j]);
			j++;
		}
		ft_printf("]\n");
		i++;
	}
}

void	asm_debug_label(t_app app)
{
	t_label		*l;

	l = app.label;
	ft_printf("___________________________________________\nLabel\n");
	while (l)
	{
		ft_printf("\033[32mname :\t\033[0m %s\n", l->name);
		ft_printf("\033[33mpos :\t\033[0m %d\n\n", l->pos);
		l = l->next;
	}
}

void	asm_debug_print_btcode(t_btcode *bt)
{
	int		i;

	i = 0;
	ft_printf("\t\033[32mCmd : \n");
	ft_printf("\t\t\033[33mInstr :\t\t\033[0m %s\n", bt->cmd->instr.name);
	ft_printf("\t\t\033[33mOpcode :\t\033[0m %#x\n", bt->cmd->instr.opcode);
	ft_printf("\t\t\033[33mNbr octet :\t\033[0m ");
	while (i < 4)
	{
		ft_printf("%d ", bt->cmd->instr.nbr_octet[i]);
		i++;
	}
	ft_printf("\n\t\t\033[33mIs encoding :\t\033[0m %d\n",
			bt->cmd->instr.is_encoding);
	ft_printf("\t\t\033[33mFull cmd size :\t\033[0m %d\n", bt->cmd->cmd_size);
	ft_printf("\n\t\t\033[36mEncodage :\t\t\033[0m %#x\n", bt->cmd->encoding);
	ft_printf("\n\t\t\033[36mParam :\t\t\033[0m \n");
}

void	asm_debug_btcode(t_app app)
{
	t_btcode	*bt;
	int			i;

	bt = app.btcode;
	ft_printf("DEBUG\n\n");
	while (bt)
	{
		asm_debug_print_btcode(bt);
		i = 0;
		while (i < 4)
		{
			ft_printf("\t\t\t%8s ", bt->cmd->param[i].str);
			ft_printf("\t%2d ", bt->cmd->param[i].size);
			ft_printf("\t%#x\n ", bt->cmd->param[i].hex);
			i++;
		}
		ft_printf("\n_________________________________"
				"__________________________________\n");
		bt = bt->next;
	}
}
