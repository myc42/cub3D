/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:44:26 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/30 18:26:59 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parsing(t_data *data, t_map *map, char *av)
{
	if (!map_management(data, av))
		return (0);
	if (!verif_map(data))
		return (0);
	if (!initialize_mlx(map))
		return (0);
	if (!verif_load_xpm(data, map))
		return (0);
	if (!color_ceiling_floor(data))
		return (0);
	position_player(map, data);
	return (1);
}
