#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "sys/types.h"
# include "sys/uio.h"
# include "../libft/includes/libft.h"


# define WIN_WID 200
# define WIN_LEN 320
# define FOV 60
# define POV (int)(WIN_LEN / 2 / tanf(FOV/2))
# define WALL '*'
# define PATH ' '
# define STARTPLAYER 'D'
# define STEP 64
# define STARTANGLE 90
# define BUFF_SIZE 8

# define KEYECHAP 65307
# define KEYLEFT 65361
# define KEYUP 65362
# define KEYRIGHT 65363
# define KEYDOWN 65364

# define COLOR_WHITE 0xCCCCCC
# define COLOR_RED 0xCC0000
# define COLOR_ORANGE 0xFF7700
# define COLOR_YELLOW 0xCCCC00
# define COLOR_GREEN 0x00CC00
# define COLOR_CYAN 0x00CCCC
# define COLOR_BLUE 0x0000CC
# define COLOR_MAGENTA 0xCC00CC
# define COLOR_BLACK 0x000000

typedef struct			s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef struct			s_map
{
	char				**maze;
	int					col;
	int					row;
	t_pos				*start;
}						t_map;

typedef struct 			s_img
{
	void				*img;
	char				*data;
	int					bbp;
	int					size_line;
	int					endian;
}						t_img;

typedef struct			s_win
{
	void				*mlx;
	void				*win;
	t_img				*img;
}						t_win;

typedef struct			s_cam
{
	t_pos				*pos;
	float				angle;
}						t_cam;

typedef struct		s_info
{
	char			*start;
	char			*buf;
	int				fd;
	int				offset;
	struct s_info	*next;
}					t_info;

typedef void (*t_funmove)(t_win*);

/*
** camera_fct.c
*/
t_cam			*ft_new_camera(t_pos *pos, int angle);
void			ft_set_camera(t_cam *cam, t_pos *pos, int angle);
void			ft_del_camera(t_cam *cam);

/*
** map_fct.c
*/
t_map			*ft_init_map(char *file_map);
int				ft_get_start_player(t_map *map);
char			**ft_resize_maze(char **maze, int nbr);
void			ft_read_map(int fd, t_map *map);
int				ft_open_map(char *map_file);

/*
** move_fct.c
*/
void			move_up(t_win *win);
void			move_down(t_win *win);
void			move_left(t_win *win);
void			move_right(t_win *win);
t_funmove		*init_fun_moves(void);

/*
** detect_fct.c
*/
void			ft_detect_wall(t_win *window, t_cam *cam, t_map *map);

/*
** error_fct.c
*/
void			ft_error(char *s);

/*
** hook_fct.c
*/
int				ft_key_hook(int keycode, t_win *window);
int				ft_expose_hook(t_win *window);

/*
** draw.c
*/
void			ft_draw(t_win *window, int wall_dist, int pix);

/*
** ft_get_next_line.c
*/
int				get_next_line(int const fd, char **line);

/*
** env_fct.c
*/
t_win			*init_env(void);

/*
** img_fct.c
*/
t_img			*init_img(t_win *win);
void			img_del(t_img *img);

/*
** pos_fct.c
*/
t_pos			*pos_init(int x, int y);
void			pos_del(t_pos *pos);

#endif /* !WOLF3D_H */
