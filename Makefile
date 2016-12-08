# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 12:03:18 by fdeclerc          #+#    #+#              #
#    Updated: 2016/12/07 22:48:35 by rmusella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/binary_conversion.c \
	   srcs/build_tetrimino.c \
	   srcs/checkfile.c \
	   srcs/check_pattern.c \
	   srcs/error.c \
	   srcs/fillit.c \
	   srcs/game_solver.c \
	   srcs/parsing.c \
	   srcs/print.c

OBJS = $(subst .c, .o, $(patsubst srcs/,,$(SRCS)))

all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS) -Iincludes/ -Ilibft/includes/

lib:
	make -C libft

clean:
	/bin/rm -rf $(OBJS)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
