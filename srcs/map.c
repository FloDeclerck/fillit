/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:27:17 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/12/07 15:27:31 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		square(int nb)
{
	int min;

	min = 1;
	while (min * min < nb)
		min++;
	return (min);
}

int				init_fillit(t_space *space, char *file)
{
	space->pieces = NULL;
	space->nb_pieces = 0;
	space->map = NULL;
	if(parse_file(space, file))
	{
		is_map(space, 4 * space->nb_pieces);
		space->size = 2 * square(space->nb_pieces) - 1;
		return (1);
	}
	return (0);
}

static int		is_map(t_space *space, int size)
{
	int i;

	if (!(space->map = (char **)malloc(size * sizeof(char *))))
		return (0);
	i = 0;
	while (i < size)
	{
		if (!(space->map[i] = (char *)malloc(size * sizeof(char))))
			return (0);
		ft_memset(space->map[i++], CEMPTY, size);}
		return (1);
}

char		*pieces_buf(char const *str, unsigned int start, size_t length,
		char j)
{
	char	*pieces;
	unsigned int i;

	if (!str)
		return (NULL);
	pieces = ft_strnew(length);
	if (!pieces)
		return (NULL);
	i = 0;
	while (i < length)
	{
		if (s[start + i] == CBLOCK)
			pieces[i] = j;
		else
			pieces[i] = s[start + i];
		i++;
	}
	return (pieces);
}


