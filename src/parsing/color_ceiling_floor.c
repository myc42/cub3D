/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ceiling_floor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:11:32 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/30 18:31:39 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_color_line(char *line)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	if (line[0] != 'F' && line[0] != 'C')
		return (0);
	if (line[1] != ' ')
		return (0);
	if (!line[2])
		return (0);
	i = 2;
	while (line[i])
	{
		if (line[i] == ',')
		{
			comma_count++;
			if (line[i + 1] == ',')
				return (0);
		}
		else if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (comma_count == 2);
}

int	create_color(int r, int g, int b)
{
	int	color;

	color = 0;
	color += r * 256 * 256;
	color += g * 256;
	color += b;
	return (color);
}

int	parse_color_line(char *line, int *color)
{
	char	**split_space;
	char	**rgb_tab;
	int		r;
	int		g;
	int		b;

	if (!is_valid_color_line(line))
		return (printf("Invalid color format"), 0);
	split_space = ft_split(line, ' ');
	if (!split_space || !split_space[0] || !split_space[1])
	{
		free_tab(split_space);
		return (0);
	}
	rgb_tab = ft_split(split_space[1], ',');
	if (!rgb_tab || !rgb_tab[0] || !rgb_tab[1] || !rgb_tab[2])
	{
		free_tab(split_space);
		return (0);
	}
	r = ft_atoi(rgb_tab[0]);
	g = ft_atoi(rgb_tab[1]);
	b = ft_atoi(rgb_tab[2]);
	free_tab(split_space);
	free_tab(rgb_tab);
	if (r == -1 || g == -1 || b == -1)
	{
		free_tab(split_space);
		return (0);
	}
	*color = create_color(r, g, b);
	return (1);
}

int	color_ceiling_floor(t_data *data)
{
	int i;

	i = 0;
	while (data->map_header[i])
	{
		if (data->map_header[i][0] == 'F')
		{
			if (!parse_color_line(data->map_header[i], &data->color_floor))
				return (printf("Invalid floor color format"), 0);
		}
		if (data->map_header[i][0] == 'C')
		{
			if (!parse_color_line(data->map_header[i], &data->color_cielling))
				return (printf("Invalid cielling color format"), 0);
		}
		i++;
	}
	return (1);
}