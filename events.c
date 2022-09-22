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
	if (key == 65361 && game->map.rdmap.matrix[game->map.p_posy][game->map.p_posx - 1] != '1') // left
		ft_matrix_move(game , key);
	if (key == 65362 && game->map.rdmap.matrix[game->map.p_posy - 1][game->map.p_posx] != '1') // up
		ft_matrix_move(game , key);
	if (key == 65363 && game->map.rdmap.matrix[game->map.p_posy][game->map.p_posx + 1] != '1') // right
		ft_matrix_move(game , key);
	if (key == 65364 && game->map.rdmap.matrix[game->map.p_posy + 1][game->map.p_posx] != '1') // down
		ft_matrix_move(game , key);
	ft_render_map(game);
	if (key == 65307)
	{
		mlx_destroy_window(game->init, game->window);
		mlx_destroy_display(game->init);
        exit(0);
	}
}
/* 
left -> y , x--
right -> y , x++
up -> y-- , x
down -> y++ , x
*/
void ft_matrix_move(t_game *game, int key)
{
	int x;
	int y;
	x = game->map.p_posx;
	y = game->map.p_posy;
	if (key == 65361) // left
	{
		game->map.rdmap.matrix[y][x] = '0';
		x--;
		game->map.rdmap.matrix[y][x] = 'P';
		game->map.p_posx--;
	}
	if (key == 65363) // right
	{
		game->map.rdmap.matrix[y][x] = '0';
		x++;
		game->map.rdmap.matrix[y][x] = 'P';
		game->map.p_posx++;
	}
	if (key == 65362) // up
	{
		game->map.rdmap.matrix[y][x] = '0';
		y--;
		game->map.rdmap.matrix[y][x] = 'P';
		game->map.p_posy--;
	}
	if (key == 65364) // down
	{
		game->map.rdmap.matrix[y][x] = '0';
		y++;
		game->map.rdmap.matrix[y][x] = 'P';
		game->map.p_posy++;
	}
}