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

int main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	int		**int_matrix;
	int		valid_path;
	t_game	game;

	int i;
	int j;
	ft_scan_map(&game,argv[1]);
	ft_ass_map(&game, argv[1]);
	int_matrix = ft_transform_matrix(game.map.rdmap.matrix, game.map.rdmap.row, game.map.rdmap.col);
	valid_path = ft_dfs(int_matrix,1,1);
	printf("%d\n", valid_path);
	i = -1;
	while(++i < game.map.rdmap.row)
		free(int_matrix[i]);
	free(int_matrix);
	printf("%d\n", game.map.rdmap.row);
	if (valid_path == 1 && ft_validate_map(&game, argv[1]) == 1)
	{
		game.init = mlx;
		game.init= mlx_init();
		game.window = mlx_win;
		game.window = mlx_new_window(game.init, 1792, 896, "DUNGEONS AND DRAGONS");
		ft_img_create(&game);
		ft_render_map(&game);
		mlx_loop_hook(game.init, ft_animate, &game);
		mlx_key_hook(game.window, ft_keyboard, &game);
		mlx_hook(game.window , 17, 0, ft_finish_game, &game);
		mlx_loop(game.init);
	}
	
	// exit(0);
}
    