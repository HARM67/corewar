/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:26:14 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/23 04:39:30 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_print_hex(unsigned char nbr)
{
	unsigned char	c;

	c = nbr / 16;
	c = (c <= 9) ? c + '0' : c + 'a' - 10;
	write(1, &c, 1);
	c = nbr % 16;
	c = (c <= 9) ? c + '0' : c + 'a' - 10;
	write(1, &c, 1);
}

void	vm_cpy_data(unsigned char *dest, unsigned char *src, unsigned int	n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

void	vm_swap_bytes_4(unsigned int *nbr)
{
	unsigned int	tmp;
	unsigned char	*pnbr;
	unsigned char	*ptmp;

	tmp = *nbr;
	pnbr = (unsigned char*)nbr;
	ptmp = (unsigned char*)&tmp;
	pnbr[0] = ptmp[3];
	pnbr[1] = ptmp[2];
	pnbr[2] = ptmp[1];
	pnbr[3] = ptmp[0];
}
