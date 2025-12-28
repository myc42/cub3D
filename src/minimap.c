#include "../includes/cub3d.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	put_pixel_mm(t_img_buffer *img, int x, int y, int color)
{
	char	*dst;

	if (!img || !img->address)
		return ;
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->address + (y * img->line_octet_length)
		+ (x * (img->Bits_Per_Pixel / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

void	draw_square(t_img_buffer *buf, int x0, int y0, int size, int color)
{
	int	y;
	int	x;

	if (!buf || !buf->address || size <= 0)
		return ;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			put_pixel_mm(buf, x0 + x, y0 + y, color);
			x++;
		}
		y++;
	}
}

void	init_bresenham(int x0, int y0, int x1, int y1, int *dx, int *dy,
		int *sx, int *sy, int *err)
{
	*dx = ft_abs(x1 - x0);
	*dy = -ft_abs(y1 - y0);
	if (x0 < x1)
		*sx = 1;
	else
		*sx = -1;
	if (y0 < y1)
		*sy = 1;
	else
		*sy = -1;
	*err = *dx + *dy;
}

void	draw_line(t_img_buffer *buf, int x0, int y0, int x1, int y1, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	if (!buf || !buf->address)
		return ;
	init_bresenham(x0, y0, x1, y1, &dx, &dy, &sx, &sy, &err);
	while (1)
	{
		put_pixel_mm(buf, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_minimap(t_map *map, t_img_buffer *buf)
{
	int	y;
	int	x;
	int	origin_x;
	int	origin_y;
	int	px;
	int	py;
	int	dx;
	int	dy;

	if (!map || !map->grid || !buf || !buf->address)
		return ;
	origin_x = MM_PAD;
	origin_y = MM_PAD;
	y = 0;
	while (map->grid[y] && (origin_y + (y + 1) * MM_TILE) < MM_MAX_H)
	{
		x = 0;
		while (map->grid[y][x] && (origin_x + (x + 1) * MM_TILE) < MM_MAX_W)
		{
			if (map->grid[y][x] == '1')
				draw_square(buf, origin_x + x * MM_TILE, origin_y + y * MM_TILE,
					MM_TILE, 0x00333333);
			else if (map->grid[y][x] == '0')
				draw_square(buf, origin_x + x * MM_TILE, origin_y + y * MM_TILE,
					MM_TILE, 0x00BBBBBB);
			else
				draw_square(buf, origin_x + x * MM_TILE, origin_y + y * MM_TILE,
					MM_TILE, 0x00000000);
			x++;
		}
		y++;
	}
	px = origin_x + (int)(map->player.x * MM_TILE);
	py = origin_y + (int)(map->player.y * MM_TILE);
	draw_square(buf, px - 2, py - 2, 5, 0x00FF0000);
	dx = px + (int)(map->player.dir_x * 10.0);
	dy = py + (int)(map->player.dir_y * 10.0);
	draw_line(buf, px, py, dx, dy, 0x00FF0000);
}
