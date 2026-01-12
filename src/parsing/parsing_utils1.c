/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:55:06 by macoulib          #+#    #+#             */
/*   Updated: 2026/01/09 20:34:10 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

int	skip_spaces(char *s, int i)
{
	while (s[i] && is_space(s[i]))
		i++;
	return (i);
}

int	parse_int_0_255(char *s, int *i, int *out)
{
	int	val;

	*i = skip_spaces(s, *i);
	if (!s[*i] || !ft_isdigit(s[*i]))
		return (0);
	val = 0;
	while (s[*i] && ft_isdigit(s[*i]))
	{
		val = val * 10 + (s[*i] - '0');
		(*i)++;
		if (val > 255)
			return (printf("color map incorrect \n"), 0);
	}
	*out = val;
	return (1);
}

void	free_partial(char **tab, int n)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	init_ij(int *i, int *j)
{
	*i = -1;
	*j = 0;
}
