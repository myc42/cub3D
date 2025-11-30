/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:05:05 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/30 19:11:23 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	initialize_mlx(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (printf("mlx init error \n"), 0);
	map->buffer[0].img = mlx_new_image(map->mlx, 480, 480);
	map->buffer[0].address = mlx_get_data_addr(map->buffer[0].img,
			&map->buffer[0].Bits_Per_Pixel, &map->buffer[0].line_octet_length,
			&map->buffer[0].octet_order);
	map->buffer[1].img = mlx_new_image(map->mlx, 480, 480);
	map->buffer[1].address = mlx_get_data_addr(map->buffer[1].img,
			&map->buffer[1].Bits_Per_Pixel, &map->buffer[1].line_octet_length,
			&map->buffer[1].octet_order);
	map->current = 0;
	return (1);
}

int	initialize_texture(t_map *map, t_data *data)
{
	(void)map;
	(void)data;
	return (1);
}