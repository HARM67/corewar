/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:39:36 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/23 00:24:24 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		read_prog(int fd, t_player *player, char *filename)
{
	player->prog = (unsigned char*)ft_memalloc(sizeof(unsigned char) *
													player->header.prog_size);
	if (read(fd, player->prog, player->header.prog_size) !=
													player->header.prog_size)
		vm_put_error_str("Error : can't read player program ", filename);
}

t_player	*read_player(t_app *app, char *filename)
{
	int				fd;
	t_player		*rt;

	rt = (t_player*)ft_memalloc(sizeof(t_player));
	fd = open(filename, O_RDONLY);
	if (!rt || fd == -1)
		vm_put_error_str("Error : can't malloc or open player ", filename);
	if (read(fd, &rt->header, sizeof(t_header)) != sizeof(t_header))
		vm_put_error_str("Error : can't read player ", filename);
	vm_swap_bytes_4(&rt->header.prog_size);
	read_prog(fd, rt, filename);
	vm_create_instance(rt);
	return (rt);
}
