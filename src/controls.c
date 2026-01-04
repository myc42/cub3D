/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2026/01/03 19:01:12 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/03 19:01:12 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	key_press(int keycode, t_map *map)
{
	if (keycode == KEY_W)
		map->keys.w = 1;
	else if (keycode == KEY_S)
		map->keys.s = 1;
	else if (keycode == KEY_A)
		map->keys.a = 1;
	else if (keycode == KEY_D)
		map->keys.d = 1;
	else if (keycode == KEY_LEFT)
		map->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		map->keys.right = 1;
	else if (keycode == KEY_ESC)
		close_window(map);
	return (0);
}

int	key_release(int keycode, t_map *map)
{
	if (keycode == KEY_W)
		map->keys.w = 0;
	else if (keycode == KEY_S)
		map->keys.s = 0;
	else if (keycode == KEY_A)
		map->keys.a = 0;
	else if (keycode == KEY_D)
		map->keys.d = 0;
	else if (keycode == KEY_LEFT)
		map->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		map->keys.right = 0;
	return (0);
}

int	close_window(t_map *map)
{
	cleanup_all(map);
	exit(0);
	return (0);
}
