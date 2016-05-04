/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:25:52 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/09 08:39:04 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_format_param(char *str, unsigned char format)
{
	if (*str)
	{
		if (format & T_REG && str[0] == 'r')
			return (T_REG);
		if (format & T_DIR && str[0] == '%')
			return (T_DIR);
		if (format & T_IND && (asm_param_is_number(&str[0]) || str[0] == ':'))
			return (T_IND);
	}
	return (0);
}

void	asm_error_param(char **str, int line, t_btcode *btcode)
{
	int		i;
	int		next_param;
	t_instr	instr;
	int		f;

	instr = btcode->cmd->instr;
	i = 0;
	next_param = 0;
	while (instr.type_param[i])
	{
		if ((f = asm_format_param(*str, instr.type_param[i])) > 0)
		{
			next_param = asm_syntax_param(str, btcode, i, f);
			*str += next_param;
		}
		else
			ERROR("Error : \"%s\" is an unexpected type of parameter, "
					"line %d.\n", *str, line);
		i++;
	}
	asm_set_encoding_byte(btcode->cmd);
	asm_set_param_hex(btcode->cmd);
}
