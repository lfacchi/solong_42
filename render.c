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

void ft_img_create(t_game *game)
{
    int size;
    void *floor;
    void *player;
    void *colect;
    void *wall;
    floor = mlx_xpm_file_to_image(game->init, "sprites/waterfloor.xpm", &size, &size);
    game->sprites.floor = floor;
    wall = mlx_xpm_file_to_image(game->init, "sprites/rockwall.xpm", &size, &size);
    game->sprites.wall = wall;
    player = mlx_xpm_file_to_image(game->init, "sprites/dolphin.xpm", &size, &size);
    game->sprites.player= player;
    colect = mlx_xpm_file_to_image(game->init, "sprites/colect.xpm", &size, &size);
    game->sprites.colect= colect;
}

void ft_scan_map(t_game *game, char *path_map)
{
    int fd;
    char *line;
    char *split_line;
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
            if (line[game->map.rdmap.col] == 'C')
            {
                game->map.rdmap.colects++;
            }
            if (line[game->map.rdmap.col] == 'P')
            {
                game->map.p_posy = game->map.rdmap.row;
                game->map.p_posx = game->map.rdmap.col;
            }
            game->map.rdmap.col++;
        }
        game->map.rdmap.row++;
        line = get_next_line(game->map.fd);
    }
    close(game->map.fd);
 
}

void ft_ass_map(t_game *game, char *path_map)
{
    int i;
    char *line;
    line = "";
    i = 0;
    if (game->map.rdmap.col && game->map.rdmap.row)
    {
        game->map.fd = open(path_map , O_RDONLY );
        game->map.rdmap.matrix =    
        ft_matrix_alocate(game->map.rdmap.col, game->map.rdmap.row);
        while (line != NULL)
        {
            line = get_next_line(game->map.fd);
            game->map.rdmap.matrix[i] = line;
            i++;
        }
    }
}

char **ft_matrix_alocate(int x, int y)
{
	char **matrix;
	int xi;

	xi = x;
	matrix  = ft_calloc(x, sizeof(char *));
	while (x >= 0)
	{
		matrix[x] = ft_calloc(y ,sizeof(char));
		x--;
	}
	return (matrix);
}

void ft_render_map(t_game *game)
{
    int i;
    int j;
    int posx;
    int posy;
    i = 0;
    while (game->map.rdmap.matrix[i])
    {
        j = 0;
        while (game->map.rdmap.matrix[i][j])
        {
            posx = i * PIXEL_MAP;
            posy = j * PIXEL_MAP;
            if(game->map.rdmap.matrix[i][j] == 'P')
                mlx_put_image_to_window(game->init, game->window, game->sprites.player, posy, posx);
            else if(game->map.rdmap.matrix[i][j] == '1')
                mlx_put_image_to_window(game->init, game->window, game->sprites.wall, posy, posx);
            else if (game->map.rdmap.matrix[i][j] == 'C')
                mlx_put_image_to_window(game->init, game->window, game->sprites.colect, posy, posx);
            else
                mlx_put_image_to_window(game->init, game->window, game->sprites.floor, posy, posx);
            j++;
        }
        i++;
    }
}

int ft_validate_map(t_game *game, char *path_map)
{
    int i;
    char *line;
    i = 0;
    line = "";
    while (path_map[i])
        i++;
    i--;
    if(path_map[i] != 'r' && path_map[i - 1] != 'e' && path_map[i - 3] != 'b' && path_map[i - 4] != '.')
    {
        printf("ERROR INVALID MAP");
        return (0);        
    }
    game->map.fd = open(path_map , O_RDONLY );
    line = get_next_line(game->map.fd);
    while (line != NULL)
    {
        if (ft_strlen(line) != game->map.rdmap.col)
        {
            printf("ERROR INVALID MAP");
            return (0);
        }
        line = get_next_line(game->map.fd);
    }
    close(game->map.fd);
    return(1);

}