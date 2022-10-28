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

NAME = so_long
LIBFT = 42_libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRCS = events.c render.c main.c validation.c matrix_utils.c keyarrow.c img.c game.c free.c
X11FLAGS = -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11
TEST = maps/teste.ber
MAP = maps/map1.ber

all:
	@clear
	@gcc $(FLAGS) $(SRCS) $(LIBFT) $(X11FLAGS) -o $(NAME)

mem:all
	@clear
	@valgrind --show-leak-kinds=all --leak-check=full -s ./$(NAME) foo.ber

memt:all
	@clear
	@valgrind --show-leak-kinds=all --leak-check=full -s ./$(NAME) $(TEST)

n:
	@clear
	@norminette $(SRCS)

t: all
	@clear
	@./$(NAME) $(TEST)

clean:
	@rm -rf ./$(NAME)

fclean: clean
	@rm -rf ./$(NAME)

re: clean all