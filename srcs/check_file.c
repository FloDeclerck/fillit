/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:51:24 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/12/04 16:58:43 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		is_char(int c, int i)
{
	if (c == CHAR_EMPTY || c == CHAR_BLOCK
			|| ((c == '\n') && ((i % 5 == 4) || (i == 20))))
		return (1);
	return (0);
}

static int		check_tetri(char *buffer, int i)
{
	int	j;

	if (i == 19)
		return (0);
	j = 0;
	if (buffer[i] == CBLOCK)
	{
		if (i > 0 && buffer[i - 1] == CHAR_BLOCK)
			j++;
		if (i < 19 && buffer[i + 1] == CHAR_BLOCK)
			j++;
		if (i >= 5 && buffer[i - 5] == CHAR_BLOCK)
			j++;
		if (i <= 14 && buffer[i + 5] == CHAR_BLOCK)
			j++;
	}
	return (j + check_tetri(buffer, ++i));
}

static int		check_block(char *buffer)
{
	int i;
	int nb_diese;
	int fi_diese;
	int back;

	i = 0;
	nb_diese = 0;
	while (buffer[i] && is_char(buffer[i], i) && nb_diese <= 4)
	{
		if (buffer[i] == CHAR_BLOCK)
		{
			nb_diese++;
			if (nb_diese == 1)
				fi_diese = i;
		}
		i++;
	}
	if (i >= 20 && !buffer[i] && nb_diese == 4
			&& (back = check_tetri(buffer, fi_diese))
			&& (back == 6 || back == 8))
		return (1);
	else
		ft_error_msg_exit("");
	return (0);
}

int			parse_file(int fd, t_map *map)
{
	int		fd;
	int		back;
	int		lastback;
	char	buffer[21];

	while ((back = read(fd, buffer, 21)) > 0)
	{
		lastback = back;
		buffer[back] = '\0';
		if (back == 21 && check_block(buffer))
			block(map, buffer);
		else
			ft_error_msg_exit("error: an invalid block separator was found");
	}
	if (back <= 0 && (lastback == 21 || !lastback))
			ft_error_msg_exit("error: an invalid block separator was found");
	return(1);
}

