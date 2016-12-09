/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 20:18:06 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/09 22:27:11 by rmusella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

extern const t_pattern		g_patterns[];

static int					set(t_game *game, t_tetrimino *t)
{
	int						i;
	t_bit_tab				tmp_bits;
	static int				j;

	ft_putstr("enter set game ");
	ft_putchar('\n');
	ft_putstr("set game index: ");
	ft_putchar('\n');
	ft_putnbr(j++);
	ft_putchar('\n');
	ft_putnbr(t->offset.x);
	ft_putchar('\n');
	ft_putnbr(t->offset.y);
	ft_putchar('\n');
	tmp_bits = t->bits;
	tmp_bits.full >>= t->offset.x;
	i = 0;
	while (i < t->height)
	{
		if (tmp_bits.part[i] & game->m[i + t->offset.y])
		{
			ft_putstr("exit set game 0 ");
			ft_putchar('\n');
			return (0);
		}
		ft_putstr("t_heigth is : ");
		ft_putnbr(t->height);
		ft_putchar('\n');
		ft_putnbr(tmp_bits.part[i]);
		ft_putchar('\n');
		i++;
	}
	i = 0;
	while (i < t->height)
	{
		game->m[i + t->offset.y] |= tmp_bits.part[i];
		i++;
	}
			ft_putstr("exit set game 1  ");
			ft_putchar('\n');
	return (1);
}

static void					unset(t_game *game, t_tetrimino *t)
{
	int						i;
	t_bit_tab				tmp_bits;
//	static int				j;

	tmp_bits = t->bits;
//	ft_putnbr(j++);
	//ft_putchar('\n');
	ft_putstr("unset game ");
	ft_putchar('\n');
	//ft_putnbr(t->offset.x);
	//ft_putchar('\n');
	tmp_bits.full >>= t->offset.x;
	i = 0;
	while (i < t->height)
	{
		game->m[i + t->offset.y] &= ~tmp_bits.part[i];
		i++;
	}
}

int							resolve(t_game *game, int t_i, int d)
{
	t_tetrimino				*t;
	t_coord					cursor_bckp;

	t = &game->t[t_i];
	cursor_bckp = game->cursor[t->pattern_i];
	t->offset = cursor_bckp;
	if (t->offset.x > 0)
		t->offset.x += g_patterns[t->pattern_i].p_x;
	else
		t->offset.x = 0;
	if (t_i > 0)
		d = (game->t[t_i - 1].value == t->value) ? d + 1 : 0;
	while (t->offset.y + t->height <= game->size)
	{
		while (t->offset.x + t->width <= game->size)
		{
			if (set(game, t))
			{
				game->cursor[t->pattern_i] = t->offset;
				ft_putstr("the tetris index  is: ");
				ft_putchar('\n');
				ft_putnbr(t_i);
				ft_putchar('\n');
				ft_putstr("and the offset is: ");
				ft_putchar('\n');
				ft_putnbr(t->offset.x);
				ft_putchar('\n');
				ft_putnbr(t->offset.y);
				ft_putchar('\n');
				if ((t_i + 1 >= game->t_count) || resolve(game, t_i + 1, d))
					return (1);
				unset(game, t);
				if (d > 1)
					return (0);
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
		if (resolve(game, 0, 0))
		{
			print_solution(game);
			break ;
		}
		game->size++;
	}
}
