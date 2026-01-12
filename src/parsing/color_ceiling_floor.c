/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ceiling_floor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:56:12 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/04 15:56:13 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_color_values(char *s, int *color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	if (!parse_int_0_255(s, &i, &r))
		return (0);
	i = skip_spaces(s, i);
	if (s[i] != ',')
		return (0);
	i++;
	if (!parse_int_0_255(s, &i, &g))
		return (0);
	i = skip_spaces(s, i);
	if (s[i] != ',')
		return (0);
	i++;
	if (!parse_int_0_255(s, &i, &b))
		return (0);
	i = skip_spaces(s, i);
	if (s[i] && s[i] != '\n')
		return (0);
	*color = (r << 16) | (g << 8) | b;
	return (1);
}

int	parse_color_line(char *line, int *dst)
{
	int	i;

	if (!line || !line[0] || !line[1])
		return (0);
	if (line[0] != 'F' && line[0] != 'C')
		return (0);
	if (line[1] != ' ' && line[1] != '\t')
		return (0);
	i = 2;
	i = skip_spaces(line, i);
	return (parse_color_values(&line[i], dst));
}

int	color_ceiling_floor(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_header[i])
	{
		if (data->map_header[i][0] == 'F')
		{
			if (!parse_color_line(data->map_header[i], &data->color_floor))
				return (0);
		}
		else if (data->map_header[i][0] == 'C')
		{
			if (!parse_color_line(data->map_header[i], &data->color_cielling))
				return (0);
		}
		i++;
	}
	if (data->color_floor == -1 || data->color_cielling == -1)
		return (0);
	return (1);
}
