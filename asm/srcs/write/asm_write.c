/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 07:33:14 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/21 21:40:27 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		asm_strcmp_label(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	while (us1[i] == us2[i] && us1[i] != 0 && us2[i] != ':')
		i++;
	if (!us1[i] && us2[i] == ':')
		i--;
	return (us1[i] - us2[i]);
}

static void		asm_write_param(t_app *app, t_param *param)
{
	int		i;
	char	*p;

	i = param->size - 1;
	p = (char *)&param->hex;
	while (i >= 0)
	{
		ft_putchar_fd(p[i], app->fd);
		i--;
	}
}

static void		asm_set_label_dist(t_app *app, t_param *param, int pos)
{
	t_label		*l;

	l = app->label;
	if (param->str[0] == '%' && param->str[1] == ':')
	{
		while (l)
		{
			if (asm_strcmp_label(&param->str[2], l->name) == 0)
			{
				param->hex = l->pos - pos;
				return ;
			}
			l = l->next;
		}
		asm_put_error_str("Error : label not found ", &param->str[2]);
	}
}

void			asm_open_out_file(t_app *app, char **av)
{
	app->path_out_file = ft_strnew(ft_strlen(av[1]) + 3);
	ft_strcpy(app->path_out_file, av[1]);
	ft_strcpy(&app->path_out_file[ft_strlen(app->path_out_file) - 1], "cor");
	app->fd = open(app->path_out_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (app->fd < 0)
		asm_put_error_str("Error : Can't open the file ", app->path_out_file);
}

void			asm_write_data(t_app *app)
{
	t_btcode	*btcode;
	int			pos;
	int			i;

	app->header.prog_size = asm_reverse_uint(app->byte_count);
	write(app->fd, &app->header, sizeof(t_header));
	pos = 0;
	btcode = app->btcode;
	while (btcode)
	{
		i = 0;
		ft_putchar_fd(btcode->cmd->instr.opcode, app->fd);
		if (btcode->cmd->instr.is_encoding)
			ft_putchar_fd(btcode->cmd->encoding, app->fd);
		while (i < 4 && btcode->cmd->param[i].size)
		{
			asm_set_label_dist(app, btcode->cmd->param + i, pos);
			asm_write_param(app, btcode->cmd->param + i);
			i++;
		}
		pos += btcode->cmd->cmd_size;
		btcode = btcode->next;
	}
	asm_put_success("Writing output program to ", app->path_out_file);
	ft_strdel(&app->path_out_file);
}
