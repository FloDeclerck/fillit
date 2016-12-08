# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 12:03:18 by fdeclerc          #+#    #+#              #
#    Updated: 2016/12/08 20:22:16 by fdeclerc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = srcs/binary_conversion.c \
	   srcs/build_tetrimino.c \
	   srcs/checkfile.c \
	   srcs/check_pattern.c \
	   srcs/error.c \
	   srcs/fillit.c \
	   srcs/game_solver.c \
	   srcs/parsing.c \
	   srcs/print.c \
	   srcs/ft_support.c

OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a
LIBINC = -I./libft
LIBLINK = -L./libft -lft

SRCDIR = ./srcs/
INCDIR = ./includes/
OBJDIR = ./objs/

all: libft objs $(NAME)

objs:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(LIBLINK) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
