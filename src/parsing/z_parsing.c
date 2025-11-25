/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:44:26 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/25 19:07:13 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parsing(t_data *data)
{
	if (check_map_rectangular(data))
		return (0);
	if (check_map_outline(data))
		return (0);
	if (verif_map_element(data))
		return (0);
	return (1);
}