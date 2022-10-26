/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:06:06 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/10/20 11:06:06 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/* Starts the number of players exits and moves
and calls the scan and assign map function */
void	init_game(t_game *game, char *map_path)
{
	game->map.rdmap.p = 0;
	game->map.rdmap.e = 0;
	game->map.rdmap.colects = 0;
	game->moves = 0;
	scan_map(game, map_path);
	ass_map(game, map_path);
}

//Destroy all imgs, the window, game instance and free the matrix
int	finish_game(t_game *game)
{
	int	i;

	mlx_clear_window(game->init, game->window);
	mlx_destroy_image(game->init, game->sprites.wall);
	mlx_destroy_image(game->init, game->sprites.floor);
	mlx_destroy_image(game->init, game->sprites.exit);
	mlx_destroy_image(game->init, game->sprites.colect);
	mlx_destroy_image(game->init, game->sprites.blackbox);
	i = -1;
	while (++i < 10)
		mlx_destroy_image(game->init, game->sprites.player[i]);
	i = -1;
	while (++i < game->map.rdmap.row)
		free(game->map.rdmap.matrix[i]);
	if (game->init && game->window)
	{
		mlx_destroy_window(game->init, game->window);
		mlx_destroy_display(game->init);
	}
	free(game->init);
	free(game->map.rdmap.matrix);
	exit(0);
}

//Recive the arrows input from keybord and move the player on matrix
void	move_player(t_game *game, int key)
{
	int		x;
	int		y;
	t_pos	i;
	t_pos	f;

	x = game->map.p_posx;
	y = game->map.p_posy;
	i.x = x;
	i.y = y;
	if (key == 65361 && game->map.rdmap.matrix[y][x - 1] != '1')
		move_left(game, i, f);
	else if (key == 65363 && game->map.rdmap.matrix[y][x + 1] != '1')
		move_right(game, i, f);
	else if (key == 65362 && game->map.rdmap.matrix[y - 1][x] != '1')
		move_up(game, i, f);
	else if (key == 65364 && game->map.rdmap.matrix[y + 1][x] != '1')
		move_down(game, i, f);
}

//Count the number of coins collected 
void	count_colect(t_game	*game, char next_move)
{
	if (next_move == 'C')
		game->map.rdmap.colects--;
	if (game->map.rdmap.colects == 0 && next_move == 'E')
		finish_game(game);
}

//Swap de position of the player on matrix and count moves
void	pos_swap(t_game *game, t_pos i, t_pos f)
{
	char	temp;

	if (game->map.rdmap.matrix[f.y][f.x] != 'E')
	{
		temp = game->map.rdmap.matrix[f.y][f.x];
		game->map.rdmap.matrix[i.y][i.x] = '0';
		game->map.rdmap.matrix[f.y][f.x] = 'P';
		game->map.p_posx = f.x;
		game->map.p_posy = f.y;
		game->moves++;
	}
	else if (game->map.rdmap.colects == 0)
	{
		game->map.rdmap.matrix[i.y][i.x] = '0';
		game->map.rdmap.matrix[f.y][f.x] = 'P';
		game->map.p_posx = f.x;
		game->map.p_posy = f.y;
		game->moves++;
	}
}
