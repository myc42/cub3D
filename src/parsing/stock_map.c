/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:08:42 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/04 15:20:14 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	stock_map_infos(char *file, t_data *data)
{
	int		fd;
	char	*line;
	char	*trim;

	data->map_rows = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (write(2, "open map Error\n", 15), 0);
	data->map = malloc(sizeof(char *) * MAX_MAP_LINES);
	if (!data->map)
		return (write(2, "alloc Error\n", 12), close(fd), 0);
	line = get_next_line(fd);
	while (line)
	{
		trim = ft_strtrim(line, "\n");
		free(line);
		if (!trim)
			return (write(2, "trim Error\n", 11),
				data->map[data->map_rows] = NULL, free_tab(data->map),
				close(fd), 0);
		data->map[data->map_rows] = trim;
		data->map_rows++;
		if (data->map_rows >= MAX_MAP_LINES - 1)
			return (write(2, "Error: map too big\n", 20), free_tab(data->map),
				close(fd), 0);
		line = get_next_line(fd);
	}
	return (close(fd), data->map[data->map_rows] = NULL, 1);
}
