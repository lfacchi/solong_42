/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:08:31 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/10/20 09:08:31 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

//Deep First Search Algoritm
int	dfs(int **int_matrix, int x, int y)
{
	int	*current;

	current = &int_matrix[x][y];
	if (*current == 2)
		return (1);
	if (*current == 0)
	{
		*current = 3;
		if (dfs(int_matrix, x, y - 1)
			|| dfs(int_matrix, x + 1, y)
			|| dfs(int_matrix, x, y + 1)
			|| dfs(int_matrix, x - 1, y))
		{
			*current = 3;
			return (1);
		}
	}
	return (0);
}

//Transform the char matrix into int matrix
int	**transform_matrix(char **matrix, int x, int y)
{
	int	**int_matrix;
	int	i;
	int	j;

	i = 0;
	j = 0;
	int_matrix = alocate_m_int(x, y);
	while (i < x)
	{
		j = 0;
		while (j < y)
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
int	**alocate_m_int(int x, int y)
{
	int	**matrix;

	matrix = ft_calloc(x, sizeof(int *));
	while (--x >= 0)
		matrix[x] = ft_calloc(y, sizeof(int));
	return (matrix);
}

//Alocate a matrix of char x,y
char	**matrix_alocate(int size)
{
	char	**matrix;

	matrix = ft_calloc(size, sizeof(char *));
	return (matrix);
}
