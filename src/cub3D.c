/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:43:28 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/25 19:22:09 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data *data = NULL;

	if (!validate_args(ac, av))
		return (1);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	get_map(data, av[1]);
	if (!parsing(data))
		return (1);
	return (0);
}