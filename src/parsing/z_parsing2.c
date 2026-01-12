/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_parsing2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knehal <knehal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:34:43 by knehal            #+#    #+#             */
/*   Updated: 2026/01/09 20:09:35 by knehal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_walkable(char c)
{
	return (c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W');
}

void	set_colors_and_grid(t_data *data, t_map *map)
{
	map->floor_color = data->color_floor;
	map->ceiling_color = data->color_cielling;
	map->grid = data->map;
}
