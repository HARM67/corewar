/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_param_syntax_ind.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 23:00:47 by dlouise           #+#    #+#             */
/*   Updated: 2016/03/10 05:48:55 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	asm_syntax_param_ind_label(char *str, int *i, int line)
{
	(*i)++;
	if (!str[*i] || !asm_is_label_char(str[*i]))
		ERROR("Error : unexpected charactere '%c' in label, line %d.\n",
			str[*i], line);
	while (str[*i] && (asm_is_label_char(str[*i])))
		(*i)++;
}

static void	asm_syntax_param_ind_number(char *str, int *i, int line)
{
	(*i)++;
	if (!str[*i] || !ft_isdigit(str[*i]))
		ERROR("Error : unexpected charactere '%c' in number, line %d.\n",
			str[*i], line);
	while (str[*i] && (ft_isdigit(str[*i])))
		(*i)++;
}

int			asm_syntax_param_ind(char *str, int line)
{
	int		i;

	i = 0;
	if (!*str)
		ERROR("Error : indirect parameter expected, line %d.\n", line);
	if (str[0] == '-')
	{
		asm_syntax_param_ind_number(str, &i, line);
		return (i);
	}
	else if (ft_isdigit(str[i]))
	{
		while (str[i] && (ft_isdigit(str[i])))
			i++;
		return (i);
	}
	else if (str[i] == ':')
	{
		asm_syntax_param_ind_label(str, &i, line);
		return (i);
	}
	else
		ERROR("Error : unexpected charactere '%c' in indirect parameter, "
			"line %d.\n", str[i], line);
	return (i);
}
