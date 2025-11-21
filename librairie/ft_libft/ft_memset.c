/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:33:53 by macoulib          #+#    #+#             */
/*   Updated: 2025/04/24 21:02:05 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset( void *pointer, int value, size_t count )
{
	unsigned char	*pointercpy;
	size_t			i;

	i = 0;
	pointercpy = (unsigned char *) pointer;
	while (i < count)
	{
		pointercpy[i] = (unsigned char) value;
		i++;
	}
	return (pointer);
}
