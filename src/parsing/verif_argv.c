/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:39:39 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/15 21:11:00 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_args(int argc, char **argv)
{
	char	*arg;
	int		len;

	if (argc != 2)
		return (printf("Error :\n  Invalid arguments .\n"), 0);
	arg = argv[1];
	len = ft_strlen(arg);
	if (ft_strcmp(arg + (int)len - 4, ".cub") != 0)
		return (printf("Error :\n  You must input a .cub file.\n"), 0);
	return (1);
}

int	is_invalid_border(t_data *data, int x, int y)
{
	if (data->map[y][x] == '0' && (y == 0 || y == data->map_height - 1))
		return (0);
	if (data->map[y][x] == '0' && (x == 0 || data->map[y][x + 1] == '\0'))
		return (printf("map border erreur"), 0);
	return (1);
}

int	checkeursx(t_data *data, int y, int x, int width)
{
	if (y > 0 && x > 0 && ftx(data->map[y - 1][x - 1]))
		return (0);
	if (y > 0 && ftx(data->map[y - 1][x]))
		return (0);
	if (y > 0 && x < width - 1 && ftx(data->map[y - 1][x + 1]))
		return (0);
	if (x > 0 && ftx(data->map[y][x - 1]))
		return (0);
	if (x < width - 1 && ftx(data->map[y][x + 1]))
		return (0);
	if (y < data->map_height - 1 && x > 0 && ftx(data->map[y + 1][x - 1]))
		return (0);
	if (y < data->map_height - 1 && ftx(data->map[y + 1][x]))
		return (0);
	if (y < data->map_height - 1 && x < width - 1 && ftx(data->map[y + 1][x
			+ 1]))
		return (0);
	return (1);
}
