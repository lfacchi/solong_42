/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:04:40 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/10/25 12:04:40 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_map(t_game *game)
{
	int	i;
	int	j;

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

int	keyboard(int key, t_game *game)
{
	char	move;
	int		x;
	int		y;
	t_pos	p;

	x = game->map.p_posx;
	y = game->map.p_posy;
	if (key == 65361 && game->map.rdmap.matrix[y][x - 1] != '1')
		count_colect(game, game->map.rdmap.matrix[y][game->map.p_posx - 1]);
	if (key == 65362 && game->map.rdmap.matrix[y - 1][x] != '1')
		count_colect(game, game->map.rdmap.matrix[y - 1][x]);
	if (key == 65363 && game->map.rdmap.matrix[y][x + 1] != '1')
		count_colect(game, game->map.rdmap.matrix[y][x + 1]);
	if (key == 65364 && game->map.rdmap.matrix[y + 1][x] != '1')
		count_colect(game, game->map.rdmap.matrix[y + 1][x]);
	move_player(game, key);
	render_map(game, p);
	if (key == 65307)
		finish_game(game);
	return (0);
}

int	check_error(t_game *game, char *map_path)
{
	if (!is_valid(game) || !is_valid_inputs(game)
		|| !is_valid_map_entry(map_path))
	{
		ft_putendl_fd("Error", 1);
		exit(1);
	}
	if (!is_valid_path(game) || !is_valid_rectangle(game))
	{
		ft_putendl_fd("Error", 1);
		finish_game(game);
		exit(1);
	}
}

void	render_moves(t_game *game)
{
	char	*moves;
	char	*prefix;
	char	*full;

	prefix = "Moves: ";
	moves = ft_itoa(game->moves);
	full = ft_strjoin(prefix, moves);
	mlx_put_image_to_window(game->init, game->window,
		game->sprites.blackbox, 10, ((game->map.rdmap.row) * PIXEL_MAP));
	mlx_string_put(game->init, game->window,
		(game->map.rdmap.row),
		(((game->map.rdmap.row + 1) * PIXEL_MAP) - (PIXEL_MAP / 2)),
		0xf8f8ff, full);
	free(moves);
	free(full);
}
