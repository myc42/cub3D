/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:16:21 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/30 21:14:14 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_map_header(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!data->map_file_content || data->map_start <= 0)
		return (0);
	while (i < data->map_start)
	{
		if (!is_line_empty(data->map_file_content[i]))
			j++;
		i++;
	}
	data->map_header = malloc(sizeof(char *) * (j + 1));
	if (!data->map_header)
		return (0);
	i = 0;
	j = 0;
	while (i < data->map_start)
	{
		if (!is_line_empty(data->map_file_content[i]))
		{
			data->map_header[j] = ft_strdup(data->map_file_content[i]);
			if (!data->map_header[j])
				return (0);
			j++;
		}
		i++;
	}
	data->map_header[j] = NULL;
	return (1);
}

int	init_map(t_data *data)
{
	int	i;
	int	j;
	int	map_lines;

	i = data->map_start;
	j = 0;
	map_lines = 0;
	while (data->map_file_content[i])
	{
		map_lines++;
		i++;
	}
	data->map = malloc(sizeof(char *) * (map_lines + 1));
	if (!data->map)
		return (0);
	i = data->map_start;
	j = 0;
	while (data->map_file_content[i])
	{
		data->map[j] = ft_strdup(data->map_file_content[i]);
		if (!data->map[j])
			return (0);
		i++;
		j++;
	}
	data->map[j] = NULL;
	data->map_height = j;
	return (1);
}
int	check_duplicates(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_header[i])
	{
		j = i + 1;
		while (data->map_header[j])
		{
			if (ft_strcmp(data->map_header[j], data->map_header[i]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	map_management(t_data *data, char *av)
{
	get_map(data, av);
	if (!find_map_start(data))
		return (printf("pas de map "), 0);
	if (!init_map_header(data))
		return (printf("probleme sur header de la map "), 0);
	if (check_duplicates(data))
		return (printf("duplicata dans le header "), 0);
	if (!init_map(data))
		return (printf("votre map nexiste pas "), 0);
	return (1);
}