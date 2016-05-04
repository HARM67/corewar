/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:36:11 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 03:15:59 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n, int base)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

char		*ft_itoa_base(int n, int base)
{
	char	*str;
	int		size;
	char	c;
	char	sign;

	if (base < 2 || base > 16)
		return (NULL);
	sign = (n < 0) ? -1 : 1;
	size = ft_intlen(n, base);
	if ((str = (char *)malloc(size * sizeof(char) + 1)) == NULL)
		return (NULL);
	str[size--] = '\0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		c = '0';
		if (n % base * sign >= 10)
			c += 7;
		str[size--] = n % base * sign + c;
		n /= base;
	}
	return (str);
}
