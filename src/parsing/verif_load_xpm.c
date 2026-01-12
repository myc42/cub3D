/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_load_xpm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knehal <knehal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:03:32 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/09 19:19:01 by knehal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	has_xpm_extension(t_data *data)
{
	char	*paths[4];
	char	*path;
	int		i;
	int		len;

	paths[0] = data->wall_north;
	paths[1] = data->wall_south;
	paths[2] = data->wall_west;
	paths[3] = data->wall_east;
	i = 0;
	while (i < 4)
	{
		path = paths[i];
		if (!path)
			return (0);
		len = ft_strlen(path);
		if (len < 4)
			return (0);
		if (ft_strcmp(path + len - 4, ".xpm") != 0)
			return (0);
		i++;
	}
	return (1);
}

void	destroy_loaded_textures(t_map *map, t_img_buffer **buffers,
		int last)
{
	while (last >= 0)
	{
		if (buffers[last]->img)
		{
			mlx_destroy_image(map->mlx, buffers[last]->img);
			buffers[last]->img = NULL;
		}
		buffers[last]->address = NULL;
		last--;
	}
}

void	init_texture_arrays(t_map *map, t_data *data, char **paths,
		t_img_buffer **buffers)
{
	paths[0] = data->wall_north;
	paths[1] = data->wall_south;
	paths[2] = data->wall_west;
	paths[3] = data->wall_east;
	buffers[0] = &map->wall_north;
	buffers[1] = &map->wall_south;
	buffers[2] = &map->wall_west;
	buffers[3] = &map->wall_east;
}

int	load_xpm(t_map *map, t_data *data)
{
	int				i;
	char			*paths[4];
	t_img_buffer	*buffers[4];

	init_texture_arrays(map, data, paths, buffers);
	if (!map || !map->mlx)
		return (printf("Error: mlx not initialized\n"), 0);
	i = 0;
	while (i < 4)
	{
		buffers[i]->img = mlx_xpm_file_to_image(map->mlx, paths[i],
				&buffers[i]->width, &buffers[i]->height);
		if (!buffers[i]->img)
			return (destroy_loaded_textures(map, buffers, i - 1), 0);
		buffers[i]->address = mlx_get_data_addr(buffers[i]->img,
				&buffers[i]->bits_per_pixel, &buffers[i]->line_octet_length,
				&buffers[i]->octet_order);
		if (!buffers[i]->address)
			return (mlx_destroy_image(map->mlx, buffers[i]->img),
				buffers[i]->img = NULL, destroy_loaded_textures(map, buffers, i
					- 1), 0);
		i++;
	}
	return (1);
}

int	verif_load_xpm(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!stock_texture_path(data, i))
			return (0);
		i++;
	}
	if (!has_xpm_extension(data))
		return (printf("xpm paths error \n"), 0);
	if (!load_xpm(map, data))
		return (printf(" xpm load error \n"), 0);
	return (1);
}
