# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 17:32:29 by lucdos-s          #+#    #+#              #
#    Updated: 2022/09/16 17:32:29 by lucdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRCS = events.c render.c main.c validation.c
MAP = maps/teste.ber

all:
	@clear
	@gcc $(SRCS) 42_libft/libft.a -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11
	@./a.out $(MAP)

mem:
	@clear
	@gcc -g3 $(SRCS) 42_libft/libft.a -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11
	@valgrind --show-leak-kinds=all --leak-check=full -s ./a.out $(MAP)
