/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:01:19 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/22 23:24:49 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_instruction(t_app *app)
{
	const t_instr instr[16] = {
		{"live", 0x01, {4, 0, 0, 0}, {T_DIR, 0, 0, 0}, 0, *vm_live},
		{"ld", 0x02, {4, 1, 0, 0}, {T_DIR | T_IND, T_REG, 0, 0}, 1, 0},
		{"st", 0x03, {1, 2, 0, 0}, {T_REG, T_IND | T_REG, 0, 0}, 1, 0},
		{"add", 0x04, {1, 1, 1, 0}, {T_REG, T_REG, T_REG, 0}, 1, 0},
		{"sub", 0x05, {1, 1, 1, 0}, {T_REG, T_REG, T_REG, 0}, 1, 0},
		{"and", 0x06, {4, 4, 1, 0}, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG, 0}, 1, 0},
		{"or", 0x07, {4, 4, 1, 0}, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG, 0}, 1, 0},
		{"xor", 0x08, {4, 4, 1, 0}, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG, 0}, 1, 0},
		{"zjmp", 0x09, {2, 0, 0, 0}, {T_DIR, 0, 0, 0}, 0, 0},
		{"ldi", 0x0a, {2, 2, 1, 0}, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, 0}, 1, 0},
		{"sti", 0x0b, {1, 2, 2, 0}, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG, 0}, 1, 0},
		{"fork", 0x0c, {2, 0, 0, 0}, {T_DIR, 0, 0, 0}, 0, 0},
		{"lld", 0x0d, {4, 1, 0, 0}, {T_DIR | T_IND, T_REG, 0, 0}, 1, 0},
		{"lldi", 0x0e, {4, 1, 0, 0}, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, 0}, 1, 0},
		{"lfork", 0x0f, {2, 0, 0, 0}, {T_DIR, 0, 0, 0}, 0, 0},
		{"aff", 0x10, {1, 0, 0, 0}, {T_REG, 0, 0, 0}, 1, 0},
	};
	app->instr = instr;
}
