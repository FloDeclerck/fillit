/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:36:59 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/09 16:46:03 by rmusella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define CHAR_EMPTY                '.'
# define CHAR_BLOCK                '#'

# define TETRIMINO_WIDTH        5
# define TETRIMINO_HEIGHT        4
# define MAX_TETRIMINOS_NB            26
# define TETRIMINO_SIZE        (TETRIMINO_WIDTH * TETRIMINO_HEIGHT)
# define BUFFER_SIZE            (MAX_TETRIMINOS_NB * (TETRIMINO_SIZE + 1))

# define PATTERNS_COUNT    19

# define MAX(A,B) (((A) > (B)) ? (A) : (B)) ;

typedef enum			e_mask
{
	TOP_MASK = 0xF000,
	LEFT_MASK = 0x8888,
	BOTTOM_MASK = 0x000F,
	RIGHT_MASK = 0x1111
}						t_mask;

typedef union			u_bit_tab
{
	unsigned short		part[4];
	unsigned long long	full;
}						t_bit_tab;

typedef struct				s_pattern
{
		char				raw_form[16];
		unsigned short		value;
		int					p_x;
}							t_pattern;

typedef struct		s_coord
{
		int		x;
		int		y;
}					t_coord;

typedef struct		s_tetrimino
{
	int				pattern_i;
	unsigned short	value;
	t_bit_tab		bits;
	t_coord			offset;
	int				width;
	int				height;
}					t_tetrimino;

typedef struct		s_game
{
	t_tetrimino		t[MAX_TETRIMINOS_NB];
	int				t_count;
	int				size;
	int				total_space;
	int				space_required;
	unsigned short	m[16];
	t_coord			cursor[19];
}					t_game;

unsigned short		str_to_bin(char *str);
void				parse_string(char *str, t_game *game);
int					matched_pattern_i(unsigned short value);
void				error_msg_exit(const char *str);
void				free_2d(char ***tab);
int					up_to_sqrt(const int nb);
int					resolve(t_game *game, int t_i, int d);
void				game_solver(t_game *game);
void				parse_file(int fd, t_game *game);
void				print_game(unsigned short game[], int game_size);
void				print_value_bits(unsigned short value, int cursor, int n);
void				print_solution(t_game *game);

#endif
