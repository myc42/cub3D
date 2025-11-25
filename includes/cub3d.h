/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:46:36 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/25 19:13:18 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../librairie/ft_libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_MAP_LINES 1000000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_data
{
	char	**map;
	int		index_start;
	int		index_end;
	int		map_height;
	int		map_rows;
}			t_data;

typedef struct s_map
{
	void	*mlx;
	void	*win;
}			t_map;

int			parsing(t_data *data);
void		stock_map_infos(char *file, t_data *data);
int			check_map_rectangular(t_data *data);
int			check_map_outline(t_data *data);
int			verif_map_element(t_data *data);
char		*get_next_line(int fd);
int			validate_args(int argc, char **argv);
void		get_map(t_data *data, char *av);
int			check_map_rectangular(t_data *data);
int			check_map_outline(t_data *data);
int			verif_map_element(t_data *data);

#endif