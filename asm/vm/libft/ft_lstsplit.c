/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 03:36:11 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 04:34:38 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	if (s[i])
		count++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i])
				count++;
		}
		i++;
	}
	return (count);
}

static int	ft_strlen_split(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_subtab(char const *s, char c)
{
	size_t	j;
	size_t	size_word;
	char	*str;

	j = 0;
	size_word = ft_strlen_split(s, c);
	if ((str = (char *)malloc(size_word * sizeof(char) + 1)) == NULL)
		return (NULL);
	while (j < size_word)
		str[j++] = *s++;
	str[j] = '\0';
	return (str);
}

t_list		*ft_lstsplit(char const *s, char c)
{
	size_t	nb_word;
	size_t	i;
	size_t	k;
	t_list	*list;

	i = 0;
	k = 0;
	nb_word = ft_count_word(s, c);
	list = NULL;
	while (i < nb_word)
	{
		while (s[k] && s[k] == c)
			k++;
		if (list)
			ft_lstpush_back(&list, &s[k], ft_strlen_split(&s[k], c));
		else
			list = ft_lstnew(ft_subtab(&s[k], c), ft_strlen_split(&s[k], c));
		k += list->content_size;
		i++;
	}
	return (list);
}
