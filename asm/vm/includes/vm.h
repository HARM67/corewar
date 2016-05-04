/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:17:59 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/23 00:20:30 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libft.h"
# include "fcntl.h"
# include "unistd.h"

# define RED \033[31m
# define GREEN \033[32m
# define BLUE \033[34m
# define YELLOW \033[33m

typedef struct s_app	t_app;

typedef struct			s_instance
{
	unsigned int		pid;
	unsigned int		pc;
	unsigned long		REG[REG_NUMBER];
	struct s_instance	*next;
	struct s_instance	*previous;
}						t_instance;

typedef struct			s_player
{
	t_header			header;
	t_instance			*first_instance;
	t_instance			*last_instance;
	unsigned char		*prog;
	unsigned int		id;
}						t_player;

typedef struct			s_arena
{
	unsigned char		*memory;
	unsigned char		*access;
}						t_arena;

typedef struct			s_instr
{
	char				*name;
	unsigned char		opcode;
	int					nbr_octet[4];
	unsigned char		type_param[4];
	int					is_encoding;
	void				(*action)(t_app *, t_instance *);
}						t_instr;

struct			s_app
{
	t_player			players[MAX_PLAYERS];
	t_arena				arena;
	t_instr				*instr;
	unsigned int		nbr_player;
	unsigned int		ac;
	char				**av;
};

/*
** app.c
*/
void					init_app(t_app *app);
void					run_app(t_app *app);

/*
** read_player.c
*/
t_player				*read_player(t_app *app, char *filename);

/*
** vm_error.c
*/
void					vm_put_error(char *str);
void					vm_put_error_line(char *str, int line);
void					vm_put_error_str(char *str1, char *str2);
void					vm_put_error_char_int_int(char *str, char c, int line,
							int col);
void					vm_put_error_str_int_int(char *str1, char *str2,
							int line, int col);


/*
** print_player.c
*/
void					print_player(t_app *app, t_player *player);

/*
** util.c
*/
void					vm_print_hex(unsigned char nbr);
void					vm_swap_bytes_4(unsigned int *nbr);

/*
** init_arena.c
*/
void					vm_first_instantiation(t_app *app);
void					init_arena(t_app *app);

/*
** vm_print_arena.c
*/
void					vm_print_arena(t_app *app);

/*
** create_instance.c
*/
void					vm_create_instance(t_player *player);

/*
** init_instruction.c
*/
void					init_instruction(t_app *app);

/*
** INSTRUCTIONS ---------------------------------------------------------
*/

/*
** vm_live.c
*/
void					vm_live(t_app *app, t_instance * inst);

/*
** vm_loop.c
*/
void					vm_loop(t_app *app);
#endif
