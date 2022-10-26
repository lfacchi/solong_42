/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:16:58 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/09/16 17:16:58 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	t_game	game;
	void	*mlx;
	void	*mlx_win;
	t_pos	p;

	init_game(&game, argv[1]);
	check_error(&game, argv[1]);
	p.x = (game.map.rdmap.row + 1) * PIXEL_MAP;
	p.y = game.map.rdmap.col * PIXEL_MAP;
	game.init = mlx;
	game.window = mlx_win;
	game.init = mlx_init();
	game.window = mlx_new_window(game.init, p.y, p.x, "DUNGEONS AND DRAGONS");
	img_create(&game);
	render_map(&game, p);
	mlx_loop_hook(game.init, ft_animate, &game);
	mlx_key_hook(game.window, keyboard, &game);
	mlx_hook(game.window, 17, 0, finish_game, &game);
	mlx_loop(game.init);
}
