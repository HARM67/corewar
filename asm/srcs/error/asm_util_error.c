/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_util_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:26:11 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/12 04:55:21 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				asm_dodge_space_tab(char *str)
{
	int		i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

void			asm_update_label_pos(t_app *app)
{
	t_label	*l;

	l = app->label;
	while (l)
	{
		if (l->pos == -1)
			l->pos = app->byte_count;
		l = l->next;
	}
}

int				asm_param_is_number(char *str)
{
	if (*str)
	{
		if (str[1] && str[0] == '-' && ft_isdigit(str[1]))
			return (1);
		if (ft_isdigit(str[0]))
			return (1);
	}
	return (0);
}

unsigned int	asm_get_param_hex(t_param p)
{
	unsigned int	hex;

	hex = 0x0;
	if (p.str[0] == '%')
	{
		if (p.str[1] == ':')
			hex = 0x0;
		else
			hex = ft_atoi(&p.str[1]);
	}
	else if (p.str[0] == 'r')
	{
		hex = ft_atoi(&p.str[1]);
		if (hex > REG_NUMBER || hex < 1)
			ERROR("Error : the r%d register does not exist.\n", hex);
	}
	else if (asm_param_is_number(p.str))
		hex = ft_atoi2(p.str);
	return (hex);
}

int				asm_is_label_char(char c)
{
	int			i;
	const char	lb[] = LABEL_CHARS;

	i = 0;
	while (lb[i])
	{
		if (c == lb[i])
			return (1);
		i++;
	}
	return (0);
}
