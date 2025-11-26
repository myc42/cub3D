/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:24:39 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/26 15:20:16 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_data(t_data *data, t_map *map)
{
	data = ft_calloc(1, sizeof(t_data));
	map = ft_calloc(1, sizeof(t_map));
	if (!data || !map)
		return (printf("alloc data, map error  \n"), 0);
	return (1);
}