/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 20:18:06 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/12 17:49:23 by rmusella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

extern const t_pattern		g_patterns[];

static int					set(t_game *game, t_tetrimino *t)
{
	int						i;
	t_bit_tab				tmp_bits;

	tmp_bits = t->bits;
	tmp_bits.full >>= t->offset.x;
	i = 0;
	while (i < t->height)
	{
		if (tmp_bits.part[i] & game->m[i + t->offset.y])
			return (0);
		i++;
	}
	i = 0;
	while (i < t->height)
	{
		game->m[i + t->offset.y] |= tmp_bits.part[i];
		i++;
	}
	return (1);
}

static void					unset(t_game *game, t_tetrimino *t)
{
	int						i;
	t_bit_tab				tmp_bits;

	tmp_bits = t->bits;
	tmp_bits.full >>= t->offset.x;
	i = 0;
	while (i < t->height)
	{
		game->m[i + t->offset.y] &= ~tmp_bits.part[i];
		i++;
	}
}

int							resolve(t_game *game, int t_i)
{
	t_tetrimino				*t;
	t_coord					cursor_bckp;

	t = &game->t[t_i];
	cursor_bckp = game->cursor[t->pattern_i];
	t->offset = cursor_bckp;
	t->offset.x += t->offset.x > 0 ? g_patterns[t->pattern_i].p_x : 0;
	while (t->offset.y + t->height <= game->size)
	{
		while (t->offset.x + t->width <= game->size)
		{
			if (set(game, t))
			{
				game->cursor[t->pattern_i] = t->offset;
				if ((t_i + 1 >= game->t_count) || resolve(game, t_i + 1))
					return (1);
				unset(game, t);
			}
			t->offset.x++;
		}
		t->offset.y++;
		t->offset.x = 0;
	}
	game->cursor[t->pattern_i] = cursor_bckp;
	return (0);
}

static void					clear_game(t_game *game)
{
	int						i;

	ft_bzero(game->m, sizeof(game->m));
	ft_bzero(game->cursor, sizeof(game->cursor));
	i = 0;
	while (i < game->t_count)
	{
		game->t[i].offset.x = 0;
		game->t[i].offset.y = 0;
		i++;
	}
}

void						game_solver(t_game *game)
{
	game->space_required = game->t_count * 4;
	game->size = up_to_sqrt(game->space_required);
	while (game->size < 16)
	{
		clear_game(game);
		game->total_space = game->size * game->size;
		if (resolve(game, 0))
		{
			print_solution(game);
			break ;
		}
		game->size++;
	}
}
