/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_strsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 11:37:36 by dlouise           #+#    #+#             */
/*   Updated: 2016/02/21 11:48:47 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	asm_count_word(char const *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == '\t' || s[i] == ' ')
		i++;
	if (s[i])
		count++;
	while (s[i])
	{
		if (s[i] == '\t' || s[i] == ' ')
		{
			while (s[i] == '\t' || s[i] == ' ')
				i++;
			if (s[i])
				count++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

static int	asm_strlen_split(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\t' && s[i] != ' ')
		i++;
	return (i);
}

static char	*asm_subtab(char const *s)
{
	size_t	j;
	size_t	size_word;
	char	*str;

	j = 0;
	size_word = asm_strlen_split(s);
	if ((str = (char *)ft_memalloc(size_word * sizeof(char) + 1)) == NULL)
		return (NULL);
	while (j < size_word)
		str[j++] = *s++;
	str[j] = '\0';
	return (str);
}

char		**asm_strsplit(char const *s)
{
	char	**str;
	size_t	nb_word;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	nb_word = asm_count_word(s);
	if ((str = (char **)ft_memalloc(nb_word * sizeof(char *) + 1)) == NULL)
		return (NULL);
	while (i < nb_word)
	{
		while (s[k] && (s[k] == '\t' || s[k] == ' '))
			k++;
		str[i] = asm_subtab(&s[k]);
		k += ft_strlen(str[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
