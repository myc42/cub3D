/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knehal <knehal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:04:21 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/09 19:18:02 by knehal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_map *map, double y, double x)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)x;
	grid_y = (int)y;
	if (grid_x < 0 || grid_x >= map->width)
		return (1);
	if (grid_y < 0 || grid_y >= map->height)
		return (1);
	if (map->grid[grid_y][grid_x] != '0')
		return (1);
	return (0);
}

void	move_forward_backward(t_map *map)
{
	double	new_x;
	double	new_y;

	if (map->keys.w)
	{
		new_x = map->player.x + map->player.dir_x * MOVE_SPEED;
		new_y = map->player.y + map->player.dir_y * MOVE_SPEED;
		if (!is_wall(map, map->player.y, new_x))
			map->player.x = new_x;
		if (!is_wall(map, new_y, map->player.x))
			map->player.y = new_y;
	}
	if (map->keys.s)
	{
		new_x = map->player.x - map->player.dir_x * MOVE_SPEED;
		new_y = map->player.y - map->player.dir_y * MOVE_SPEED;
		if (!is_wall(map, map->player.y, new_x))
			map->player.x = new_x;
		if (!is_wall(map, new_y, map->player.x))
			map->player.y = new_y;
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	put_pixel_mm(t_img_buffer *img, int x, int y, int color)
{
	char	*dst;

	if (!img || !img->address || x < 0 || x >= img->width || y < 0
		|| y >= img->height)
		return ;
	dst = img->address + y * img->line_octet_length + x * (img->bits_per_pixel
			/ 8);
	*(unsigned int *)dst = (unsigned int)color;
}

void	draw_square(t_img_buffer *buf, t_point origin, int size, int color)
{
	t_point	p;

	if (!buf || !buf->address || size <= 0)
		return ;
	p.y = 0;
	while (p.y < size)
	{
		p.x = 0;
		while (p.x < size)
		{
			put_pixel_mm(buf, origin.x + p.x, origin.y + p.y, color);
			p.x++;
		}
		p.y++;
	}
}
