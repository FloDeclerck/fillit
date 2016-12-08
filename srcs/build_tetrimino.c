/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:20:08 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/08 22:51:46 by rmusella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		get_width(unsigned short v)
{
	int		width;

	width = 4;
	while (width && !(v & 0x1000))
	{
	v >>= 1;
	width--;
	}
	return (width);
}

static void		set_dim(t_tetrimino *t)
{
	int					i;
	unsigned long long	mask;

	mask = TOP_MASK;
	i = 0;
	while (i < 4)
	{
		t->bits.part[i] = (t->value & mask) << (i * 4);
		if (t->bits.part[i])
		{
			t->height++;
			t->width = MAX(t->width, get_width(t->bits.part[i]));
		}
	mask >>= 4;
	++i;
	}
}

static void		check_tetri(char *tetri_str)
{
	int			i;
	char		c;

	i = 0;
	while (i < TETRIMINO_SIZE)
	{
	c = tetri_str[i];
	if (((i + 1) % 5 == 0 && c != '\n')
			|| ((i + 1) % 5 != 0 && c != CHAR_BLOCK && c != CHAR_EMPTY))
	error_msg_exit("error : invalid char found in tetriminos");
	i++;
	}
}

static void		parse_tetri(char *tetri_str, t_tetrimino *t)
{
	char		**t_tab;
	char		*t_str;
	int			i;

	if (!(t_tab = ft_strsplit(tetri_str, '\n')))
		return (error_msg_exit("error : split operation failure"));
	if (!(t_str = ft_strnew(16)))
		return (error_msg_exit("error : malloc operation failure"));
	i = 0;
		while (t_tab[i])
	{
		ft_strcpy(t_str + (i * 4), t_tab[i]);
		i++;
	}
	free_2D(&t_tab);
	t->value = str_to_bin(t_str);
	t->pattern_i = matched_pattern_i(t->value);
	if (t->pattern_i == -1)
		return (error_msg_exit("error : invalid shape found"));
	t->offset.x = 0;
	t->offset.y = 0;
	ft_strdel(&t_str);
	set_dim(t);
}

void			parse_string(char *str, t_game *game)
{
	char		**pieces_tab;
	char		**tmp_tab;
	int			tetri_index;

	if (!(pieces_tab = ft_strsplit(str, '\t')))
		return (error_msg_exit("error: split operation failure"));
	tmp_tab = pieces_tab;
	tetri_index = 0;
	while (*tmp_tab)
	{
	check_tetri(*tmp_tab);
	parse_tetri(*tmp_tab, &game->t[tetri_index]);
	tmp_tab++;
	tetri_index++;
	}
	free_2D(&pieces_tab);
	game->t_count = tetri_index;
}
