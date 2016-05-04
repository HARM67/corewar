#include "asm.h"

void	asm_set_real_param_size(t_cmd *cmd)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	while (i < 4)
	{
		s = 0;
		if (cmd->param[i].str)
		{
			if (cmd->param[i].str[0] == '%')
				s = (cmd->param[i].str[1] == ':') ? 2 : 4;
			else if (cmd->param[i].str[0] == 'r')
				s = 1;
			else
				s = 2;
		}
		if (s <= cmd->instr.nbr_octet[i])
			cmd->param[i].size = s;
		else if (cmd->instr.nbr_octet[i] < s)
			cmd->param[i].size = cmd->instr.nbr_octet[i];
		cmd->cmd_size += cmd->param[i].size;
		i++;
	}
}

void		asm_set_encoding_byte(t_cmd *cmd)
{
	int				i;
	unsigned char	mask_dir;
	unsigned char	mask_ind;
	unsigned char	mask_reg;

	i = 0;
	cmd->encoding = 0x00;
	if (cmd->instr.is_encoding)
	{
		mask_dir = 0x80;
		mask_ind = 0xc0;
		mask_reg = 0x40;
		while (i < 4)
		{
			if (cmd->param[i].size == 4)
				cmd->encoding |= (mask_dir >> i * 2);
			else if (cmd->param[i].size == 2)
				cmd->encoding |= (mask_ind >> i * 2);
			else if (cmd->param[i].size == 1)
				cmd->encoding |= (mask_reg >> i * 2);
			i++;
		}
	}
	asm_set_real_param_size(cmd);
}

void	asm_set_cmd_param(t_btcode *bt, char *str, int i)
{
	int		s;

	s = 0;
	if (str[0] == '%')
		s = 4;
	else if (str[0] == 'r')
		s = 1;
	else
		s = 2;
	bt->cmd->param[i].size = s;
	bt->cmd->param[i].hex = 0;
	bt->cmd->param[i].str = str;
}

void	asm_set_cmd_instr(t_app *app, t_btcode *bt, int i_instr)
{
	t_cmd	*c;

	if ((c = (t_cmd *)ft_memalloc(sizeof(t_cmd))) == NULL)
		asm_put_error("Error : Malloc CMD");
	bt->cmd = c;
	bt->cmd->cmd_size = 1;
	bt->cmd->instr.name = app->instr[i_instr].name;
	bt->cmd->instr.opcode = app->instr[i_instr].opcode;
	bt->cmd->instr.nbr_octet[0] = app->instr[i_instr].nbr_octet[0];
	bt->cmd->instr.nbr_octet[1] = app->instr[i_instr].nbr_octet[1];
	bt->cmd->instr.nbr_octet[2] = app->instr[i_instr].nbr_octet[2];
	bt->cmd->instr.nbr_octet[3] = app->instr[i_instr].nbr_octet[3];
	bt->cmd->instr.type_param[0] = app->instr[i_instr].type_param[0];
	bt->cmd->instr.type_param[1] = app->instr[i_instr].type_param[1];
	bt->cmd->instr.type_param[2] = app->instr[i_instr].type_param[2];
	bt->cmd->instr.type_param[3] = app->instr[i_instr].type_param[3];
	bt->cmd->instr.is_encoding = app->instr[i_instr].is_encoding;
	bt->cmd->cmd_size += bt->cmd->instr.is_encoding;
}