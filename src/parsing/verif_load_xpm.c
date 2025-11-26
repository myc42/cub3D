/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_load_xpm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:03:32 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/26 18:18:36 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	has_xpm_extension(t_data *data)
{
	char	*paths[4] = {data->wall_north, data->wall_south, data->wall_west,
			data->wall_east};
	char	*path;
	int		i;
	int		len;

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
int	load_xpm(t_map *map, t_data *data)
{
	int				i;
	char			*paths[4] = {data->wall_north, data->wall_south,
					data->wall_west, data->wall_east};
	t_img_buffer	*buffers[4] = {&map->wall_north, &map->wall_south,
			&map->wall_west, &map->wall_east};

	i = 0;
	while (i < 4)
	{
		buffers[i]->img = mlx_xpm_file_to_image(map->mlx, paths[i],
				&buffers[i]->width, &buffers[i]->height);
		if (!buffers[i]->img)
			return (0);
		buffers[i]->address = mlx_get_data_addr(buffers[i]->img,
				&buffers[i]->Bits_Per_Pixel, &buffers[i]->line_octet_length,
				&buffers[i]->octet_order);
		i++;
	}
	return (1);
}

int	verif_load_xpm(t_data *data, t_map *map)
{
	int i;
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