/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:29:01 by macoulib          #+#    #+#             */
/*   Updated: 2025/05/12 16:31:49 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scpy;
	int				i;
	int				j;

	j = (int)n;
	i = 0;
	scpy = (unsigned char *)s;
	while (i < j)
	{
		if (scpy[i] == (unsigned char)c)
		{
			return (&scpy[i]);
		}
		i ++;
	}
	return (NULL);
}
