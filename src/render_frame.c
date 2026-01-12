/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 19:17:51 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/04 19:17:51 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	compute_texture_coords(t_map *map, t_ray *r)
{
	double	wall_x;

	r->tex_x = 0;
	r->step = 0.0;
	r->tex_pos = 0.0;
	if (!r->tex || r->line_height <= 0 || r->tex->width <= 0
		|| r->tex->height <= 0)
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
	r->tex_pos = (r->draw_start - (SCREEN_H / 2) + (r->line_height / 2))
		* r->step;
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
			put_pixel(buf, x, y, (int)get_texel(r->tex, r->tex_x,
					(int)r->tex_pos));
			r->tex_pos += r->step;
		}
		else
			put_pixel(buf, x, y, 0);
		y++;
	}
}

void	render_fame2(t_img_buffer *buf, t_map *map)
{
	draw_minimap(map, buf);
	mlx_put_image_to_window(map->mlx, map->win, buf->img, 0, 0);
	map->current = 1 - map->current;
}

void	render_frame(t_map *map)
{
	t_img_buffer	*buf;
	t_ray			r;
	int				map_h;
	int				map_w;
	int				x;

	buf = &map->buffer[map->current];
	if (!buf->img || !buf->address || !map || !map->grid)
		return ;
	if (!get_map_size(map, &map_h, &map_w))
		return ;
	x = -1;
	while (x++ < SCREEN_W)
	{
		init_ray(map, &r, x);
		init_dda(map, &r);
		init_dda_y(map, &r);
		do_dda(map, &r, map_h);
		compute_projection(&r);
		select_texture(map, &r);
		compute_texture_coords(map, &r);
		draw_column(map, buf, &r, x);
	}
	render_fame2(buf, map);
}
