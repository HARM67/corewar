/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_init_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 11:36:36 by dlouise           #+#    #+#             */
/*   Updated: 2016/02/21 11:37:55 by dlouise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*static t_size_p	asm_get_sp(int a, int b, int c, int d)
{
	t_size_p	p;

	p.a = a;
	p.b = b;
	p.c = c;
	p.d = d;
	return (p);
}

static t_instr	asm_set_instr(char *name, unsigned char opcode,
	t_size_p sp, int b)
{
	t_instr		instr;

	instr.name = name;
	instr.opcode = opcode;
	instr.nbr_octet[0] = sp.a;
	instr.nbr_octet[1] = sp.b;
	instr.nbr_octet[2] = sp.c;
	instr.nbr_octet[3] = sp.d;
	instr.is_encoding = b;
	return (instr);
}*/

/*int			asm_get_type(int a, int b, int c, int d)
{
	int		type_param[4];

	type_param[0] = a;
	type_param[1] = b;
	type_param[2] = c;
	type_param[3] = d;
	return (1);
}*/

void			asm_init_type_param(t_app *app)
{
	const t_instr instr[16] = {
		{"live", 0x01, {4, 0, 0, 0}, {T_DIR, 0, 0, 0}, 0},
		{"ld", 0x02, {4, 1, 0, 0}, {T_DIR | T_IND, T_REG, 0, 0}, 1},
		{"st", 0x03, {1, 2, 0, 0}, {T_REG, T_IND | T_REG, 0, 0}, 1},
		{"add", 0x04, {1, 1, 1, 0}, {T_REG, T_REG, T_REG, 0}, 1},
		{"sub", 0x05, {1, 1, 1, 0}, {T_REG, T_REG, T_REG, 0}, 1},
		{"and", 0x06, {4, 4, 1, 0}, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG, 0}, 1},
		{"or", 0x07, {4, 4, 1, 0}, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG, 0}, 1},
		{"xor", 0x08, {4, 4, 1, 0}, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG, 0}, 1},
		{"zjmp", 0x09, {2, 0, 0, 0}, {T_DIR, 0, 0, 0}, 0},
		{"ldi", 0x0a, {2, 2, 1, 0}, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, 0}, 1},
		{"sti", 0x0b, {1, 2, 2, 0}, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG, 0}, 1},
		{"fork", 0x0c, {2, 0, 0, 0}, {T_DIR, 0, 0, 0}, 0},
		{"lld", 0x0d, {4, 1, 0, 0}, {T_DIR | T_IND, T_REG, 0, 0}, 1},
		{"lldi", 0x0e, {4, 1, 0, 0}, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, 0}, 1},
		{"lfork", 0x0f, {2, 0, 0, 0}, {T_DIR, 0, 0, 0}, 0},
		{"aff", 0x10, {1, 0, 0, 0}, {T_REG, 0, 0, 0}, 1},
	};
	app->instr = instr;
}

/*void			asm_init_instr(t_app *app)
{
	ft_bzero(app->instr, sizeof(app->instr));
	app->instr[0] = asm_set_instr("live", 0x01, asm_get_sp(4, 0, 0, 0), 0);
	app->instr[1] = asm_set_instr("ld", 0x02, asm_get_sp(4, 1, 0, 0), 1);
	app->instr[2] = asm_set_instr("st", 0x03, asm_get_sp(1, 2, 0, 0), 1);
	app->instr[3] = asm_set_instr("add", 0x04, asm_get_sp(1, 1, 1, 0), 1);
	app->instr[4] = asm_set_instr("sub", 0x05, asm_get_sp(1, 1, 1, 0), 1);
	app->instr[5] = asm_set_instr("and", 0x06, asm_get_sp(4, 4, 1, 0), 1);
	app->instr[6] = asm_set_instr("or", 0x07, asm_get_sp(4, 4, 1, 0), 1);
	app->instr[7] = asm_set_instr("xor", 0x08, asm_get_sp(4, 4, 1, 0), 1);
	app->instr[8] = asm_set_instr("zjmp", 0x09, asm_get_sp(2, 0, 0, 0), 0);
	app->instr[9] = asm_set_instr("ldi", 0x0a, asm_get_sp(2, 2, 1, 0), 1);
	app->instr[10] = asm_set_instr("sti", 0x0b, asm_get_sp(1, 2, 2, 0), 1);
	app->instr[11] = asm_set_instr("fork", 0x0c, asm_get_sp(2, 0, 0, 0), 0);
	app->instr[12] = asm_set_instr("lld", 0x0d, asm_get_sp(4, 1, 0, 0), 1);
	app->instr[13] = asm_set_instr("lldi", 0x0e, asm_get_sp(4, 1, 0, 0), 1);
	app->instr[14] = asm_set_instr("lfork", 0x0f, asm_get_sp(2, 0, 0, 0), 0);
	app->instr[15] = asm_set_instr("aff", 0x10, asm_get_sp(1, 0, 0, 0), 1);
	asm_init_type_param(app);
}*/
