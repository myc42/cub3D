/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:40:21 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/25 19:58:07 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	position_player(t_map *map, t_data *data)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < data->map_rows)
	{
		x = 0;
		while (x < data->map[y][x])
		{
			c = data->map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				map->px = x;
				map->py = y;
				if (c == 'N')
					map->angle = 270;
				if (c == 'S')
					map->angle = 90;
				if (c == 'E')
					map->angle = 0;
				if (c == 'W')
					map->angle = 180;
				data->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}
