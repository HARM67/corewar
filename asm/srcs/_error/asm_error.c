#include "asm.h"

void	asm_update_label_pos(t_app *app)
{
	t_label	*l;

	l = app->label;
	while (l)
	{
		if (l->pos == -1)
			l->pos = app->byte_count;
		l = l->next;
	}
}

void	asm_check_line(t_app *app, char *str, int line)
{
	int			i;
	int			index_instr;
	t_btcode	*bt;

	i = 0;
	bt = asm_create_bt();
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (*str)
	{
		asm_error_label(&str, app);
		if (!*str)
			return ;
		asm_update_label_pos(app);
		index_instr = asm_error_instr(&str, app, line, bt);
		asm_error_param(&str, line, bt);
		//printf("[%s] %d\n", str, line);
		if (*str)
			asm_put_error_line(str, line);
		asm_push_bt(app, bt);
		app->byte_count += bt->cmd->cmd_size;
	}
}

t_instr	asm_get_instr(t_app *app, int i_instr)
{
	int		i;

	i = 0;
	while (i < 16 && i != i_instr)
		i++;
	return (app->instr[i]);
}