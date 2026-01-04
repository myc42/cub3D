/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:16:21 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/04 15:29:49 by macoulib         ###   ########.fr       */
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

void	init_ij(int *i, int *j)
{
	*i = -1;
	*j = 0;
}

int	init_map_header(t_data *data)
{
	int	i;
	int	j;

	init_ij(&i, &j);
	while (++i < data->map_start)
	{
		if (!is_line_empty(data->map_file_content[i]))
			j++;
	}
	data->map_header = malloc(sizeof(char *) * (j + 1));
	if (!data->map_header)
		return (0);
	init_ij(&i, &j);
	while (++i < data->map_start)
	{
		if (!is_line_empty(data->map_file_content[i]))
		{
			data->map_header[j] = ft_strdup(data->map_file_content[i]);
			if (!data->map_header[j])
				return (free_partial(data->map_header, j),
					data->map_header = NULL, 0);
			j++;
		}
	}
	return (data->map_header[j] = NULL, reorder_map_header(data), 1);
}

void	init_ij_mapline(t_data *data, int *i, int *j, int *mapline)
{
	*i = data->map_start;
	*j = 0;
	*mapline = 0;
	while (data->map_file_content[*i])
	{
		(*mapline)++;
		(*i)++;
	}
}

int	init_map(t_data *data)
{
	int	i;
	int	j;
	int	map_lines;

	init_ij_mapline(data, &i, &j, &map_lines);
	data->map = malloc(sizeof(char *) * (map_lines + 1));
	if (!data->map)
		return (0);
	i = data->map_start;
	j = 0;
	while (data->map_file_content[i])
	{
		data->map[j] = ft_strdup(data->map_file_content[i]);
		if (!data->map[j])
			return (free_partial(data->map, j), data->map = NULL, 0);
		i++;
		j++;
	}
	data->map[j] = NULL;
	data->map_height = j;
	if (!check_map_size(data->map))
		return (printf("erreur ligne map  \n"), 0);
	if (!is_closed_map(data))
		return (0);
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

// int (x), (y) = -1;

void	init_point(t_pointcardinaux *p)
{
	p->no = 0;
	p->so = 0;
	p->we = 0;
	p->ea = 0;
	p->f = 0;
	p->c = 0;
}

int	check_duplicates(t_data *data)
{
	int					i;
	t_pointcardinaux	point;

	i = 0;
	init_point(&point);
	while (data->map_header[i])
	{
		if (is_id(data->map_header[i], 'N', 'O'))
			point.no++;
		else if (is_id(data->map_header[i], 'S', 'O'))
			point.so++;
		else if (is_id(data->map_header[i], 'W', 'E'))
			point.we++;
		else if (is_id(data->map_header[i], 'E', 'A'))
			point.ea++;
		else if (is_id(data->map_header[i], 'F', 0))
			point.f++;
		else if (is_id(data->map_header[i], 'C', 0))
			point.c++;
		i++;
	}
	if (point.no > 1 || point.so > 1 || point.we > 1 || point.ea > 1
		|| point.f > 1 || point.c > 1)
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
	if (!clean_map_file_content(data))
		return (0);
	if (!init_map_header(data))
		return (printf("probleme sur header de la map "), 0);
	if (check_duplicates(data))
		return (printf("duplicata dans le header "), 0);
	if (!init_map(data))
		return (printf("erreur dans la map"), 0);
	return (1);
}
