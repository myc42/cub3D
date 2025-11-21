/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:09:04 by macoulib          #+#    #+#             */
/*   Updated: 2025/05/13 15:33:47 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slen;

	slen = ft_strlen(s);
	while (slen >= 0)
	{
		if (s[slen] == (unsigned char)c)
			return ((char *)&s[slen]);
		slen--;
	}
	return (0);
}
/* 
#include <stdio.h>

int main(void)
{
	printf("%s", ft_strrchr("bonjour", 'j'));
}*/
