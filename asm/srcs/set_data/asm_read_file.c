/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:14:37 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/09 07:46:07 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_node	*asm_create_line(char *str, int i)
{
	t_node	*n;

	if ((n = (t_node*)ft_memalloc(sizeof(t_node))) == NULL)
		ERROR("Error : malloc node.\n");
	n->next = NULL;
	n->line = str;
	n->n_line = i;
	return (n);
}

static void		asm_push_line(t_app *app, char *str, int i)
{
	t_node	*l;

	l = app->lst_line;
	if (l)
	{
		while (l->next)
			l = l->next;
		l->next = asm_create_line(str, i);
	}
	else
		app->lst_line = asm_create_line(str, i);
}

void			asm_read_file(t_app *app, char *name)
{
	char	*line;
	int		i;

	i = 0;
	if ((app->fd = open(name, O_RDONLY)) == -1)
		ERROR("Error : can't open the file \"%s\".\n", name);
	while ((app->ret = get_next_line(app->fd, &line)) > 0)
	{
		asm_push_line(app, line, i);
		i++;
	}
	if (app->ret == -1)
		ERROR("Error : an error occured while reading the file \"%s\".\n",
				name);
	close(app->fd);
}
