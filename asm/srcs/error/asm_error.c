/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:25:29 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/09 09:49:32 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_check_line(t_app *app, char *str, int line)
{
	t_btcode	*bt;

	bt = asm_create_bt();
	bt->n_line = line;
	str += asm_dodge_space_tab(str);
	if (!*str)
	{
		free(bt);
		return ;
	}
	asm_error_label(&str, app, line);
	asm_update_label_pos(app);
	if (!*str)
	{
		free(bt);
		return ;
	}
	asm_error_instr(&str, app, line, bt);
	asm_error_param(&str, line, bt);
	if (*str)
		ERROR("Error : too many parameters, line %d.\n", line);
	asm_push_bt(app, bt);
	app->byte_count += bt->cmd->cmd_size;
}

t_instr	asm_get_instr(t_app *app, int i_instr)
{
	int		i;

	i = 0;
	while (i < 16 && i != i_instr)
		i++;
	return (app->instr[i]);
}
