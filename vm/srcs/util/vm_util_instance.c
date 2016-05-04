/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_instance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 22:20:09 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/05 22:40:17 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_instance	*vm_new_instance(t_app *app)
{
	t_instance	*rt;
	static int	pid = 0;

	rt = (t_instance*)ft_memalloc(sizeof(t_instance));
	if (!rt)
		vm_print_error("Error : can't create instance");
	rt->pid = pid;
	pid++;
	app->nb_processes++;
	return (rt);
}

void				vm_create_instance(t_app *app)
{
	t_instance	*rt;

	rt = vm_new_instance(app);
	if (app->first_instance == 0)
	{
		app->first_instance = rt;
		app->last_instance = rt;
		app->current_instance = rt;
	}
	else
	{
		app->last_instance->next = rt;
		rt->previous = app->last_instance;
		app->last_instance = rt;
	}
}

void				vm_remove_instance_first_last(t_app *app,
	t_instance *inst, int token)
{
	if (token)
	{
		app->first_instance = inst->next;
		if (inst->next == 0)
		{
			app->last_instance = 0;
			app->current_instance = 0;
		}
		else
			inst->next->previous = 0;
	}
	else
	{
		app->last_instance = inst->previous;
		if (inst->previous == 0)
		{
			app->first_instance = 0;
			app->current_instance = 0;
		}
		else
			inst->previous->next = 0;
	}
}

void				vm_remove_instance(t_app *app, t_instance *inst)
{
	if (inst == 0)
		return ;
	if (inst == app->first_instance)
		vm_remove_instance_first_last(app, inst, 1);
	else if (inst == app->last_instance)
		vm_remove_instance_first_last(app, inst, 0);
	else
	{
		if (inst->previous)
			inst->previous->next = inst->next;
		if (inst->next)
			inst->next->previous = inst->previous;
	}
	ft_bzero(inst, sizeof(t_instance));
	free(inst);
	app->nb_processes--;
	inst = 0;
}
