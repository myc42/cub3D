/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:16:21 by macoulib          #+#    #+#             */
/*   Updated: 2025/12/30 20:54:35 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_partial(char **tab, int n)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	init_map_header(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	clean_map_file_content(data);
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
			{
				free_partial(data->map_header, j);
				data->map_header = NULL;
				return (0);
			}
			j++;
		}
		i++;
	}
	data->map_header[j] = NULL;
	reorder_map_header(data);
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
		{
			free_partial(data->map, j);
			data->map = NULL;
			return (0);
		}
		i++;
		j++;
	}
	data->map[j] = NULL;
	data->map_height = j;
	if (!check_map_size(data->map))
		return (printf("map trop petite \n"),0);
	return (1);
}

int	is_id(char *s, char a, char b)
{
	if (!s || !s[0] || !s[1])
		return (0);
	if (s[0] != a)
		return (0);
	if (b == 0)
		return (1);
	if (s[1] != b)
		return (0);
	return (1);
}

int	check_duplicates(t_data *data)
{
	int	i;
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;

	i = 0;
	no = 0;
	so = 0;
	we = 0;
	ea = 0;
	f = 0;
	c = 0;
	while (data->map_header[i])
	{
		if (is_id(data->map_header[i], 'N', 'O'))
			no++;
		else if (is_id(data->map_header[i], 'S', 'O'))
			so++;
		else if (is_id(data->map_header[i], 'W', 'E'))
			we++;
		else if (is_id(data->map_header[i], 'E', 'A'))
			ea++;
		else if (is_id(data->map_header[i], 'F', 0))
			f++;
		else if (is_id(data->map_header[i], 'C', 0))
			c++;
		i++;
	}
	if (no > 1 || so > 1 || we > 1 || ea > 1 || f > 1 || c > 1)
		return (1);
	return (0);
}

int	map_management(t_data *data, char *av)
{
	data->color_floor = -1;
	data->color_cielling = -1;

	get_map(data, av);

	if (!find_map_start(data))
		return (printf("pas de map "), 0);
	if (!init_map_header(data))
		return (printf("probleme sur header de la map "), 0);
	if (check_duplicates(data))
		return (printf("duplicata dans le header "), 0);
	if (!init_map(data))
		return (printf("erreur dans la map"), 0);
	return (1);
}