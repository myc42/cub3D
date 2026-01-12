/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:46:57 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/04 17:53:13 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		r->side_dist_x = ((double)r->map_x + 1.0 - map->player.x)
			* r->delta_dist_x;
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
		r->side_dist_y = ((double)r->map_y + 1.0 - map->player.y)
			* r->delta_dist_y;
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
