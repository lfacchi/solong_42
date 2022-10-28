/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 05:18:37 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/10/28 05:19:24 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_on_error(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.rdmap.row)
		free(game->map.rdmap.matrix[i]);
	free(game->map.rdmap.matrix);
	exit(0);
}
