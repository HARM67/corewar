/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 22:42:28 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/13 07:15:08 by atrupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_set_opt_dump(t_app *app, int x)
{
	int i;

	i = 0;
	if (app->av[x])
	{
		while (app->av[x][i])
		{
			if (ft_isdigit(app->av[x][i]) == 0)
				vm_print_error("Error : no valid dump cycle");
			i++;
		}
		if (ft_atoi(app->av[x]) < 0)
			vm_print_error("Error : dump cycle must be over 0");
		app->start_cycle = ft_atoi(app->av[x]);
		app->d_bool = 1;
		app->fl.d = 1;
	}
	else
		vm_print_error("Error : no valid dump cycle");
}

void		vm_print_help(void)
{
	ft_printf("./corewar [flags] [player1.cor] [player2.cor] ...\n");
	ft_printf("#---------------------------------------------------------#\n");
	ft_printf("# -h      : help, show VM commands                        #\n");
	ft_printf("# -a      : display aff functions                         #\n");
	ft_printf("# -v      : verbose mode                                  #\n");
	ft_printf("# -g      : show graphic mode (ncurses)                   #\n");
	ft_printf("# -n X Y  : set the X id to the player Y                  #\n");
	ft_printf("# -dump X : dump the memory after X cycles                #\n");
	ft_printf("#---------------------------------------------------------#\n");
	exit(1);
}

int			vm_split(t_app *app, int *token, int *i, char *str)
{
	t_player	*player;

	if (*token != 0)
		return (0);
	if (ft_strcmp("-dump", str) == 0)
		*token = 3;
	else if (ft_strcmp("-n", str) == 0)
		*token = 1;
	else if (ft_strcmp("-h", str) == 0)
		vm_print_help();
	else if (ft_strcmp("-a", str) == 0)
		app->fl.a = 1;
	else if (ft_strcmp("-v", str) == 0)
		app->fl.v = 1;
	else if (ft_strcmp("-g", str) == 0)
		app->fl.g = 1;
	else
	{
		player = vm_read_player(app, app->av[*i]);
		ft_memcpy(&app->player[app->nbr_player], player, sizeof(t_player));
		free(player);
		app->player[app->nbr_player].id = app->player_nb.p_nb--;
		app->nbr_player++;
	}
	return (1);
}

void		vm_check_flags(t_app *app, int *token, int *i)
{
	char		*str;
	t_player	*player;

	str = app->av[*i];
	if (vm_split(app, token, i, str))
		;
	else if (*token == 1)
	{
		vm_check_player_nb(app, str);
		*token = 2;
	}
	else if (*token == 2)
	{
		player = vm_read_player(app, app->av[*i]);
		ft_memcpy(&app->player[app->nbr_player], player, sizeof(t_player));
		free(player);
		app->player[app->nbr_player].id = app->player_nb.p_nb--;
		app->nbr_player++;
		*token = 0;
	}
	else if (*token == 3)
	{
		vm_set_opt_dump(app, *i);
		*token = 0;
	}
}

void		vm_check_magic(t_app *app)
{
	unsigned int	i;

	i = 0;
	while (i < app->nbr_player)
	{
		if (app->player[i].header.magic != COREWAR_EXEC_MAGIC)
			vm_print_error("Error : Wrong COREWAR_EXEC_MAGIC number");
		i++;
	}
}
