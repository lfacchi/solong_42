/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:40:14 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/10/20 10:53:39 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/* Loop the map keep info of row colums number of collects,
player position and exit position  */
void	scan_map(t_game *game, char *path_map)
{
	char	*line;
	int		row;
	int		col;
	int		fd;

	fd = open(path_map, O_RDONLY);
	line = get_next_line(fd);
	game->map.rdmap.col = ft_strlen(line) - 2;
	row = 0;
	while (line != NULL)
	{
		col = -1;
		while (line[++col])
			verify_coordanates(game, line[col], row, col);
		row++;
		free(line);
		line = get_next_line(fd);
	}
	game->map.rdmap.row = row;
	close(fd);
}

//Alocate and assign the map values in a matrix of char 
void	ass_map(t_game *game, char *path_map)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(path_map, O_RDONLY);
	i = -1;
	game->map.rdmap.matrix = matrix_alocate(game->map.rdmap.row);
	while (++i < game->map.rdmap.row)
	{
		line = get_next_line(fd);
		game->map.rdmap.matrix[i] = ft_strtrim(line, "\n");
		free(line);
	}
	close(fd);
}

//Render the images in game struct to the window
void	render_map(t_game *game, t_pos p)
{
	p.x = -1;
	while (++p.x < game->map.rdmap.row)
	{
		p.y = -1;
		while (++p.y < game->map.rdmap.col)
		{
			if (game->map.rdmap.matrix[p.x][p.y] == 'P')
				mlx_put_image_to_window(game->init, game->window,
					game->sprites.player[0], p.y * PIXEL_MAP, p.x * PIXEL_MAP);
			else if (game->map.rdmap.matrix[p.x][p.y] == '1')
				mlx_put_image_to_window(game->init, game->window,
					game->sprites.wall, p.y * PIXEL_MAP, p.x * PIXEL_MAP);
			else if (game->map.rdmap.matrix[p.x][p.y] == 'C')
				mlx_put_image_to_window(game->init, game->window,
					game->sprites.colect, p.y * PIXEL_MAP, p.x * PIXEL_MAP);
			else if (game->map.rdmap.matrix[p.x][p.y] == 'E')
				mlx_put_image_to_window(game->init, game->window,
					game->sprites.exit, p.y * PIXEL_MAP, p.x * PIXEL_MAP);
			else
				mlx_put_image_to_window(game->init, game->window,
					game->sprites.floor, p.y * PIXEL_MAP, p.x * PIXEL_MAP);
		}
	}
}

//Animate the player 
int	ft_animate(t_game *game)
{
	int		size;
	int		i;
	int		x;
	int		y;
	t_pos	p;

	x = game->map.p_posx * PIXEL_MAP ;
	y = game->map.p_posy * PIXEL_MAP ;
	i = 0;
	while (i < 10)
	{
		usleep(10000);
		mlx_put_image_to_window(game->init, game->window,
			game->sprites.player[i], x, y);
		i++;
	}
	render_map(game, p);
	render_moves(game);
	return (0);
}
