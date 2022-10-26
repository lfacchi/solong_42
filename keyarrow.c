/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyarrow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:46:23 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/10/25 20:46:23 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move_right(t_game *game, t_pos i, t_pos f)
{
	f.x = i.x + 1;
	f.y = i.y;
	pos_swap(game, i, f);
}

void	move_left(t_game *game, t_pos i, t_pos f)
{
	f.x = i.x - 1;
	f.y = i.y;
	pos_swap(game, i, f);
}

void	move_down(t_game *game, t_pos i, t_pos f)
{
	f.x = i.x;
	f.y = i.y + 1;
	pos_swap(game, i, f);
}

void	move_up(t_game *game, t_pos i, t_pos f)
{
	f.x = i.x;
	f.y = i.y - 1;
	pos_swap(game, i, f);
}
