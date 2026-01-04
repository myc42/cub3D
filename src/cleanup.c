/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2026/01/03 19:01:25 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/03 19:01:25 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	destroy_img(void *mlx, t_img_buffer *img)
{
	if (mlx && img && img->img)
	{
		mlx_destroy_image(mlx, img->img);
		img->img = NULL;
	}
}

void	free_data(t_data *d)
{
	if (!d)
		return ;
	free_tab(d->map_file_content);
	free_tab(d->map_header);
	free_tab(d->map);
}

void	cleanup_all(t_map *map)
{
	t_data *d;

	if (!map)
		return ;
	d = map->data;

	destroy_img(map->mlx, &map->wall_north);
	destroy_img(map->mlx, &map->wall_south);
	destroy_img(map->mlx, &map->wall_west);
	destroy_img(map->mlx, &map->wall_east);
	destroy_img(map->mlx, &map->buffer[0]);
	destroy_img(map->mlx, &map->buffer[1]);

	if (map->mlx && map->win)
	{
		mlx_destroy_window(map->mlx, map->win);
		map->win = NULL;
	}
	if (map->mlx)
		mlx_destroy_display(map->mlx);
	if (map->mlx)
		free(map->mlx);
	free_data(d);
	free(d);
	free(map);
}

int	exit_error(t_map *map, const char *msg)
{
	if (msg)
	{
		write(2, "Error\n", 6);
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	cleanup_all(map);
	return (1);
}
