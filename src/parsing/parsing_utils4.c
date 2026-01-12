/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knehal <knehal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:09:25 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/09 19:18:44 by knehal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img_buffer *img, int x, int y, int color)
{
	char	*dst;

	if (!img || !img->address)
		return ;
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->address + (y * img->line_octet_length) + (x
			* (img->bits_per_pixel / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

unsigned int	get_texel(t_img_buffer *tex, int x, int y)
{
	char	*dst;

	if (!tex || !tex->address)
		return (0);
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x >= tex->width)
		x = tex->width - 1;
	if (y >= tex->height)
		y = tex->height - 1;
	dst = tex->address + (y * tex->line_octet_length) + (x
			* (tex->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	get_map_size(t_map *map, int *h, int *w)
{
	int	len;

	if (!map || !map->grid)
		return (0);
	*h = 0;
	*w = 0;
	while (map->grid[*h])
	{
		len = (int)ft_strlen(map->grid[*h]);
		if (len > *w)
			*w = len;
		(*h)++;
	}
	if (*h <= 0 || *w <= 0)
		return (0);
	return (1);
}

int	is_wall_cell(t_map *map, int map_h, int y, int x)
{
	int	len;

	if (y < 0 || y >= map_h || x < 0)
		return (1);
	if (!map->grid[y])
		return (1);
	len = (int)ft_strlen(map->grid[y]);
	if (x >= len)
		return (1);
	if (map->grid[y][x] == '1' || map->grid[y][x] == ' ')
		return (1);
	return (0);
}

void	init_ray(t_map *map, t_ray *r, int x)
{
	r->camera_x = (2.0 * (double)x / (double)SCREEN_W) - 1.0;
	r->ray_dir_x = map->player.dir_x + map->player.plane_x * r->camera_x;
	r->ray_dir_y = map->player.dir_y + map->player.plane_y * r->camera_x;
	r->map_x = (int)map->player.x;
	r->map_y = (int)map->player.y;
	r->hit = 0;
	r->side = 0;
}
