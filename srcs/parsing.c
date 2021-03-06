/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:05:05 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/12 18:00:00 by rmusella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void		set_delimitator_for_split(char *str)
{
	int		cursor;

	cursor = 20;
	while ((cursor + 1) <= (int)ft_strlen(str))
	{
		if (str[cursor] != '\n')
			error_msg_exit("error");
		if (str[cursor] == '\n' && cursor == (int)ft_strlen(str))
			error_msg_exit("error");
		str[cursor] = '\t';
		cursor += 21;
	}
}

static void		check_tot_length(int length)
{
	if (length == 0 || ((length + 1) % (TETRIMINO_SIZE + 1)) != 0)
		error_msg_exit("error");
}

static int		read_input(int fd, char *buffer)
{
	int		char_count;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	char_count = read(fd, buffer, BUFFER_SIZE);
	if (char_count == -1)
		error_msg_exit("error");
	return (char_count);
}

void			parse_file(int fd, t_game *game)
{
	char	buffer[BUFFER_SIZE + 1];
	int		char_counter;

	char_counter = read_input(fd, buffer);
	check_tot_length(char_counter);
	set_delimitator_for_split(buffer);
	parse_string(buffer, game);
}
