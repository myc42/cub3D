#include "cub3d.h"

int	is_wall(t_map *map, double y, double x)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)x;
	grid_y = (int)y;
	if (grid_x < 0 || grid_x >= map->width)
		return (1);
	if (grid_y < 0 || grid_y >= map->height)
		return (1);
	if (map->grid[grid_y][grid_x] != '0')
		return (1);
	return (0);
}

void	move_forward_backward(t_map *map)
{
	double	new_x;
	double	new_y;

	if (map->keys.w)
	{
		new_x = map->player.x + map->player.dir_x * MOVE_SPEED;
		new_y = map->player.y + map->player.dir_y * MOVE_SPEED;
		if (!is_wall(map, map->player.y, new_x))
			map->player.x = new_x;
		if (!is_wall(map, new_y, map->player.x))
			map->player.y = new_y;
	}
	if (map->keys.s)
	{
		new_x = map->player.x - map->player.dir_x * MOVE_SPEED;
		new_y = map->player.y - map->player.dir_y * MOVE_SPEED;
		if (!is_wall(map, map->player.y, new_x))
			map->player.x = new_x;
		if (!is_wall(map, new_y, map->player.x))
			map->player.y = new_y;
	}
}

void	move_left_right(t_map *map)
{
	double	perp_x;
	double	perp_y;
	double	new_x;
	double	new_y;

	perp_x = -map->player.dir_y;
	perp_y = map->player.dir_x;
	if (map->keys.a)
	{
		new_x = map->player.x - perp_x * MOVE_SPEED;
		new_y = map->player.y - perp_y * MOVE_SPEED;
		if (!is_wall(map, map->player.y, new_x))
			map->player.x = new_x;
		if (!is_wall(map, new_y, map->player.x))
			map->player.y = new_y;
	}
	if (map->keys.d)
	{
		new_x = map->player.x + perp_x * MOVE_SPEED;
		new_y = map->player.y + perp_y * MOVE_SPEED;
		if (!is_wall(map, map->player.y, new_x))
			map->player.x = new_x;
		if (!is_wall(map, new_y, map->player.x))
			map->player.y = new_y;
	}
}

void	rotate_with_value(t_map *map, double rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = map->player.dir_x;
	old_plane_x = map->player.plane_x;

	map->player.dir_x = map->player.dir_x * cos(rot)
		- map->player.dir_y * sin(rot);
	map->player.dir_y = old_dir_x * sin(rot)
		+ map->player.dir_y * cos(rot);

	map->player.plane_x = map->player.plane_x * cos(rot)
		- map->player.plane_y * sin(rot);
	map->player.plane_y = old_plane_x * sin(rot)
		+ map->player.plane_y * cos(rot);
}

void	rotate_player(t_map *map)
{
	if (map->keys.left)
		rotate_with_value(map, -ROT_SPEED);
	if (map->keys.right)
		rotate_with_value(map, ROT_SPEED);
}


void	update_player(t_map *map)
{
	move_forward_backward(map);
	move_left_right(map);
	rotate_player(map);
}

int	game_loop(t_map *map)
{
	update_player(map);
	render_frame(map);

	return (0);
}
