/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:27:04 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/04 15:20:20 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	texture_exists(t_data *data, int i)
{
	if (!ft_strncmp(data->map_header[i], "NO ", 3)
		|| !ft_strncmp(data->map_header[i], "SO ", 3)
		|| !ft_strncmp(data->map_header[i], "WE ", 3)
		|| !ft_strncmp(data->map_header[i], "EA ", 3))
		return (1);
	return (0);
}

char	*trim_end_spaces(char *str)
{
	int	end;

	end = ft_strlen(str) - 1;
	while (end >= 0 && ft_isspace((unsigned char)str[end]))
		end--;
	str[end + 1] = '\0';
	return (str);
}

int	stock_texture_path(t_data *data, int i)
{
	char	*line;
	int		j;
	char	*path;

	line = data->map_header[i];
	j = 2;
	if (!texture_exists(data, i))
		return (printf("texture incomplete  \n"), 0);
	while (line[j] && ft_isspace((unsigned char)line[j]))
		j++;
	path = trim_end_spaces(line + j);
	if (!path)
		return (printf("chemin xpm incorrect \n"), 0);
	if (!ft_strncmp(line, "NO", 2))
		data->wall_north = path;
	else if (!ft_strncmp(line, "SO", 2))
		data->wall_south = path;
	else if (!ft_strncmp(line, "WE", 2))
		data->wall_west = path;
	else if (!ft_strncmp(line, "EA", 2))
		data->wall_east = path;
	return (1);
}
