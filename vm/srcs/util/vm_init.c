/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 04:27:59 by atrupin           #+#    #+#             */
/*   Updated: 2016/03/13 07:02:43 by atrupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_init_instruction(t_app *app)
{
	const t_instr instr[16] = {
		{"live", 0x01, {4, 0, 0, 0}, T_LIVE, 0, *vm_live, 10},
		{"ld", 0x02, {4, 1, 0, 0}, T_LD, 1, *vm_ld, 5},
		{"st", 0x03, {1, 2, 0, 0}, T_ST, 1, *vm_st, 5},
		{"add", 0x04, {1, 1, 1, 0}, T_ADD, 1, *vm_add, 10},
		{"sub", 0x05, {1, 1, 1, 0}, T_SUB, 1, *vm_sub, 10},
		{"and", 0x06, {4, 4, 1, 0}, T_AND, 1, *vm_and, 6},
		{"or", 0x07, {4, 4, 1, 0}, T_OR, 1, *vm_or, 6},
		{"xor", 0x08, {4, 4, 1, 0}, T_XOR, 1, *vm_xor, 6},
		{"zjmp", 0x09, {2, 0, 0, 0}, T_ZJMP, 0, *vm_zjmp, 20},
		{"ldi", 0x0a, {2, 2, 1, 0}, T_LDI, 1, *vm_ldi, 25},
		{"sti", 0x0b, {1, 2, 2, 0}, T_STI, 1, *vm_sti, 25},
		{"fork", 0x0c, {2, 0, 0, 0}, T_FORK, 0, *vm_fork, 800},
		{"lld", 0x0d, {4, 1, 0, 0}, T_LLD, 1, *vm_lld, 10},
		{"lldi", 0x0e, {2, 2, 1, 0}, T_LLDI, 1, *vm_lldi, 50},
		{"lfork", 0x0f, {2, 0, 0, 0}, T_LFORK, 0, *vm_lfork, 1000},
		{"aff", 0x10, {1, 0, 0, 0}, T_AFF, 1, *vm_aff, 2}
	};

	ft_memcpy(app->instr, (t_instr*)instr, sizeof(t_instr) * 16);
}

void		vm_set_player_nb(t_app *app, int j, int k)
{
	int i;

	i = 1;
	if (app->player_nb.p_bool == 0)
		app->player[j].id = k;
	else
	{
		while (i <= j)
		{
			if ((int)app->player[i].id == app->player_nb.p_nb)
				vm_print_error("Error : Two players can't have the same id");
			i++;
		}
		app->player[j].id = app->player_nb.p_nb;
		app->player_nb.p_bool = 0;
		app->player_nb.p_nb = 0;
	}
}

void		vm_init_players(t_app *app)
{
	int	i;
	int	token;

	i = 1;
	token = 0;
	while (i < (int)app->ac)
	{
		vm_check_flags(app, &token, &i);
		i++;
	}
	if (token != 0)
		vm_print_error("Error : Bad argument(s)");
}

void		vm_init_arena(t_app *app)
{
	ft_bzero(&app->arena, sizeof(t_arena));
}

void		vm_init_app(t_app *app)
{
	vm_init_arena(app);
	app->cycle_to_die = CYCLE_TO_DIE;
	app->player_nb.p_nb = -1;
	vm_init_players(app);
	if ((app->fl.v == 1 && app->fl.g == 1) ||
		(app->fl.v == 1 && app->fl.d == 1))
		vm_print_error("Error : Can't perorm multiple flags");
	if (app->fl.v == 1)
		app->flag_v5 = 1;
	vm_check_magic(app);
	ft_printf("Introducing contestants...\n");
	vm_init_instruction(app);
	vm_first_instantiation(app);
}
