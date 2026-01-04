/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:40:21 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/04 15:20:10 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_angle(char c)
{
	if (c == 'N')
		return (270);
	if (c == 'S')
		return (90);
	if (c == 'E')
		return (0);
	return (180);
}

void	position_player(t_map *map, t_data *data)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (data->map[y][x])
		{
			c = data->map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				map->px = x + 0.5f;
				map->py = y + 0.5f;
				map->angle = get_angle(c);
				data->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}
