/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knehal <knehal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:45:08 by knehal            #+#    #+#             */
/*   Updated: 2026/01/04 20:45:08 by knehal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_img_buffer *buf, t_point start, t_point end, int color)
{
	t_bres	b;
	t_point	p;
	int		e2;

	if (!buf || !buf->address)
		return ;
	init_bresen(&b, start, end);
	p = start;
	while (1)
	{
		put_pixel_mm(buf, p.x, p.y, color);
		if (p.x == end.x && p.y == end.y)
			break ;
		e2 = 2 * b.err;
		if (e2 >= b.dy)
		{
			b.err += b.dy;
			p.x += b.sx;
		}
		if (e2 <= b.dx)
		{
			b.err += b.dx;
			p.y += b.sy;
		}
	}
}

void	draw_mm_tile(t_img_buffer *buf, t_point origin, char c)
{
	int	color;

	if (c == '1')
		color = 0x00333333;
	else if (c == '0')
		color = 0x00BBBBBB;
	else
		color = 0x00000000;
	draw_square(buf, origin, MM_TILE, color);
}

void	draw_mm_grid(t_map *map, t_img_buffer *buf)
{
	t_point	p;
	t_point	origin;

	p.y = 0;
	while (map->grid[p.y] && MM_PAD + (p.y + 1) * MM_TILE < MM_MAX_H)
	{
		p.x = 0;
		while (map->grid[p.y][p.x] && MM_PAD + (p.x + 1) * MM_TILE < MM_MAX_W)
		{
			origin.x = MM_PAD + p.x * MM_TILE;
			origin.y = MM_PAD + p.y * MM_TILE;
			draw_mm_tile(buf, origin, map->grid[p.y][p.x]);
			p.x++;
		}
		p.y++;
	}
}

void	draw_mm_player(t_map *map, t_img_buffer *buf)
{
	t_point	px;
	t_point	end;
	t_point	top_left;

	px.x = MM_PAD + (int)(map->player.x * MM_TILE);
	px.y = MM_PAD + (int)(map->player.y * MM_TILE);
	top_left.x = px.x - 2;
	top_left.y = px.y - 2;
	draw_square(buf, top_left, 5, 0x00FF0000);
	end.x = px.x + (int)(map->player.dir_x * 10.0);
	end.y = px.y + (int)(map->player.dir_y * 10.0);
	draw_line(buf, px, end, 0x00FF0000);
}

void	draw_minimap(t_map *map, t_img_buffer *buf)
{
	if (!map || !map->grid || !buf || !buf->address)
		return ;
	draw_mm_grid(map, buf);
	draw_mm_player(map, buf);
}
