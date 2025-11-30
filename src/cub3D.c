/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:43:28 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/30 19:09:45 by macoulib         ###   ########.fr       */
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
	if (!parsing(data, map, av[1]))
		return (1);
	map->win = mlx_new_window(map->mlx, 640, 480, "Cub3D knehal -- macoulib");
	mlx_loop(map->mlx);
	return (0);
}
