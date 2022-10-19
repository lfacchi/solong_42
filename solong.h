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
	char *path;
	void *img;
	int y_pos;
	int x_pos;
}t_img;

typedef struct s_rdmap{
	int col;
	int  row;
	int colects;
	char **matrix;
	int exitx;
	int exity;
} t_rdmap;

typedef struct s_map{
	int fd;
	char *path;
	int p_posy;
	int p_posx;
	t_rdmap rdmap;
} t_map;

typedef struct sprites
{
	void *player[10];
	void *floor;
	void *wall;
	void *colect;
	void *exit;
	void *blackbox;
}t_sprites;

typedef struct s_game{
	void *init;
	void *window;
	t_map map;
	t_sprites sprites;
	int moves;
}t_game;

char	**ft_matrix_alocate(int x , int y);
int		key_value(int key, t_game *id);
void	ft_img_create(t_game *game);
void	ft_ass_map(t_game *game, char *path_map);
void	ft_scan_map(t_game *game, char *path_map);
void	ft_print_matrix(char **matrix);
int		ft_render_map(t_game *game);
int		ft_check_move( char move);
int		ft_keyboard(int key, t_game *game);
void	ft_matrix_move(t_game *game, int key);
int		ft_validate_map(t_game *game, char *path_map);
void	ft_count_colect(t_game	*game, char next_move);
int		ft_animate(t_game *game);
int		ft_finish_game(t_game *game);
int		ft_dfs(int **int_matrix, int x, int y);
int		**ft_transform_matrix(char **matrix, int x, int y);
int		**ft_alocate_m_int(int x, int y);
void	fn(t_game *game);
void	ft_render_moves(t_game *game);
void	ft_pos_swap(t_game *game, char **matrix, int x1, int y1, int x2, int y2);