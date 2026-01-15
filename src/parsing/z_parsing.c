/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:44:26 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/15 21:11:18 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define PI 3.14159265358979323846

int	parsing_load(t_data *data, t_map *map, char *av)
{
	if (!map_management(data, av))
		return (0);
	if (!verif_map(data))
		return (printf("Error : \n map problem \n"), 0);
	if (!initialize_mlx(map))
		return (printf("Error : \n mlx problem \n"), 0);
	if (!verif_load_xpm(data, map))
		return (printf("Error : \n xpm problem \n"), 0);
	if (!color_ceiling_floor(data))
		return (printf("Error : \n color problem \n"), 0);
	return (1);
}

void	set_map_dimensions(t_map *map)
{
	int	len;

	map->height = 0;
	map->width = 0;
	while (map->grid[map->height])
	{
		len = (int)ft_strlen(map->grid[map->height]);
		if (len > map->width)
			map->width = len;
		map->height++;
	}
}

void	init_player_vectors(t_map *map)
{
	double	a;

	a = map->angle * PI / 180.0;
	map->player.x = map->px;
	map->player.y = map->py;
	map->player.dir_x = cos(a);
	map->player.dir_y = sin(a);
	map->player.plane_x = -map->player.dir_y * 0.66;
	map->player.plane_y = map->player.dir_x * 0.66;
}

int	parsing(t_data *data, t_map *map, char *av)
{
	if (!parsing_load(data, map, av))
		return (0);
	set_colors_and_grid(data, map);
	position_player(map, data);
	set_map_dimensions(map);
	init_player_vectors(map);
	return (1);
}

char	map_at(t_data *data, int y, int x)
{
	int	len;

	if (!data || !data->map || y < 0 || y >= data->map_height)
		return (' ');
	if (!data->map[y] || x < 0)
		return (' ');
	len = (int)ft_strlen(data->map[y]);
	if (x >= len)
		return (' ');
	return (data->map[y][x]);
}
