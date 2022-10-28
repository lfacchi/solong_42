/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:55:01 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/10/14 09:55:01 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

//Ccheck if all colums has the same size
int	is_valid_rectangle(t_game *game)
{
	int		len;
	int		i;

	i = 0;
	while ((int)(ft_strlen(
			game->map.rdmap.matrix[i])) - 1 == game->map.rdmap.col)
		i++;
	if (i == game->map.rdmap.row)
		return (1);
	len = ft_strlen(game->map.rdmap.matrix[i]);
	if (len == game->map.rdmap.col)
		return (1);
	return (0);
}

//Check if the map has a valid path to the exit
int	is_valid_path(t_game *game)
{
	int		**int_matrix;
	int		valid_path;
	int		i;
	int		row;
	int		col;

	row = game->map.rdmap.row;
	col = game->map.rdmap.col;
	int_matrix = transform_matrix(game->map.rdmap.matrix, row, col);
	valid_path = dfs(int_matrix, game->map.p_posx, game->map.p_posy);
	i = -1;
	while (++i < row)
		free(int_matrix[i]);
	free(int_matrix);
	return (valid_path);
}

//Validate the extension of map ".ber"
int	is_valid_map_entry(char *path_map)
{
	char	*p;

	p = ft_strchr(path_map, '.');
	if (!p)
		return (0);
	if (ft_strncmp(p, ".ber", 5) == 0)
		return (1);
	return (0);
}

//Check if rows and colums are different
int	is_valid(t_game *game)
{
	if (game->map.rdmap.col == game->map.rdmap.row)
		return (0);
	if (game->map.rdmap.col == 0 || game->map.rdmap.row == 0)
		return (0);
	return (1);
}

//Check if the map has 1 player 1 exit and at least 1 collect
int	is_valid_inputs(t_game *game)
{
	if (game->map.rdmap.p == 1
		&& game->map.rdmap.e == 1
		&& game->map.rdmap.colects)
		return (1);
	return (0);
}
