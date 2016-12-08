/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 20:25:07 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/08 17:26:33 by rmusella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void			print_game(unsigned short game[], int game_size)
{
	int				i;

	i = 0;
	while (i < game_size)
	{
		print_value_bits(game[i], 1, game_size);
		i++;
	}
}

void			print_value_bits(unsigned short value, int sep, int n)
{
	unsigned short	mask;
	int				i;

	mask = 0x1 << 15;
	i = 1;
	while (mask > 0 && n--)
	{
		if (value & mask)
			ft_putchar('1');
		else
			ft_putchar('0');
		if (sep && (i % sep) == 0)
			ft_putchar(' ');
		mask >>= 1;
		i++;
	}
	ft_putchar('\n');
}

static void		write_t(char *r_game, int game_size, t_tetrimino *t, int t_i)
{
	int				i;
	int				j;
	unsigned short	tmp_val;
	int				index;

	i = 0;
	while (i < t->height)
	{
		j = 0;
		tmp_val = t->bits.part[i];
		while (j < t->width)
		{
			if (tmp_val & (0x1 << 15))
			{
				index = (t->offset.y + i) * (game_size + 1) + (t->offset.x + j);
				r_game[index] = 'A' + t_i;
			}
			tmp_val <<= 1;
			j++;
		}
		i++;
	}
}

void			print_solution(t_game *game)
{
	int				i;
	int				ttr_i;
	char			*r_game;
	int				r_game_size;

	r_game_size = (game->size + 1) * game->size;
	r_game = (char *)ft_strnew(r_game_size * sizeof(char));
	if (!r_game)
		return (error_msg_exit(NULL));
	ft_memset(r_game, '.', r_game_size);
	i = 0;
	while (i < game->size)
	{
		r_game[(i + 1) * (game->size + 1) - 1] = '\n';
		i++;
	}
	ttr_i = 0;
	while (ttr_i < game->t_count)
	{
		write_t(r_game, game->size, &game->t[ttr_i], ttr_i);
		ttr_i++;
	}
	ft_putstr(r_game);
	ft_strdel(&r_game);
}
