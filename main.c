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
    t_game game;
    ft_scan_map(&game,argv[1]);
    if (ft_validate_map(&game, argv[1]) == 1);
    {
        ft_ass_map(&game, argv[1]);
        game.init = mlx;
        game.init= mlx_init();
        game.window = mlx_win;
        game.window = mlx_new_window(game.init, 1792,896, "GOLFINHO DO CAPETA");
        ft_img_create(&game);
        ft_render_map(&game);
        printf("%d" , game.map.rdmap.colects);
        mlx_key_hook(game.window ,ft_keyboard , &game);
        mlx_loop(game.init);
    }
   

}
