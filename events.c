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
		ft_count_colect(game,game->map.rdmap.matrix[game->map.p_posy][game->map.p_posx - 1]);
		ft_matrix_move(game, key);
	}
	if (key == 65362 && game->map.rdmap.matrix[game->map.p_posy - 1][game->map.p_posx] != '1')
	{
		ft_count_colect(game, game->map.rdmap.matrix[game->map.p_posy - 1][game->map.p_posx]);
		ft_matrix_move(game, key);
	}
	if (key == 65363 && game->map.rdmap.matrix[game->map.p_posy][game->map.p_posx + 1] != '1')
	{
		ft_count_colect(game, game->map.rdmap.matrix[game->map.p_posy][game->map.p_posx + 1]);
		ft_matrix_move(game, key);
	}
	if (key == 65364 && game->map.rdmap.matrix[game->map.p_posy + 1][game->map.p_posx] != '1')
	{
		ft_count_colect(game, game->map.rdmap.matrix[game->map.p_posy + 1][game->map.p_posx]);
		ft_matrix_move(game , key);
	}
	ft_render_map(game);
	if (key == 65307)
		ft_finish_game(game);
}

void ft_matrix_move(t_game *game, int key)
{
	int x;
	int y;

	x = game->map.p_posx;
	y = game->map.p_posy;
	if (key == 65361)
		ft_pos_swap(game, game->map.rdmap.matrix, y , x, y, (x - 1));
	if (key == 65363)
		ft_pos_swap(game, game->map.rdmap.matrix, y, x, y, (x + 1));
	if (key == 65362)
		ft_pos_swap(game, game->map.rdmap.matrix, y , x, (y - 1), x);
	if (key == 65364)
		ft_pos_swap(game, game->map.rdmap.matrix, y , x, (y + 1), x);
}

void ft_count_colect(t_game	*game, char next_move)
{
	if (next_move == 'C')
		game->map.rdmap.colects--;
	if (game->map.rdmap.colects == 0 && next_move == 'E')
		ft_finish_game(game);
}

int ft_finish_game(t_game *game)
{
	int i;

	mlx_clear_window(game->init, game->window);
	mlx_destroy_image(game->init, game->sprites.wall);
	mlx_destroy_image(game->init, game->sprites.floor);
	mlx_destroy_image(game->init, game->sprites.exit);
	mlx_destroy_image(game->init, game->sprites.colect);
	mlx_destroy_image(game->init, game->sprites.blackbox);
	i = -1;
	while(++i < 10)
		mlx_destroy_image(game->init, game->sprites.player[i]);
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
void ft_pos_swap(t_game *game,char **matrix, int y1, int x1, int y2, int x2)
{
	char temp;

	if (matrix[y2][x2] != 'E')
	{
		temp = matrix[y1][x1];
		matrix[y1][x1] = '0';
		matrix[y2][x2] = 'P';
		game->map.p_posx = x2;
		game->map.p_posy = y2;
		game->moves++;
	}
	else if(game->map.rdmap.colects == 0)
	{
		matrix[y1][x1] = '0';
		matrix[y2][x2] = 'P';
		game->map.p_posx = x2;
		game->map.p_posy = y2;
		game->moves++;
	}
}
