/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_push_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:14:11 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/09 07:42:22 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_btcode	*asm_create_bt(void)
{
	t_btcode *bt;

	if ((bt = (t_btcode *)ft_memalloc(sizeof(t_btcode))) == NULL)
		ERROR("Error : malloc btcode.\n");
	bt->size_hex = 0;
	bt->cmd = NULL;
	bt->n_line = 0;
	bt->next = NULL;
	return (bt);
}

void		asm_push_bt(t_app *app, t_btcode *btcode)
{
	t_btcode *bt;

	bt = app->btcode;
	if (bt)
	{
		while (bt->next)
			bt = bt->next;
		bt->next = btcode;
	}
	else
		app->btcode = btcode;
}

t_label		*asm_create_label(char *str)
{
	t_label	*label;

	if ((label = (t_label*)ft_memalloc(sizeof(t_label))) == NULL)
		ERROR("Error : malloc new label.\n");
	label->name = str;
	label->pos = -1;
	label->next = NULL;
	return (label);
}

void		asm_push_label(t_app *app, char *str)
{
	t_label	*l;

	l = app->label;
	if (l)
	{
		while (l->next)
			l = l->next;
		l->next = asm_create_label(str);
	}
	else
		app->label = asm_create_label(str);
}
