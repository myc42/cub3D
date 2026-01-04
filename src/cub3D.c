/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:43:28 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/04 15:26:34 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_window_and_hooks(t_map *map)
{
	map->mouse_init = 0;
	map->mouse_warp = 0;
	map->mouse_sens = MOUSE_SENS;
	map->win = mlx_new_window(map->mlx, SCREEN_W, SCREEN_H,
			"Cub3D knehal -- macoulib");
	if (!map->win)
		return (exit_error(map, "mlx_new_window failed"));
	mlx_hook(map->win, 2, 1L << 0, key_press, map);
	mlx_hook(map->win, 3, 1L << 1, key_release, map);
	mlx_hook(map->win, 6, 1L << 6, mouse_move, map);
	mlx_hook(map->win, 17, 1L << 17, close_window, map);
	mlx_mouse_move(map->mlx, map->win, SCREEN_W / 2, SCREEN_H / 2);
	mlx_loop_hook(map->mlx, game_loop, map);
	return (1);
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_data	*data;


	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (1);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (free(map), 1);
	map->data = data;
	if (!validate_args(ac, av))
		return (exit_error(map, "bad arguments"));
	if (!parsing(data, map, av[1]))
		return (exit_error(map, ""));
	if (!init_window_and_hooks(map))
		return (1);
	mlx_loop(map->mlx);
	return (0);
}
