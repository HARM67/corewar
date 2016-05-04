/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_instr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:25:37 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/09 08:29:44 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_error_instr_exist(t_app *app, char *instr, int line)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(app->instr[i].name, instr) == 0)
			return (i);
		i++;
	}
	ERROR("Error : the instruction \"%s\" does not exist, line %d.\n",
			instr, line);
	return (i);
}

void	asm_error_instr(char **str, t_app *app, int line, t_btcode *bt)
{
	int				i;
	char			*tmp;
	char			*tmp_instr;
	int				index_instr;

	i = 0;
	tmp = *str;
	tmp_instr = NULL;
	index_instr = 0;
	while (tmp[i] && tmp[i] != ' ' && tmp[i] != '\t' && tmp[i] != '%')
		i++;
	tmp_instr = ft_strndup(*str, i);
	index_instr = asm_error_instr_exist(app, tmp_instr, line);
	i += asm_dodge_space_tab(&tmp[i]);
	*str += i;
	ft_strdel(&tmp_instr);
	asm_set_cmd_instr(app, bt, index_instr);
}
