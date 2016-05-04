/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:52:34 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/10 13:52:51 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int len)
{
	char	*rep;

	if ((rep = (char*)ft_memalloc(len + 1)) == NULL)
		return (NULL);
	ft_strncpy(rep, str, len);
	rep[len] = '\0';
	return (rep);
}
