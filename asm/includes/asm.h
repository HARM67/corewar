/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:46:43 by atrupin           #+#    #+#             */
/*   Updated: 2016/03/12 22:03:04 by atrupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

# define ASM_H

# include <stdlib.h>
# include <libft.h>
# include <ft_printf.h>
# include <fcntl.h>
# include "op.h"

typedef struct		s_cursor
{
	unsigned int	line;
	unsigned int	col;
}					t_cursor;

typedef struct		s_node
{
	char			*line;
	struct s_node	*next;
	int				n_line;
}					t_node;

typedef struct		s_label
{
	char			*name;
	int				pos;
	struct s_label	*next;
}					t_label;

typedef struct		s_size_p
{
	int				a;
	int				b;
	int				c;
	int				d;
}					t_size_p;

typedef struct		s_instr
{
	char			name[6];
	unsigned char	opcode;
	int				nbr_octet[4];
	unsigned char	type_param[4];
	int				is_encoding;
}					t_instr;

typedef struct		s_param
{
	char			*str;
	int				size;
	unsigned int	hex;
}					t_param;

typedef struct		s_cmd
{
	struct s_instr	instr;
	unsigned char	encoding;
	struct s_param	param[4];
	int				cmd_size;
}					t_cmd;

typedef struct		s_btcode
{
	int				size_hex;
	struct s_cmd	*cmd;
	unsigned int	n_line;
	struct s_btcode	*next;
}					t_btcode;

typedef	struct		s_app
{
	int				fd;
	int				ret;
	t_node			*lst_line;
	t_label			*label;
	t_header		header;
	t_cursor		*cursor;
	t_btcode		*btcode;
	t_instr			instr[16];
	unsigned int	byte_count;
	char			*path_of;
	int				directives_readed[2];
}					t_app;

# define ERROR(fmt,...)(ft_printf("\033[31m"fmt"\033[0m",##__VA_ARGS__),exit(1))

/*
**	Path : srcs/util/asm_util.c
**	Role : Various utils functions
*/
void				asm_check_extension(t_app *app, char **av);
unsigned int		asm_reverse_uint(unsigned int n);
void				asm_delete_comment_after_header(t_app *app);

/*
**	Path : srcs/util/asm_debug.c
**	Role : Debug printf WARNING
*/
void				asm_debug_instr_init(t_app app);
void				asm_debug_label(t_app app);
void				asm_debug_btcode(t_app app);

/*
**	Path : srcs/util/asm_cursor.c
**	Role : ?????
*/
t_cursor			*asm_create_cursor(void);
char				*asm_get_line(t_app *app, unsigned int n);
char				asm_get_char(char *line, unsigned int n);
char				asm_read_char(t_app *app);

/*
**	Path : srcs/set_data/asm_set_btcode.c
**	Role : Set and push btcode structure
*/
void				asm_set_real_param_size(t_cmd *cmd);
void				asm_set_encoding_byte(t_cmd *cmd);
void				asm_set_cmd_param(t_btcode *bt, char *str, int i);
void				asm_set_cmd_instr(t_app *app, t_btcode *bt,
						int i_instr);

/*
**	Path : srcs/set_data/asm_read_file.c
**	Role : Read with gnl and push in app->lst_line
*/
void				asm_read_file(t_app *app, char *name);

/*
**	Path : srcs/set_data/asm_push_data.c
**	Role : Linked list for label and btcode
*/
t_btcode			*asm_create_bt(void);
void				asm_push_bt(t_app *app, t_btcode *btcode);
t_label				*asm_create_label(char *str);
void				asm_push_label(t_app *app, char *str);

/*
**	Path : srcs/set_data/asm_init.c
**	Role : Init app and instructions
*/
void				asm_init_app(t_app *app);
void				asm_init_type_param(t_app *app);

/*
**	Path : srcs/print/asm_write.c
**	Role : Write final output in bytecode
*/
void				asm_open_out_file(t_app *app, char **av);
void				asm_write_data(t_app *app);

/*
**	Path : srcs/parsing/asm_parsing_header.c
**	Role : Parsing header
*/
int					asm_read_directive(t_app *app);

/*
**	Path : srcs/parsing/asm_parsing.c
**	Role : Main parsing file
*/
void				asm_parse_header(t_app *app);
void				asm_save_cmd(t_app *app);
void				asm_parse(t_app *app);

/*
**	Path : A VOIR
**	Role : A VOIR
*/
int					asm_syntax_param(char **str, t_btcode *btcode,
						int j, int f);
int					asm_format_param(char *str, unsigned char format);
unsigned int		asm_get_param_hex(t_param p);
void				asm_set_param_hex(t_cmd *cmd);
void				asm_error_param(char **str, int line,
						t_btcode *btcode);
int					asm_syntax_param_ind(char *str, int line);
int					asm_is_label_char(char c);
void				asm_error_label(char **str, t_app *app, int line);

int					asm_error_instr_exist(t_app *app, char *instr, int line);
void				asm_error_instr(char **str, t_app *app, int line,
						t_btcode *bt);

void				asm_update_label_pos(t_app *app);
void				asm_check_line(t_app *app, char *str, int line);
t_instr				asm_get_instr(t_app *app, int i_instr);

int					asm_dodge_space_tab(char *str);
void				asm_update_label_pos(t_app *app);
int					asm_param_is_number(char *str);

int					asm_syntax_param_reg(char *str, int line);
int					asm_syntax_param_dir(char *str, int line);
int					asm_syntax_param_ind(char *str, int line);
int					asm_syntax_param(char **s, t_btcode *btcode, int j, int f);
int					ft_atoi2(const char *str);

#endif
