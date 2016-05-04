/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:25:44 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/09 08:32:07 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_error_label(char **str, t_app *app, int line)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = *str;
	while (asm_is_label_char(tmp[i]))
		i++;
	if (i == 0)
		ERROR("Error : label without name, line %d.\n", line);
	if (tmp[i] == ':')
	{
		i++;
		asm_push_label(app, ft_strndup(*str, i));
		i += asm_dodge_space_tab(&tmp[i]);
		*str += i;
	}
}
