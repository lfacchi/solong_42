/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:22:31 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/09/15 17:22:31 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	fn(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map.rdmap.matrix[i])
	{
		j = 0;
		while (game->map.rdmap.matrix[i][j])
			printf("%c", game->map.rdmap.matrix[i][j++]);
		i++;
	}
	printf("\n");
}

int ft_keyboard(int key, t_game *game)
{
	if (key == 65361 && game->map.rdmap.matrix[game->map.p_posy][game->map.p_posx - 1] != '1')
	{
		if (game->map.rdmap.matrix[game->map.p_posy][game->map.p_posx - 1] == 'C')
		{
			game->map.rdmap.colects--;
			if(game->map.rdmap.colects == 0)
				printf("LIBERAR SCAPE\n");
		}
		ft_matrix_move(game , key);
	}
	if (key == 65362 && game->map.rdmap.matrix[game->map.p_posy - 1][game->map.p_posx] != '1')
	{
		if (game->map.rdmap.matrix[game->map.p_posy - 1][game->map.p_posx] == 'C')
		{
			game->map.rdmap.colects--;
			if(game->map.rdmap.colects == 0)
				printf("LIBERAR SCAPE\n");
		}
		ft_matrix_move(game , key);
	}
	if (key == 65363 && game->map.rdmap.matrix[game->map.p_posy][game->map.p_posx + 1] != '1')
	{
		if (game->map.rdmap.matrix[game->map.p_posy][game->map.p_posx + 1] == 'C')
		{
			game->map.rdmap.colects--;
			if(game->map.rdmap.colects == 0)
				printf("LIBERAR SCAPE\n");
		}
		ft_matrix_move(game , key);
	}
	if (key == 65364 && game->map.rdmap.matrix[game->map.p_posy + 1][game->map.p_posx] != '1')
	{
		if (game->map.rdmap.matrix[game->map.p_posy + 1][game->map.p_posx] == 'C')
		{
			game->map.rdmap.colects--;
			if(game->map.rdmap.colects == 0)
				printf("LIBERAR SCAPE\n");
		}
		ft_matrix_move(game , key);
	}
	
	ft_render_map(game);
	if (key == 65307)
	{
		ft_finish_game(game);
	}
}

void ft_matrix_move(t_game *game, int key)
{
	int x;
	int y;
	x = game->map.p_posx;
	y = game->map.p_posy;
	if (key == 65361)
	{
		game->map.rdmap.matrix[y][x] = '0';
		x--;
		game->map.rdmap.matrix[y][x] = 'P';
		game->map.p_posx--;
	}
	if (key == 65363)
	{
		game->map.rdmap.matrix[y][x] = '0';
		x++;
		game->map.rdmap.matrix[y][x] = 'P';
		game->map.p_posx++;
	}
	if (key == 65362)
	{
		game->map.rdmap.matrix[y][x] = '0';
		y--;
		game->map.rdmap.matrix[y][x] = 'P';
		game->map.p_posy--;
	}
	if (key == 65364)
	{
		game->map.rdmap.matrix[y][x] = '0';
		y++;
		game->map.rdmap.matrix[y][x] = 'P';
		game->map.p_posy++;
	}
}

void ft_count_colect(t_game	*game, char next_move)
{
	if (next_move == 'C')
		game->map.rdmap.colects--;
	if (game->map.rdmap.colects == 0)
		printf("liberar scape");
}

int ft_finish_game(t_game *game)
{
	int i;
	int j;
	mlx_clear_window(game->init, game->window);
	mlx_destroy_image(game->init, game->sprites.wall);
	mlx_destroy_image(game->init, game->sprites.floor);
	mlx_destroy_image(game->init, game->sprites.exit);
	mlx_destroy_image(game->init, game->sprites.colect);
	i = 0;
	while(i < 10)
	{
		mlx_destroy_image(game->init, game->sprites.player[i]);
		i++;
	}
	mlx_destroy_window(game->init, game->window);
	mlx_destroy_display(game->init);
	i = -1;
	while(++i < game->map.rdmap.row)
		free(game->map.rdmap.matrix[i]);
	free(game->map.rdmap.matrix[i]);
	free(game->init);
	free(game->map.rdmap.matrix);
	exit(0);
}
