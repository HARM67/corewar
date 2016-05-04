/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_param_syntax.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:26:00 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/09 23:38:14 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_syntax_param_reg(char *str, int line)
{
	int		i;

	i = 0;
	if (str[i] && str[i] == 'r')
	{
		i++;
		while (str[i] && (ft_isdigit(str[i])))
			i++;
		return (i);
	}
	else
		ERROR("Error : \"%s\" is not a register, line %d.\n", str, line);
	return (0);
}

void	asm_syntax_param_dir_number(char *str, int *i, int line)
{
	if (str[*i] == '-')
	{
		(*i)++;
		if (!str[*i] || !ft_isdigit(str[*i]))
			ERROR("Error : \"%s\" is not a valid number, line %d.\n",
				str, line);
	}
	else if (!ft_isdigit(str[*i]))
		ERROR("Error : \"%s\" is not a valid number, line %d.\n",
			str, line);
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	if (str[*i] != ',' && str[*i] != ' ' && str[*i] != '\t'
			&& str[*i] != '\n' && str[*i] != '\0')
		ERROR("Error: character '%c' unexpected, line %d.\n", str[*i], line);
}

int		asm_syntax_param_dir(char *str, int line)
{
	int		i;

	i = 0;
	if (!str[i] || str[i] != '%')
		ERROR("Error : \"%s\" is not a direct parameter, line %d.\n",
			str, line);
	i++;
	if (str[i] && str[i] == ':')
	{
		i++;
		if (!asm_is_label_char(str[i]))
			ERROR("Error : \"%s\" is not a valid label, line %d.\n",
			str, line);
		while (asm_is_label_char(str[i]))
			i++;
		if (str[i] != ',' && str[i] != ' ' && str[i] != '\t'
				&& str[i] != '\n' && str[i] != '\0')
			ERROR("Error : character '%c' unexpected, line %d.\n",
				str[i], line);
	}
	else if (str[i] && asm_param_is_number(&str[i]))
		asm_syntax_param_dir_number(str, &i, line);
	else
		ERROR("Error : invalid direct parameter.\n");
	return (i);
}

int		asm_syntax_param(char **str, t_btcode *btcode, int j, int f)
{
	char	*tmp;
	int		i;
	int		token;

	tmp = *str;
	token = 0;
	i = 0;
	if (f == T_REG)
		i = asm_syntax_param_reg(tmp, btcode->n_line);
	else if (f == T_DIR)
		i = asm_syntax_param_dir(tmp, btcode->n_line);
	else if (f == T_IND)
		i = asm_syntax_param_ind(tmp, btcode->n_line);
	asm_set_cmd_param(btcode, ft_strndup(*str, i), j);
	i += asm_dodge_space_tab(&tmp[i]);
	if (tmp[i] != ',' && tmp[i] != '\0')
		ERROR("Error : a comma is expected in the place of '%c', line %d.\n",
			tmp[i], btcode->n_line);
	if (tmp[i] == ',' && ++token)
		i++;
	i += asm_dodge_space_tab(&tmp[i]);
	if (token && tmp[i] == '\0')
		ERROR("Error : parameter missing, line %d.\n", btcode->n_line);
	return (i);
}
