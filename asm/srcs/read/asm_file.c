/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 11:37:17 by dlouise           #+#    #+#             */
/*   Updated: 2016/02/21 21:37:42 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_node	*asm_create_line(char *str, int i)
{
	t_node	*n;

	if ((n = (t_node*)ft_memalloc(sizeof(t_node))) == NULL)
		asm_put_error("Error : Node not created");
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
		asm_put_error_str("Error : Can't open the file ", name);
	while ((app->ret = get_next_line(app->fd, &line)) > 0)
	{
		asm_push_line(app, line, i);
		i++;
	}
	if (app->ret == -1)
		asm_put_error_str("Error : An error occured while reading the file ",
				name);
	close(app->fd);
}
