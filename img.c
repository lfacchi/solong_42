/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:58:47 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/10/25 21:58:47 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

//Create the images from the ".xpm" files
void	img_create(t_game *game)
{
	int		size;

	game->sprites.floor = mlx_xpm_file_to_image(game->init,
			"sprites/floor.xpm", &size, &size);
	game->sprites.wall = mlx_xpm_file_to_image(game->init,
			"sprites/rwall.xpm", &size, &size);
	player_img_create(game);
	game->sprites.colect = mlx_xpm_file_to_image(game->init,
			"sprites/colect.xpm", &size, &size);
	game->sprites.exit = mlx_xpm_file_to_image(game->init,
			"sprites/exit.xpm", &size, &size);
	game->sprites.blackbox = mlx_xpm_file_to_image(game->init,
			"sprites/blackbox.xpm", &size, &size);
}

void	player_img_create(t_game *game)
{
	int		size;
	int		i;
	char	*path;
	char	*sufix;
	char	*ext;

	i = -1;
	while (++i < 10)
	{
		sufix = ft_itoa(i + 1);
		path = ft_strjoin("sprites/idle/idle", sufix);
		ext = ft_strjoin(path, ".xpm");
		game->sprites.player[i] = mlx_xpm_file_to_image(game->init,
				ext, &size, &size);
		free(sufix);
		free(ext);
		free(path);
	}
}

void	verify_coordanates(t_game *game, char c, int row, int col)
{
	if (c == 'E')
		game->map.rdmap.e++;
	if (c == 'C')
		game->map.rdmap.colects++;
	if (c == 'P')
	{
		game->map.rdmap.p++;
		game->map.p_posy = row;
		game->map.p_posx = col;
	}
}

void	is_invalid_char(t_game *game)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (i < game->map.rdmap.row)
	{
		j = 0;
		while (j < game->map.rdmap.col)
		{
			s = ft_strchr("10PCE", game->map.rdmap.matrix[i][j]);
			if (!s)
			{
				ft_putendl_fd("Error\nInvalid map or file", 2);
				free_on_error(game);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	is_valid_wall(t_game *game, int row, int col)
{
	int	i;
	int	j;
	int	val;

	val = 0;
	i = 0;
	while (i < game->map.rdmap.row)
	{
		j = 0;
		while (j < game->map.rdmap.col)
		{
			if ((i == 0 || j == 0)
				|| (i == (row - 1)) || (j == (col - 1)))
			{
				if (game->map.rdmap.matrix[i][j] != '1')
					val = 1;
			}
			j++;
		}
		i++;
	}
	if (val == 1)
		return (0);
	else
		return (1);
}
