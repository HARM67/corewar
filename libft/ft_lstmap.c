/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:33:17 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 03:14:03 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*tmp;
	t_list	*new;
	t_list	*tmp2;

	list = NULL;
	if (lst)
	{
		while (lst)
		{
			tmp = (*f)(lst);
			new = ft_lstnew(tmp->content, tmp->content_size);
			if (list)
				tmp2->next = new;
			else
				list = new;
			tmp2 = new;
			lst = lst->next;
		}
	}
	return (list);
}
