/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:50:30 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/21 18:09:46 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_map_rectangular(t_data *data)
{
	int		i;
	size_t	len;
	size_t	first_len;

	first_len = ft_strlen(data->map[data->index_start]);
	if (first_len == 0)
		return (ft_putstr_fd("Error : Empty map line\n", 2), 1);
	i = data->index_start;
	while (i <= data->index_end)
	{
		len = ft_strlen(data->map[i]);
		if (len != first_len)
			return (ft_putstr_fd("Error : Map must be rectangular\n", 2), 1);
		i++;
	}
	return (0);
}

int	check_map_outline(t_data *data)
{
	int		i;
	char	*line;

	line = data->map[data->index_start];
	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (ft_putstr_fd("Error : First map line  '1'\n", 2), 1);
		i++;
	}
	i = 0;
	line = data->map[data->index_end];
	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (ft_putstr_fd("Error : First map line  '1'\n", 2), 1);
		i++;
	}
	while (i < data->index_end)
	{
		line = data->map[i];
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			return (ft_putstr_fd("Error : Map must be enclosed '1'\n", 2), 1);
		i++;
	}
	return (0);
}

int	verif_map_element(t_data *data)
{
	int		invalid;
	int		player_count;
	char	c;
	int		i;
	int		j;

	invalid = 0;
	player_count = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			c = data->map[i][j];
			if (c == 'E' || c == 'W' || c == 'S' || c == 'N')
				player_count++;
			if (c != 'E' && c != 'W' && c != 'S' && c != 'N' && c != '1'
				&& c != '0' && c != ' ')
				invalid = 1;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (printf("Erreur: nombre de joueurs incorrect.\n"), 1);
	if (invalid)
		return (printf("Erreur: caractère invalide dans la map.\n"), 1);
	return (0);
}
