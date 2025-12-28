/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:46:36 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/30 19:21:51 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../librairie/ft_libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <math.h>

# define MAX_MAP_LINES 1000000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MM_TILE 8
# define MM_PAD  10
# define MM_MAX_W 200
# define MM_MAX_H 200

# define KEY_W       119
# define KEY_A       97
# define KEY_S       115
# define KEY_D       100
# define KEY_ESC     65307
# define KEY_LEFT    65361
# define KEY_RIGHT   65363
# define SCREEN_W 640
# define SCREEN_H 480
# define MOUSE_SENS 0.002

# define MOVE_SPEED  0.0008
# define ROT_SPEED   0.0005
# define MOUSE_CENTER_X (SCREEN_W / 2)
# define MOUSE_CENTER_Y (SCREEN_H / 2)


typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		line_len;
	int		endian;
}	t_tex;


typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_img_buffer
{
	void			*img;
	char			*address;
	int				Bits_Per_Pixel;
	int				line_octet_length;
	int				octet_order;
	int				width;
	int				height;
}					t_img_buffer;

typedef struct s_data
{
	char			**map_file_content;
	char			**map;
	char			**map_header;
	int				map_start;
	int				index_end;
	int				map_height;
	int				map_rows;
	char			*wall_west;
	char			*wall_north;
	char			*wall_south;
	char			*wall_east;
	int				color_floor;
	int				color_cielling;
	t_tex	no;
	t_tex	so;
	t_tex	we;
	t_tex	ea;

}					t_data;

typedef struct s_map
{
	void		*mlx;
	void		*win;
	int   mouse_init;
	double mouse_sens;
	t_data  *data;

	char		**grid;
	int			width;
	int			height;
	int floor_color;
	int ceiling_color;

	t_player	player;
	t_keys		keys;
	t_img_buffer	wall_west;
	t_img_buffer	wall_north;
	t_img_buffer	wall_south;
	t_img_buffer	wall_east;
	t_img_buffer	ground;

	float			px;
	float			py;
	float			angle;
	t_img_buffer	buffer[2];
	int				current;
	int     mouse_warp;


}					t_map;

typedef struct s_ray
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			perp_wall_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
	t_img_buffer	*tex;
	int				tex_x;
	double			step;
	double			tex_pos;
}	t_ray;

int					parsing(t_data *data, t_map *map, char *av);
int					stock_map_infos(char *file, t_data *data);
int					check_map_rectangular(t_data *data);
int					check_map_outline(t_data *data);
int					verif_map_element(t_data *data);
char				*get_next_line(int fd);
int					validate_args(int argc, char **argv);
void				get_map(t_data *data, char *av);
int					check_map_rectangular(t_data *data);
int					check_map_outline(t_data *data);
int					verif_map_element(t_data *data);
void				position_player(t_map *map, t_data *data);
int					initialize_mlx(t_map *map);
int					ft_strcmp(char *s1, char *s2);
int					verif_load_xpm(t_data *data, t_map *map);
char				*trim_end_spaces(char *str);
int					texture_exists(t_data *data, int i);
int					stock_texture_path(t_data *data, int i);
int					ft_isspace(char c);
int					is_line_empty(char *line);
void				free_tab(char **tab);
int					find_map_start(t_data *data);
int					verif_map(t_data *data);
int					color_ceiling_floor(t_data *data);
int					map_management(t_data *data, char *av);
int					key_press(int keycode, t_map *map);
int					key_release(int keycode, t_map *map);
int					game_loop(t_map *map);
int					close_window(t_map *map);
void	render_frame(t_map *map);
void	draw_minimap(t_map *map, t_img_buffer *buf);
void    cleanup_all(t_map *map);
int     exit_error(t_map *map, const char *msg);

void	rotate_with_value(t_map *map, double rot);

int	mouse_move(int x, int y, t_map *map);

#endif