/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:44:29 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/12 15:53:18 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
	{
		return (1);
	}
	return (0);
}

int	ftx(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
	{
		return (1);
	}
	return (0);
}

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_closed_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (!is_invalid_border(data, x, y))
				return (0);
			if (data->map[y][x] == '0')
			{
				if (ftx(data->map[y - 1][x - 1]) || ftx(data->map[y - 1][x])
					|| ftx(data->map[y - 1][x + 1]) || ftx(data->map[y][x - 1])
					|| ftx(data->map[y][x + 1]) || ftx(data->map[y + 1][x - 1])
					|| ftx(data->map[y + 1][x]) || ftx(data->map[y + 1][x + 1]))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
