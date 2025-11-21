/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:52:36 by macoulib          #+#    #+#             */
/*   Updated: 2025/04/26 21:49:10 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	srclen;
	char	*srcpy;

	i = 0;
	srclen = ft_strlen(src);
	srcpy = malloc((srclen + 1) * sizeof(char));
	if (!srcpy)
		return (NULL);
	while (i < srclen)
	{
		srcpy[i] = src[i];
		i++;
	}
	srcpy[i] = '\0';
	return (srcpy);
}
