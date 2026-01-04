/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:50:30 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/04 15:21:47 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_map_rectangular(t_data *data)
{
	size_t	first_len;

	if (!data->map || !data->map[0])
		return (ft_putstr_fd("Error : Empty map\n", 2), 0);
	first_len = ft_strlen(data->map[0]);
	if (first_len == 0)
		return (ft_putstr_fd("Error : Empty map line\n", 2), 1);
	return (1);
}

static int	is_closed_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_outline(t_data *data)
{
	int	i;
	int	last;

	if (!data->map || data->map_height <= 0)
		return (ft_putstr_fd("Error : Empty map\n", 2), 0);
	last = data->map_height - 1;
	if (!is_closed_line(data->map[0]))
		return (ft_putstr_fd("Error : First map line invalid\n", 2), 0);
	if (!is_closed_line(data->map[last]))
		return (ft_putstr_fd("Error : Last map line invalid\n", 2), 0);
	i = 1;
	while (i < last)
	{
		if (data->map[i][0] != '1' || data->map[i][ft_strlen(data->map[i])
			- 1] != '1')
			return (ft_putstr_fd("Error : Map must be enclosed by '1'\n", 2),
				0);
		i++;
	}
	return (1);
}

static int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_valid_char(char c)
{
	return (is_player(c) || c == '1' || c == '0' || c == ' ');
}

int	verif_map_element(t_data *data)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (is_player(data->map[i][j]))
				player++;
			else if (!is_valid_char(data->map[i][j]))
				return (printf("Erreur: caractère invalide dans la map.\n"), 1);
			j++;
		}
		i++;
	}
	if (player != 1)
		return (printf("Erreur: nombre de joueurs incorrect.\n"), 1);
	return (0);
}

int	verif_map(t_data *data)
{
	if (!check_map_rectangular(data))
		return (0);
	if (!check_map_outline(data))
		return (0);
	if (verif_map_element(data))
		return (0);
	return (1);
}