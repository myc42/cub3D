#include "../includes/cub3d.h"


void	put_pixel(t_img_buffer *img, int x, int y, int color)
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
	dst = tex->address + (y * tex->line_octet_length)
		+ (x * (tex->Bits_Per_Pixel / 8));
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

void	init_dda(t_map *map, t_ray *r)
{
	if (r->ray_dir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1.0 / r->ray_dir_x);
	if (r->ray_dir_y == 0)
		r->delta_dist_y = 1e30;
	else
		r->delta_dist_y = fabs(1.0 / r->ray_dir_y);
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (map->player.x - (double)r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = ((double)r->map_x + 1.0 - map->player.x) * r->delta_dist_x;
	}
}

void	init_dda_y(t_map *map, t_ray *r)
{
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (map->player.y - (double)r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = ((double)r->map_y + 1.0 - map->player.y) * r->delta_dist_y;
	}
}

void	do_dda(t_map *map, t_ray *r, int map_h)
{
	while (!r->hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (is_wall_cell(map, map_h, r->map_y, r->map_x))
			r->hit = 1;
	}
}

void	compute_projection(t_ray *r)
{
	if (r->side == 0)
		r->perp_wall_dist = r->side_dist_x - r->delta_dist_x;
	else
		r->perp_wall_dist = r->side_dist_y - r->delta_dist_y;
	r->line_height = 0;
	if (r->perp_wall_dist > 0.0001 && r->perp_wall_dist < 1e29)
		r->line_height = (int)((double)SCREEN_H / r->perp_wall_dist);
	r->draw_start = (-r->line_height / 2) + (SCREEN_H / 2);
	r->draw_end = (r->line_height / 2) + (SCREEN_H / 2);
	if (r->draw_start < 0)
		r->draw_start = 0;
	if (r->draw_end >= SCREEN_H)
		r->draw_end = SCREEN_H - 1;
}

void	select_texture(t_map *map, t_ray *r)
{
	if (r->side == 0)
	{
		if (r->ray_dir_x > 0)
			r->tex = &map->wall_east;
		else
			r->tex = &map->wall_west;
	}
	else
	{
		if (r->ray_dir_y > 0)
			r->tex = &map->wall_south;
		else
			r->tex = &map->wall_north;
	}
}

void	compute_texture_coords(t_map *map, t_ray *r)
{
	double	wall_x;

	r->tex_x = 0;
	r->step = 0.0;
	r->tex_pos = 0.0;
	if (!r->tex || r->line_height <= 0 || r->tex->width <= 0 || r->tex->height <= 0)
		return ;
	if (r->side == 0)
		wall_x = map->player.y + r->perp_wall_dist * r->ray_dir_y;
	else
		wall_x = map->player.x + r->perp_wall_dist * r->ray_dir_x;
	wall_x -= floor(wall_x);
	r->tex_x = (int)(wall_x * (double)r->tex->width);
	if (r->side == 0 && r->ray_dir_x < 0)
		r->tex_x = r->tex->width - r->tex_x - 1;
	if (r->side == 1 && r->ray_dir_y > 0)
		r->tex_x = r->tex->width - r->tex_x - 1;
	r->step = (double)r->tex->height / (double)r->line_height;
	r->tex_pos = (r->draw_start - (SCREEN_H / 2) + (r->line_height / 2)) * r->step;
}

void	draw_column(t_map *map, t_img_buffer *buf, t_ray *r, int x)
{
	int	y;

	y = 0;
	while (y < SCREEN_H)
	{
		if (y < r->draw_start)
			put_pixel(buf, x, y, map->ceiling_color);
		else if (y > r->draw_end)
			put_pixel(buf, x, y, map->floor_color);
		else if (r->tex && r->tex->address && r->line_height > 0)
		{
			put_pixel(buf, x, y, (int)get_texel(r->tex, r->tex_x, (int)r->tex_pos));
			r->tex_pos += r->step;
		}
		else
			put_pixel(buf, x, y, 0);
		y++;
	}
}

void	render_frame(t_map *map)
{
	t_img_buffer	*buf;
	t_ray			r;
	int				map_h;
	int				map_w;
	int				x;

	if (!map || !map->grid)
		return ;
	buf = &map->buffer[map->current];
	if (!buf->img || !buf->address)
		return ;
	if (!get_map_size(map, &map_h, &map_w))
		return ;
	x = 0;
	while (x < SCREEN_W)
	{
		init_ray(map, &r, x);
		init_dda(map, &r);
		init_dda_y(map, &r);
		do_dda(map, &r, map_h);
		compute_projection(&r);
		select_texture(map, &r);
		compute_texture_coords(map, &r);
		draw_column(map, buf, &r, x);
		x++;
	}
	draw_minimap(map, buf);
	mlx_put_image_to_window(map->mlx, map->win, buf->img, 0, 0);
	map->current = 1 - map->current;
}
