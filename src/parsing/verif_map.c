/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:50:30 by macoulib          #+#    #+#             */
/*   Updated: 2025/12/28 17:19:23 by macoulib         ###   ########.fr       */
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
int	check_map_outline(t_data *data)
{
	int		i;
	char	*line;
	int		last_index;

	if (!data->map || data->map_height <= 0)
		return (ft_putstr_fd("Error : Empty map\n", 2), 0);
	last_index = data->map_height - 1;
	line = data->map[0];
	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (ft_putstr_fd("Error : First map line must be all '1'\n", 2),
				0);
		i++;
	}
	line = data->map[last_index];
	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (ft_putstr_fd("Error : Last map line must be all '1' or space\n", 2),
				0);
		i++;
	}
	i = 1;
	while (i < last_index)
	{
		line = data->map[i];
		if ((line[0] != '1' && line[i] != ' ' ) && (line[ft_strlen(line) - 1] != '1'
			&& line[ft_strlen(line) - 1] != '1' ))
			return (ft_putstr_fd("Error : Map must be enclosed by '1'\n", 2),
				0);
		i++;
	}
	return (1);
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