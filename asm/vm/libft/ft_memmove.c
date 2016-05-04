/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 02:23:24 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/24 03:09:24 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)dst;
	if ((s = (char *)malloc(ft_strlen(src) * sizeof(char))) == NULL)
		return (NULL);
	s = ft_strcpy(s, (char *)src);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	free(s);
	return (dst);
}
