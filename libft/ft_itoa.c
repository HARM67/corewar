/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:24:55 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/24 17:25:38 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long long n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(long long n)
{
	char	*str;
	size_t	i;
	int		sign;

	i = ft_intlen(n);
	sign = (n < 0) ? -1 : 1;
	if (n == 0)
		return ("0");
	if ((str = (char *)malloc(i * sizeof(char) + 1)) == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		str[i - 1] = (n % 10 * sign) + '0';
		n /= 10;
		i--;
	}
	return (str);
}
