/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:49:54 by macoulib          #+#    #+#             */
/*   Updated: 2025/05/13 14:30:58 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*scpy;

	i = 0;
	if (!*s)
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	scpy = malloc((len + 1) * sizeof(char));
	if (!scpy)
		return (NULL);
	while (i < len)
	{
		scpy[i] = s[start];
		start ++;
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}
