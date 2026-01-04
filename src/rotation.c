#include "../includes/cub3d.h"


int	mouse_move(int x, int y, t_map *map)
{
	int dx;
	double rot;

	(void)y;
	if (!map)
		return (0);
	if (map->mouse_warp)
		return (map->mouse_warp = 0, 0);
	if (!map->mouse_init)
	{
		map->mouse_init = 1;
		map->mouse_warp = 1;
		mlx_mouse_move(map->mlx, map->win, SCREEN_W / 2, SCREEN_H / 2);
		mlx_do_sync(map->mlx);
		return (0);
	}
	dx = x - (SCREEN_W / 2);
	if (dx != 0)
	{
		rot = (double)dx * map->mouse_sens;
		rotate_with_value(map, rot);
	}
	map->mouse_warp = 1;
	mlx_mouse_move(map->mlx, map->win, SCREEN_W / 2, SCREEN_H / 2);
	return (mlx_do_sync(map->mlx), 0);
}
