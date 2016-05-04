/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 04:22:22 by atrupin           #+#    #+#             */
/*   Updated: 2016/03/13 07:15:06 by atrupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libft.h"
# include "ft_printf.h"
# include "fcntl.h"
# include "unistd.h"
# include <ncurses.h>

# define RED \033[31m
# define GREEN \033[32m
# define BLUE \033[34m
# define YELLOW \033[33m
# define DIRECT 0
# define REGISTRE 1
# define INDIRECT 2

# define T_LIVE {T_DIR, 0, 0, 0}
# define T_LD {T_DIR | T_IND, T_REG, 0, 0}
# define T_ST {T_REG, T_IND | T_REG, 0, 0}
# define T_ADD {T_REG, T_REG, T_REG, 0}
# define T_SUB {T_REG, T_REG, T_REG, 0}
# define T_AND {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG, 0}
# define T_OR {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG, 0}
# define T_XOR {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG, 0}
# define T_ZJMP {T_DIR, 0, 0, 0}
# define T_LDI {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, 0}
# define T_STI {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG, 0}
# define T_FORK {T_DIR, 0, 0, 0}
# define T_LLD {T_DIR | T_IND, T_REG, 0, 0}
# define T_LLDI {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, 0}
# define T_LFORK {T_DIR, 0, 0, 0}
# define T_AFF {T_REG, 0, 0, 0}

/*
** DEFINE NCURSES
*/
# define KEY_SPACE 32
# define KEY_DOWN_10 113
# define KEY_DOWN_1 119
# define KEY_UP_10 114
# define KEY_UP_1 101

# define COL_GREY 100
# define COL_RED 101
# define COL_LIGHT_RED 102
# define COL_GREEN 103
# define COL_LIGHT_GREEN 104
# define COL_BLUE 105
# define COL_LIGHT_BLUE 106
# define COL_YELLOW 107
# define COL_LIGHT_YELLOW 108
# define COL_WHITE 109

# define IS_RUN 0
# define CYCLE_TO_SECOND 50

typedef struct s_app	t_app;

typedef	struct			s_flags
{
	int					v;
	int					n;
	int					d;
	int					g;
	int					a;
	int					h;
}						t_flags;

typedef struct			s_type
{
	int					*r;
	int					data;
	unsigned int		size;
	unsigned char		type;
	unsigned char		reg_nbr;
}						t_type;

typedef struct			s_arg
{
	t_type				arg[4];
	unsigned char		*addr;
	unsigned char		*addr_access;
	unsigned char		code;
	unsigned char		current_arg;
	unsigned char		pos;
}						t_arg;

typedef struct			s_instance
{
	t_arg				arg;
	unsigned int		pid;
	unsigned int		pc;
	int					reg[REG_NUMBER];
	unsigned char		carry;
	struct s_instance	*next;
	struct s_instance	*previous;
	unsigned int		cycle;
	unsigned int		last_live;
	unsigned char		is_dead;
	unsigned char		creator;
	unsigned char		tmp_instr;
}						t_instance;

typedef struct			s_player
{
	t_header			header;
	unsigned int		live_count;
	unsigned int		id;
	unsigned char		*prog;
	unsigned char		is_dead;
	unsigned int		last_live;
}						t_player;

typedef struct			s_arena
{
	unsigned char		memory[MEM_SIZE];
	unsigned char		access[MEM_SIZE];
	unsigned char		live[MEM_SIZE];
}						t_arena;

typedef struct			s_instr
{
	char				*name;
	unsigned char		opcode;
	int					nbr_octet[4];
	unsigned char		type_param[4];
	int					is_encoding;
	int					(*action)(t_app *, t_instance *);
	unsigned int		cost;
}						t_instr;

typedef struct			s_render
{
	WINDOW				*w_left;
	WINDOW				*w_right;
	int					size_x;
	int					size_y;
	int					run;
	int					cts;
	int					total_live_current_period;
	unsigned int		cycle_start;
	unsigned int		current_cycle_to_die;
}						t_render;

typedef	struct			s_player_nb
{
	int					p_bool;
	int					p_nb;
}						t_player_nb;

struct					s_app
{
	t_player			player[MAX_PLAYERS];
	t_instance			*first_instance;
	t_instance			*last_instance;
	t_instance			*current_instance;
	t_arena				arena;
	t_instr				instr[16];
	t_flags				fl;
	t_player_nb			player_nb;
	unsigned int		check_count;
	unsigned int		last_check;
	unsigned int		total_live;
	unsigned int		cycle_to_die;
	unsigned int		cycle;
	unsigned int		start_cycle;
	unsigned int		current_instr;
	unsigned int		nbr_player;
	unsigned int		current_player;
	unsigned int		ac;
	unsigned int		focus;
	unsigned int		nb_processes;
	unsigned char		last_player_live;
	unsigned char		flag_v5;
	char				**av;
	int					d_bool;
};

