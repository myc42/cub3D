/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:43:28 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/26 15:26:29 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_map	*map;

	data = NULL;
	map = NULL;
	data = ft_calloc(1, sizeof(t_data));
	map = ft_calloc(1, sizeof(t_map));
	if (!data || !map)
		return (printf("alloc data, map error  \n"), 0);
	if (!validate_args(ac, av))
		return (1);
	get_map(data, av[1]);
	if (!parsing(data, map))
		return (1);
	return (0);
}
