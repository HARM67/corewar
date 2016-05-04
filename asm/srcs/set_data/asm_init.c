/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:13:41 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/07 23:51:21 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

const t_instr g_instr[16] = {
	{"live", 0x01, {4, 0, 0, 0}, {T_DIR, 0, 0, 0}, 0},
	{"ld", 0x02, {4, 1, 0, 0}, {T_DIR | T_IND, T_REG, 0, 0}, 1},
	{"st", 0x03, {1, 2, 0, 0}, {T_REG, T_IND | T_REG, 0, 0}, 1},
	{"add", 0x04, {1, 1, 1, 0}, {T_REG, T_REG, T_REG, 0}, 1},
	{"sub", 0x05, {1, 1, 1, 0}, {T_REG, T_REG, T_REG, 0}, 1},
	{"and", 0x06, {4, 4, 1, 0},
		{T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG, 0}, 1},
	{"or", 0x07, {4, 4, 1, 0}, {T_REG | T_IND | T_DIR, T_REG | T_IND |
			T_DIR, T_REG, 0}, 1},
	{"xor", 0x08, {4, 4, 1, 0},
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG, 0}, 1},
	{"zjmp", 0x09, {2, 0, 0, 0}, {T_DIR, 0, 0, 0}, 0},
	{"ldi", 0x0a, {2, 2, 1, 0},
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, 0}, 1},
	{"sti", 0x0b, {1, 2, 2, 0},
		{T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG, 0}, 1},
	{"fork", 0x0c, {2, 0, 0, 0}, {T_DIR, 0, 0, 0}, 0},
	{"lld", 0x0d, {4, 1, 0, 0}, {T_DIR | T_IND, T_REG, 0, 0}, 1},
	{"lldi", 0x0e, {2, 2, 1, 0},
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, 0}, 1},
	{"lfork", 0x0f, {2, 0, 0, 0}, {T_DIR, 0, 0, 0}, 0},
	{"aff", 0x10, {1, 0, 0, 0}, {T_REG, 0, 0, 0}, 1}};

void	asm_init_app(t_app *app)
{
	app->byte_count = 0;
	app->fd = -1;
	app->ret = -1;
	app->lst_line = NULL;
	app->label = NULL;
	app->btcode = NULL;
	ft_bzero(&app->header, sizeof(app->header));
	app->cursor = asm_create_cursor();
	asm_init_type_param(app);
	ft_bzero(app->directives_readed, 2 * sizeof(int));
}

void	asm_init_type_param(t_app *app)
{
	ft_memcpy(app->instr, g_instr, 16 * sizeof(t_instr));
}