/*
** app.c
*/
void					vm_init_app(t_app *app);

/*
** read_player.c
*/
t_player				*vm_read_player(t_app *app, char *filename);
void					vm_check_player_nb(t_app *app, char *av);

/*
** vm_error.c
*/
void					vm_print_error(char *str);
void					vm_print_error_line(char *str, int line);
void					vm_print_error_str(char *str1, char *str2);
void					vm_print_error_char_int_int(char *str, char c, int line,
							int col);
void					vm_print_error_str_int_int(char *str1, char *str2,
							int line, int col);

/*
** print_player.c
*/
void					vm_print_instance(t_app *app, t_instance *inst);
void					vm_print_player(t_app *app, t_player *player);

/*
** util.c
*/
void					vm_print_hex(unsigned char nbr);
void					vm_swap_bytes_4(unsigned int *nbr);
void					vm_cpy_data(unsigned char *dest, unsigned char *src,
							unsigned int n);
int						vm_calculate_move(t_arg *arg, unsigned int max,
							unsigned int size);
void					vm_print_current_instr(t_app *app, t_instance *inst);

/*
** init_arena.c
*/
void					vm_first_instantiation(t_app *app);
void					vm_init_arena(t_app *app);

/*
** vm_print_arena.c
*/
void					vm_print_arena2(t_app *app);

/*
** create_instance.c
*/
void					vm_create_instance(t_app *app);
void					vm_print_instances(t_app *app);
void					vm_remove_instance(t_app *app, t_instance *inst);

/*
** init_instruction.c
*/
void					vm_init_instruction(t_app *app);

/*
** vm_loop.c
*/
void					vm_loop(t_app *app);

/*
** vm_exec.c
*/
void					vm_exec_instance(t_app *app);
void					vm_exec_player(t_app *app);

/*
** vm_read_arg.c
*/
t_arg					*vm_read_encoding_args(t_app *app);
void					vm_print_arg(t_arg *arg);

/*
** vm_print_arg.c
*/
void					vm_print_args(t_app *app, t_arg *arg);

/*
** vm_put_mem.c
*/
void					vm_put_mem(t_app *app, int pos, t_type t);

/*
** vm_get_mem.c
*/
t_type					vm_get_mem(t_app *app, int pos,
							unsigned int size);
void					vm_put_winner(t_app *app);
void					vm_check_magic(t_app *app);
void					vm_check_flags(t_app *app, int *token, int *i);

void					vm_loop_verbose(t_app *app);
void					vm_loop(t_app *app);
void					vm_print_help(void);
void					vm_loop_dump(t_app *app);

/*
** vm_nc_event.c
*/
void					vm_nc_hook(t_render *r);

/*
** vm_nc_init.c
*/
void					vm_nc_init(t_app *app, t_render *r);
void					vm_nc_init_color(void);
void					vm_nc_init_window(t_app *app, t_render *r);

/*
** vm_nc_menu.c
*/
void					vm_nc_menu(t_app *app, t_render *r);

/*
** vm_nc_util.c
*/
void					vm_nc_check_size_term(t_app *app, t_render *r);
void					vm_nc_set_hex(unsigned char nbr, char *ret);
int						vm_nc_get_current_live(t_app *app);

/*
** vm_loop_ncurses.c
*/
void					vm_loop_ncurses(t_app *app);
void					vm_nc_run(t_app *app, t_render *r);
void					vm_nc_print_arena_line(t_app *app, int y, int i,
							WINDOW *w_left);
void					vm_nc_print_arena(t_app *app, WINDOW *w_left);
void					vm_nc_start_cycle(t_app *app);

/*
** INSTRUCTIONS ---------------------------------------------------------
*/

int						vm_live(t_app *app, t_instance *inst);
int						vm_zjmp(t_app *app, t_instance *inst);
int						vm_sti(t_app *app, t_instance *inst);
int						vm_and(t_app *app, t_instance *inst);
int						vm_or(t_app *app, t_instance *inst);
int						vm_xor(t_app *app, t_instance *inst);
int						vm_ld(t_app *app, t_instance *inst);
int						vm_st(t_app *app, t_instance *inst);
int						vm_add(t_app *app, t_instance *inst);
int						vm_sub(t_app *app, t_instance *inst);
int						vm_ldi(t_app *app, t_instance *inst);
int						vm_aff(t_app *app, t_instance *inst);
int						vm_lld(t_app *app, t_instance *inst);
int						vm_lldi(t_app *app, t_instance *inst);
int						vm_fork(t_app *app, t_instance *inst);
int						vm_lfork(t_app *app, t_instance *inst);

#endif
