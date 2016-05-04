/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_cursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 11:37:23 by dlouise           #+#    #+#             */
/*   Updated: 2016/03/09 07:35:35 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_cursor	*asm_create_cursor(void)
{
	t_cursor	*cursor;

	cursor = (t_cursor*)ft_memalloc(sizeof(t_cursor));
	if (cursor == NULL)
		ERROR("Error : malloc cursor.\n");
	cursor->line = 1;
	cursor->col = 0;
	return (cursor);
}

char		*asm_get_line(t_app *app, unsigned int n)
{
	unsigned int	num_line;
	t_node			*node_line;

	node_line = app->lst_line;
	num_line = 1;
	while (node_line && num_line < n)
	{
		node_line = node_line->next;
		num_line++;
	}
	if (node_line == NULL)
		return (NULL);
	return (node_line->line);
}

char		asm_get_char(char *line, unsigned int n)
{
	unsigned int		num_char;

	if (line == NULL)
		return ('\0');
	num_char = 0;
	while (line[num_char] && num_char < n)
	{
		num_char++;
	}
	if (line[num_char] == '\0' && num_char == n)
		return ('\n');
	return (line[num_char]);
}

char		asm_read_char(t_app *app)
{
	char	*line;
	char	c;

	line = asm_get_line(app, app->cursor->line);
	c = asm_get_char(line, app->cursor->col);
	if (line)
	{
		if (c == '\n')
		{
			app->cursor->line++;
			app->cursor->col = 0;
		}
		else
			app->cursor->col++;
	}
	return (c);
}
