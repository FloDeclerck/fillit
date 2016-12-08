/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:49:55 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/05 13:53:02 by rmusella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "../includes/libft.h"
#include <stdlib.h>

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_error_msg_exit("usage: fillit extern_file");
	else if (argc != 2)
		ft_error_msg_exit("error: number of arguments is invalid");
	else
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error_msg_exit("error opening the input file");
	ft_memset(&game, 0, sizeof(game));
	parse_file(fd, &game);
	close(fd);
	solver(&game);
	return (0);
}
