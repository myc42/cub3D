/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:46:36 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/26 17:39:52 by macoulib         ###   ########.fr       */
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

# define MAX_MAP_LINES 1000000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
	char			**map;
	int				index_start;
	int				index_end;
	int				map_height;
	int				map_rows;
	char			*wall_west;
	char			*wall_north;
	char			*wall_south;
	char			*wall_east;
}					t_data;

typedef struct s_map
{
	t_img_buffer	wall_west;
	t_img_buffer	wall_north;
	t_img_buffer	wall_south;
	t_img_buffer	wall_east;
	t_img_buffer	ground;

	void			*mlx;
	void			*win;
	float			px;
	float			py;
	float			angle;
	t_img_buffer	buffer[2];
	int				current;

}					t_map;

int					init_data(t_data *data, t_map *map);
int					parsing(t_data *data, t_map *map);
void				stock_map_infos(char *file, t_data *data);
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

#endif