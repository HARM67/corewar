#include "asm.h"

int		asm_is_label_char(char c)
{
	int			i;
	const char	lb[] = LABEL_CHARS;

	i = 0;
	while (lb[i])
	{
		if (c == lb[i])
			return (1);
		i++;
	}
	return (0);
}

void	asm_error_label(char **str, t_app *app)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = *str;
	while (asm_is_label_char(tmp[i]))
		i++;
	if (tmp[i] == ':')
	{
		i++;
		asm_push_label(app, ft_strndup(*str, i));
		while (tmp[i] == ' ' || tmp[i] == '\t')
			i++;
		*str += i;
	}
}