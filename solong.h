

# include "minilibx-linux/mlx.h"
# include "42_libft/libft.h"
# include "42_libft/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# ifndef PIXEL_MAP
#  define PIXEL_MAP 64
# endif
# define P_PLAYER "sprites/wfloor.xpm"
# define P_WALL "sprites/rwall.xpm"
# define P_FLOOR "sprites/wfloor.xpm"

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
    void *player;
    void *floor;
    void *wall;
    void *colect;
}t_sprites;

typedef struct s_game{
	void *init;
	void *window;
    t_map map;
    t_sprites sprites;
}t_game;

char **ft_matrix_alocate(int x , int y);
int key_value(int key, t_game *id);
void ft_img_create(t_game *game);
void ft_ass_map(t_game *game, char *path_map);
void ft_scan_map(t_game *game, char *path_map);
void ft_print_matrix(char **matrix);
void ft_render_map(t_game *game);
int ft_check_move( char move);
int ft_keyboard(int key, t_game *game);
void ft_matrix_move(t_game *game, int key);
int ft_validate_map(t_game *game, char *path_map);