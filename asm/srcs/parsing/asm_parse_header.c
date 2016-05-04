/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 11:36:55 by dlouise           #+#    #+#             */
/*   Updated: 2016/02/21 23:36:49 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	asm_read_directive_value(t_app *app, char *dst_value, int length,
				char *name)
{
	int		i;
	char	c;

	while (1)
	{
		c = asm_read_char(app);
		if (c == ' ' || c == '\t')
			continue ;
		if (c != '"')
			asm_put_error_str_int_int(
				"Error : directive value must begin with a quotation mark ",
				0, app->cursor->line, app->cursor->col);
		break ;
	}
	c = asm_read_char(app);
	i = 0;
	while (c != '"' && i < length)
	{
		dst_value[i] = c;
		i++;
		c = asm_read_char(app);
	}
	if (c != '"')
		asm_put_error_str_int_int("Error : directive value is too long",
			name, app->cursor->line, app->cursor->col);
}

static void	asm_read_directive_name(t_app *app, char directive[9])
{
	int		i;

	i = 0;
	directive[i] = asm_read_char(app);
	while (ft_isalpha(directive[i]) && i < 7)
	{
		i++;
		directive[i] = asm_read_char(app);
	}
	if ((ft_strncmp(directive, NAME_CMD_STRING + 1, 4) != 0
			&& (ft_strncmp(directive, COMMENT_CMD_STRING + 1, 7) != 0)))
		asm_put_error_str_int_int("Error : directive not expected ", directive,
			app->cursor->line, app->cursor->col - ft_strlen(directive) + 1);
	directive[i] = '\0';
	app->cursor->col--;
}

static void	asm_check_after_directive(t_app *app)
{
	char	c;

	c = asm_read_char(app);
	while (c == ' ' || c == '\t')
		c = asm_read_char(app);
	if (c == ';' || c == '#')
	{
		c = asm_read_char(app);
		while (c != '\n')
			c = asm_read_char(app);
	}
	if (c != '\n')
		asm_put_error_char_int_int("Error : unexpected character after the "
				"directive", c, app->cursor->line, app->cursor->col);
}

int			asm_read_directive(t_app *app)
{
	char		directive_name[9];
	static	int nb_directive = 0;

	bzero(directive_name, 9);
	if (nb_directive++ == 2)
		asm_put_error_line("Error : too directives ", app->cursor->line);
	asm_read_directive_name(app, directive_name);
	if (ft_strcmp(directive_name, NAME_CMD_STRING + 1) == 0)
		asm_read_directive_value(app, app->header.prog_name, PROG_NAME_LENGTH,
				directive_name);
	if (ft_strcmp(directive_name, COMMENT_CMD_STRING + 1) == 0)
		asm_read_directive_value(app, app->header.comment, COMMENT_LENGTH,
				directive_name);
	asm_check_after_directive(app);
	if (*app->header.prog_name && *app->header.comment)
		return (1);
	return (0);
}
