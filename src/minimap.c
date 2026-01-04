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

	if (!img || !img->address || x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->address + y * img->line_octet_length + x * (img->Bits_Per_Pixel / 8);
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
static void	init_bresen(t_bres *b, t_point start, t_point end)
{
	b->dx = ft_abs(end.x - start.x);
	b->dy = -ft_abs(end.y - start.y);
	b->sx = (start.x < end.x) ? 1 : -1;
	b->sy = (start.y < end.y) ? 1 : -1;
	b->err = b->dx + b->dy;
}

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
static void	draw_mm_tile(t_img_buffer *buf, t_point origin, char c)
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

static void	draw_mm_grid(t_map *map, t_img_buffer *buf)
{
	t_point	p;

	p.y = 0;
	while (map->grid[p.y] && MM_PAD + (p.y + 1) * MM_TILE < MM_MAX_H)
	{
		p.x = 0;
		while (map->grid[p.y][p.x] && MM_PAD + (p.x + 1) * MM_TILE < MM_MAX_W)
		{
			draw_mm_tile(buf, (t_point){MM_PAD + p.x * MM_TILE, MM_PAD + p.y * MM_TILE},
				map->grid[p.y][p.x]);
			p.x++;
		}
		p.y++;
	}
}

static void	draw_mm_player(t_map *map, t_img_buffer *buf)
{
	t_point	px;
	t_point	end;

	px.x = MM_PAD + (int)(map->player.x * MM_TILE);
	px.y = MM_PAD + (int)(map->player.y * MM_TILE);
	draw_square(buf, (t_point){px.x - 2, px.y - 2}, 5, 0x00FF0000);
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
