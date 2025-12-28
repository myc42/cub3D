/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:44:26 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/30 18:26:59 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*int	parsing(t_data *data, t_map *map, char *av)
{
	if (!map_management(data, av))
		return (0);
	if (!verif_map(data))
		return (0);
	if (!initialize_mlx(map))
		return (0);
	if (!verif_load_xpm(data, map))
		return (0);
	if (!color_ceiling_floor(data))
		return (0);
	position_player(map, data);
	return (1);
}
*/

#include "../../includes/cub3d.h"

#define PI 3.14159265358979323846

static int	parsing_load(t_data *data, t_map *map, char *av)
{
	if (!map_management(data, av))
		return (0);
	if (!verif_map(data))
		return (0);
	if (!initialize_mlx(map))
		return (0);
	if (!verif_load_xpm(data, map))
		return (0);
	if (!color_ceiling_floor(data))
		return (0);
	return (1);
}

static void	set_colors_and_grid(t_data *data, t_map *map)
{
	map->floor_color = data->color_floor;
	map->ceiling_color = data->color_cielling;
	map->grid = data->map;
}

static void	set_map_dimensions(t_map *map)
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

static void	init_player_vectors(t_map *map)
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
