/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 11:37:41 by dlouise           #+#    #+#             */
/*   Updated: 2016/03/12 04:59:35 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			asm_check_extension(t_app *app, char **av)
{
	int len;

	len = ft_strlen(av[1]);
	if (len < 2 || av[1][len - 1] != 's' || av[1][len - 2] != '.')
		ERROR("Error : bad file type.\n");
	app = (void*)app;
}

unsigned int	asm_reverse_uint(unsigned int n)
{
	unsigned char	*t;

	t = (unsigned char*)&n;
	return (0
		| (unsigned int)t[0] << 24
		| (unsigned int)t[1] << 16
		| (unsigned int)t[2] << 8
		| (unsigned int)t[3]);
}

void			asm_delete_comment_after_header(t_app *app)
{
	t_node			*line;
	unsigned int	num_line;
	unsigned int	num_col;

	num_line = 1;
	line = app->lst_line;
	while (line)
	{
		num_col = 0;
		while (line->line[num_col])
		{
			if (num_line >= app->cursor->line
					&& (line->line[num_col] == '#'
						|| line->line[num_col] == ';'))
				line->line[num_col] = '\0';
			num_col++;
		}
		num_line++;
		line = line->next;
	}
}

int				ft_atoi2(const char *nptr)
{
	size_t	i;
	int		res;
	char	neg;

	neg = 0;
	res = 0;
	i = 0;
	while (' ' == nptr[i] || '\t' == nptr[i] || '\f' == nptr[i]
		|| '\v' == nptr[i] || '\r' == nptr[i] || '\n' == nptr[i])
		i++;
	if ('-' == nptr[i])
	{
		neg = 1;
		i++;
	}
	else if ('+' == nptr[i])
		i++;
	while ('0' <= nptr[i] && '9' >= nptr[i])
	{
		if (res > (res * 10) + nptr[i] - '0')
			return (-1);
		res = (res * 10) + nptr[i++] - '0';
	}
	res = (neg ? -res : res);
	return (res);
}
