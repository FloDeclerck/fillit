/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:49:55 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/08 22:20:03 by rmusella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	fd = -1;
	if (argc == 1)
		error_msg_exit("usage: fillit extern_file");
	else if (argc != 2)
		error_msg_exit("error: number of arguments is invalid");
	else
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg_exit("error opening the input file");
	ft_memset(&game, 0, sizeof(game));
	parse_file(fd, &game);
	close(fd);
	game_solver(&game);
	return (0);
}
