/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:39:39 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/25 18:33:29 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
int	validate_args(int argc, char **argv)
{
	char *arg;
	int len;
	(void)argc;

	if (argc != 2)
		return (printf("❌ Error : Invalid arguments .\n"), 0);
	arg = argv[1];
	len = ft_strlen(arg);
	if (ft_strcmp(arg + (int)len - 4, ".cub") != 0)
		return (printf("❌ Error : You must input a .cub file.\n"), 0);

	return (1);
}