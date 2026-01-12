/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:59:55 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/12 15:53:41 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_point(t_pointcardinaux *p)
{
	p->no = 0;
	p->so = 0;
	p->we = 0;
	p->ea = 0;
	p->f = 0;
	p->c = 0;
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

int	check_map_rectangular(t_data *data)
{
	size_t	first_len;

	if (!data->map || !data->map[0])
		return (ft_putstr_fd("Error :\n  Empty map\n", 2), 0);
	first_len = ft_strlen(data->map[0]);
	if (first_len == 0)
		return (ft_putstr_fd("Error :\n  Empty map line\n", 2), 1);
	return (1);
}

int	is_closed_line(char *line)
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

void	init_bresen(t_bres *b, t_point start, t_point end)
{
	b->dx = ft_abs(end.x - start.x);
	b->dy = -ft_abs(end.y - start.y);
	if (start.x < end.x)
	{
		b->sx = 1;
	}
	else
	{
		b->sx = -1;
	}
	if (start.y < end.y)
	{
		b->sy = 1;
	}
	else
	{
		b->sy = -1;
	}
	b->err = b->dx + b->dy;
}
