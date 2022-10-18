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

//Validate the extension of map ".ber" and if the number of colums are the same in every row
int	ft_validate_map(t_game *game, char *path_map)
{
	int		i;
	char	*line;

	i = 0;
	line = "";
	while (path_map[i])
		i++;
	i--;
	if(path_map[i] != 'r' && path_map[i - 1] != 'e' && 
	path_map[i - 2] != 'b' && path_map[i - 3] != '.')
		return (0);
	game->map.fd = open(path_map , O_RDONLY);
	line = get_next_line(game->map.fd);
	i = -1;
	while (++i < game->map.rdmap.row)
	{
		if (ft_strlen(line) != game->map.rdmap.col)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(game->map.fd);
	}
	free(line);
	close(game->map.fd);
	return(1);
}

//Deep First Search Algoritm
int ft_dfs(int **int_matrix, int x, int y)
{
	int *current;
	current = &int_matrix[x][y];
	if (*current == 2)
		return (1);
	if (*current == 0)
	{
		*current = 3;
		if (ft_dfs(int_matrix, x, y - 1) 
		|| ft_dfs(int_matrix, x + 1, y) 
		|| ft_dfs(int_matrix, x, y + 1) 
		|| ft_dfs(int_matrix, x - 1, y))
		{
			*current = 3;
			return (1); 
		}
	}
	return (0);
}

//Transform the char matrix into int matrix
int **ft_transform_matrix(char **matrix, int x, int y)
{
	int	**int_matrix;
	int i;
	int j;

	i = 0;
	j = 0;
	int_matrix = ft_alocate_m_int(x , y);
	while(i < x)
	{
		j = 0;
		while(j < y)
		{
			if (matrix[i][j] == 'P' || matrix[i][j] == 'C')
				int_matrix[i][j] = 0;
			if (matrix[i][j] == '1')
				int_matrix[i][j] = 1;
			if (matrix[i][j] == 'E')
				int_matrix[i][j] = 2;
			j++;
		}
		i++;
	}
	return (int_matrix);
}

//Alocates a matrix of int 
int	**ft_alocate_m_int(int x, int y)
{
	int **matrix;

	matrix  = ft_calloc(x, sizeof(int *));
	while (--x >= 0)
		matrix[x] = ft_calloc(y ,sizeof(int));
	return (matrix);
}

//Alocate a matrix of char x,y
char	**ft_matrix_alocate(int x, int y)
{
	char	**matrix;

	matrix  = ft_calloc(x, sizeof(char *)); 
	return (matrix);
}