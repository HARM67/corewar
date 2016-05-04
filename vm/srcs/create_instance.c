/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_instance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 22:20:09 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/23 02:39:35 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_instance	*vm_new_instance(void)
{
	t_instance	*rt;

	rt = (t_instance*)ft_memalloc(sizeof(t_instance));
	if (!rt)
		vm_put_error("Error : can't create instance");
	return (rt);
}

void				vm_create_instance(t_player *player)
{
	t_instance *rt;

	rt = vm_new_instance();
	if (player->first_instance == 0)
	{
		player->first_instance = rt;
		player->last_instance = player->first_instance;
		player->current_instance = player->first_instance;
	}
	else
	{
		player->last_instance->next = rt;
		player->last_instance->next->previous = player->last_instance;
		player->last_instance = player->last_instance->next;
	}
}
