/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:50:28 by macoulib          #+#    #+#             */
/*   Updated: 2025/04/29 00:32:00 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	minmaj(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c);
	else
		return (c - 32);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*scpy;
	char	*ss;
	int		i;

	i = 0;
	ss = (char *)s;
	scpy = malloc((ft_strlen(s) + 1));
	if (!scpy)
	{
		return (NULL);
	}
	while (ss[i])
	{
		scpy[i] = f(i, ss[i]);
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}
