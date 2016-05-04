/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:39:36 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/13 07:32:38 by atrupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		vm_check_dispo(t_app *app, int nbr)
{
	unsigned int	i;

	i = 0;
	while (i < app->nbr_player)
	{
		if (nbr == (int)app->player[i].id)
			vm_print_error("Error : Two players have the same id");
		i++;
	}
	return (1);
}

static void		vm_read_prog(int fd, t_player *player, char *filename)
{
	if (player->header.prog_size > CHAMP_MAX_SIZE)
		vm_print_error_str("Error : One player oversize"
				, filename);
	player->prog = (unsigned char*)ft_memalloc(sizeof(unsigned char) *
													player->header.prog_size);
	if (read(fd, player->prog, player->header.prog_size + 1) !=
													player->header.prog_size)
		vm_print_error_str("Error : can't read player program ", filename);
}

t_player		*vm_read_player(t_app *app, char *filename)
{
	int				fd;
	t_player		*rt;

	rt = malloc(sizeof(t_player));
	ft_bzero(rt, sizeof(t_player));
	if (!filename)
		vm_print_error("Error : Wrong player");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		vm_print_error_str("Error : can't malloc or open player ", filename);
	if (read(fd, &rt->header, sizeof(t_header)) != sizeof(t_header))
		vm_print_error_str("Error : can't read player ", filename);
	vm_swap_bytes_4(&rt->header.prog_size);
	vm_swap_bytes_4(&rt->header.magic);
	ft_bzero(rt->header.prog_name + PROG_NAME_LENGTH + 1, 3);
	ft_bzero(rt->header.comment + COMMENT_LENGTH + 1, 3);
	vm_read_prog(fd, rt, filename);
	vm_create_instance(app);
	return (rt);
}

void			vm_check_player_nb(t_app *app, char *av)
{
	int i;

	i = 0;
	app->player_nb.p_nb = ft_atoi(av);
	if (av && vm_check_dispo(app, app->player_nb.p_nb))
	{
		if ((av[0] == '-') && av[1])
			i++;
		while (av[i])
		{
			if (ft_isdigit(av[i]) == 0)
				vm_print_error("Error : invalid player number");
			i++;
		}
	}
	else
		vm_print_error("Error : invalid player number");
}
