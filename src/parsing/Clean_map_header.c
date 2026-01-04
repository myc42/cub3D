/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Clean_map_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 01:47:52 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/04 14:35:34 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*trim_start_spaces(char *str)
{
	int		start;
	int		end;
	char	*trimmed_str;

	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] && ft_isspace((unsigned char)str[start]))
		start++;
	while (end >= start && ft_isspace((unsigned char)str[end]))
		end--;
	trimmed_str = ft_substr(str, start, end - start + 1);
	return (trimmed_str);
}

int	clean_map_file_content(t_data *data)
{
	int		i;
	char	*cleaned;

	i = 0;
	if (!data->map_file_content || data->map_start <= 0)
		return (0);
	while (data->map_file_content[i])
	{
		cleaned = trim_start_spaces(data->map_file_content[i]);
		if (!cleaned)
			return (0);
		free(data->map_file_content[i]);
		data->map_file_content[i] = cleaned;
		i++;
	}
	return (1);
}

static void	handle_fc_and_copy(t_data *data, char **new_header, int j)
{
	int	i;

	i = 0;
	while (data->map_header[i])
	{
		if (!ft_strncmp(data->map_header[i], "F ", 2)
			|| !ft_strncmp(data->map_header[i], "C ", 2))
		{
			new_header[j++] = data->map_header[i];
		}
		i++;
	}
	new_header[j] = NULL;
	i = 0;
	while (new_header[i])
	{
		data->map_header[i] = new_header[i];
		i++;
	}
	data->map_header[i] = NULL;
}

int	reorder_map_header(t_data *data)
{
	char	*new_header[8];
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (data->map_header[i])
	{
		if (!ft_strncmp(data->map_header[i], "NO ", 3)
			|| !ft_strncmp(data->map_header[i], "SO ", 3)
			|| !ft_strncmp(data->map_header[i], "WE ", 3)
			|| !ft_strncmp(data->map_header[i], "EA ", 3))
		{
			new_header[j++] = data->map_header[i];
		}
		i++;
	}
	i = 0;
	handle_fc_and_copy(data, new_header, j);
	return (1);
}

#include <stdlib.h>

int	check_map_size(char **map)
{
	int	i;
	int	height;
	int	width;

	if (!map)
		return (0);
	height = 0;
	while (map[height])
		height++;
	if (height < 3)
		return (0);
	i = 0;
	while (map[i])
	{
		width = 0;
		while (map[i][width])
			width++;
		if (width < 3)
			return (0);
		i++;
	}
	return (1);
}
