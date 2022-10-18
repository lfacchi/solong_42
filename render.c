/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:40:14 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/09/15 17:40:14 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

//Create the images from the ".xpm" files
void	ft_img_create(t_game *game)
{
	int		size;
	int		i;
	void	*floor;
	void	*player[10];
	void	*colect;
	void	*wall;
	void	*exit;
	char	*path;
	char	*sufix;
	char	*ext;
	i = 0;
	floor = mlx_xpm_file_to_image(game->init, "sprites/floor.xpm", &size, &size);
	game->sprites.floor = floor;
	wall = mlx_xpm_file_to_image(game->init, "sprites/rwall.xpm", &size, &size);
	game->sprites.wall = wall;
	while (i < 10)
	{

		sufix = ft_itoa(i + 1);
		path = ft_strjoin("sprites/idle/idle", sufix);
		ext =  ft_strjoin(path,".xpm");
		player[i] = mlx_xpm_file_to_image(game->init, ext, &size, &size);
		game->sprites.player[i] = player[i];
		i++;
		free(sufix);
		free(ext);
		free(path);

	}
	colect = mlx_xpm_file_to_image(game->init, "sprites/colect.xpm", &size, &size);
	game->sprites.colect = colect;
	exit = mlx_xpm_file_to_image(game->init, "sprites/exit.xpm", &size, &size);
	game->sprites.exit = exit;
	
}

//Loop the map keep info of row colums number of collects, player position and exit position 
void	ft_scan_map(t_game *game, char *path_map)
{
    int		fd;
    char	*line;
    char	*split_line;

	game->map.rdmap.row = 0;
	game->map.rdmap.colects = 0;
	line = "";
	game->map.fd = open(path_map , O_RDONLY );
	line = get_next_line(game->map.fd);
	while (line != NULL)
    {
		game->map.rdmap.col = 0;
		while (line[game->map.rdmap.col])
		{
			if (line[game->map.rdmap.col] == 'E')
			{
				game->map.rdmap.exity = game->map.rdmap.col;
				game->map.rdmap.exitx = game->map.rdmap.row;
			}
			if (line[game->map.rdmap.col] == 'C')
				game->map.rdmap.colects++;
			if (line[game->map.rdmap.col] == 'P')
			{
				game->map.p_posy = game->map.rdmap.row;
				game->map.p_posx = game->map.rdmap.col;
			}
			game->map.rdmap.col++;
		}
		free(line);
		game->map.rdmap.row++;
		line = get_next_line(game->map.fd);
	}
	close(game->map.fd);
}

//Alocate and assign the map values in a matrix of char 
void	ft_ass_map(t_game *game, char *path_map)
{
	int		i;
	char	*line;

	
	line = "";
	i = 0;
	if (game->map.rdmap.col && game->map.rdmap.row)
	{
		game->map.fd = open(path_map , O_RDONLY);
		game->map.rdmap.matrix =
			ft_matrix_alocate(game->map.rdmap.col, game->map.rdmap.row);
		while (line != NULL)
		{
			line = get_next_line(game->map.fd);
			game->map.rdmap.matrix[i] = ft_strdup(line);
			i++;
			free(line);
		}
	}
}

//Render the images in game struct to the window
int	ft_render_map(t_game *game)
{
	int	i;
	int	j;
	int	posx;
	int	posy;

	i = 0;
	while (game->map.rdmap.matrix[i])
	{
		j = 0;
		while (game->map.rdmap.matrix[i][j])
		{
			posx = i * PIXEL_MAP;
			posy = j * PIXEL_MAP;
			if(game->map.rdmap.matrix[i][j] == 'P')
				mlx_put_image_to_window(game->init, game->window, game->sprites.player[0], posy, posx);
			else if(game->map.rdmap.matrix[i][j] == '1')
				mlx_put_image_to_window(game->init, game->window, game->sprites.wall, posy, posx);
			else if (game->map.rdmap.matrix[i][j] == 'C')
				mlx_put_image_to_window(game->init, game->window, game->sprites.colect, posy, posx);
			else if (game->map.rdmap.matrix[i][j] == 'E')
				mlx_put_image_to_window(game->init, game->window, game->sprites.exit, posy, posx);
			else
				mlx_put_image_to_window(game->init, game->window, game->sprites.floor, posy, posx);
			j++;
		}
		i++;
	}
	return(0);
}

//Animate the player 
int	ft_animate(t_game *game)
{
	int	size;
	int	i;
	int	x;
	int	y;

	x = game->map.p_posx * PIXEL_MAP ;
	y = game->map.p_posy * PIXEL_MAP ;
	i = 0;
	while(i < 10)
	{
		usleep(10000);
		mlx_put_image_to_window(game->init, game->window, game->sprites.player[i], x, y);
		i++;
	}
	return(0);
}
