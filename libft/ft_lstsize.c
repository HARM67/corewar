/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:32:34 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 00:32:42 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *l)
{
	int		count;

	count = 0;
	while (l)
	{
		count++;
		l = l->next;
	}
	return (count);
}
