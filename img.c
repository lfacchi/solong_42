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
