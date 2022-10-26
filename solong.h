/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:25:40 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/09/22 14:25:40 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include "minilibx-linux/mlx.h"
# include "42_libft/libft.h"
# include "42_libft/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define P_PLAYER "sprites/wfloor.xpm"
# define P_WALL "sprites/rwall.xpm"
# define P_FLOOR "sprites/wfloor.xpm"

# ifndef PIXEL_MAP
#  define PIXEL_MAP 64
# endif

typedef struct s_image
{
	char	*path;
	void	*img;
	int		y_pos;
	int		x_pos;
}	t_img;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_rdmap{
	int		col;
	int		row;
	int		colects;
	char	**matrix;
	int		p;
	int		e;
}	t_rdmap;

typedef struct s_map{
	int		fd;
	char	*path;
	int		p_posy;
	int		p_posx;
	t_rdmap	rdmap;
}	t_map;

typedef struct sprites
{
	void	*player[10];
	void	*floor;
	void	*wall;
	void	*colect;
	void	*exit;
	void	*blackbox;
}	t_sprites;

typedef struct s_game{
	void		*init;
	void		*window;
	t_map		map;
	t_sprites	sprites;
	int			moves;
}	t_game;
//validation.c
int		is_valid_path(t_game *game);
int		is_valid_map_entry(char *path_map);
int		is_valid(t_game *game);
int		is_valid_inputs(t_game *game);
int		is_valid_rectangle(t_game *game);
//matrix_utils.c
char	**matrix_alocate(int size);
int		dfs(int **int_matrix, int x, int y);
int		**transform_matrix(char **matrix, int x, int y);
int		**alocate_m_int(int x, int y);
void	ft_print_matrix(char **matrix);
void	print_map(t_game *game);
//render.c
void	ass_map(t_game *game, char *path_map);
void	scan_map(t_game *game, char *path_map);
void	render_map(t_game *game, t_pos p);
int		ft_animate(t_game *game);
void	render_moves(t_game *game);
//events.c
int		key_value(int key, t_game *id);
int		keyboard(int key, t_game *game);
void	move_player(t_game *game, int key);
int		check_error(t_game *game, char *map_path);
//game.c
void	init_game(t_game *game, char *map_path);
int		finish_game(t_game *game);
void	count_colect(t_game	*game, char next_move);
void	pos_swap(t_game *game, t_pos i, t_pos f);
//keyarrow.c
void	move_right(t_game *game, t_pos i, t_pos f);
void	move_left(t_game *game, t_pos i, t_pos f);
void	move_down(t_game *game, t_pos i, t_pos f);
void	move_up(t_game *game, t_pos i, t_pos f);
//img.c
void	img_create(t_game *game);
void	player_img_create(t_game *game);

#endif