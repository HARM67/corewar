#include "asm.h"

int		asm_error_instr_exist(t_app *app, char *instr, int line)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(app->instr[i].name, instr) == 0)
			return (i);
		i++;
	}
	asm_put_error_line(instr, line);
	return (i);
}

int		asm_error_instr(char **str, t_app *app, int line, t_btcode *bt)
{
	int				i;
	char			*tmp;
	char			*tmp_instr;
	int				index_instr;

	i = 0;
	tmp = *str;
	tmp_instr = NULL;
	index_instr = 0;
	while (tmp[i] && tmp[i] != ' ' && tmp[i] != '\t' && tmp[i] != '%')
		i++;
	tmp_instr = ft_strndup(*str, i);
	index_instr = asm_error_instr_exist(app, tmp_instr, line);
	while (tmp[i] == ' ' || tmp[i] == '\t')
		i++;
	*str += i;
	ft_strdel(&tmp_instr);
	asm_set_cmd_instr(app, bt, index_instr);
	return (index_instr);
}