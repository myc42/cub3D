/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:06:13 by macoulib          #+#    #+#             */
/*   Updated: 2025/05/12 15:25:06 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	functioncentral(unsigned char *dstcpy, unsigned char *srccpy,
						size_t size)
{
	size_t	i;

	i = 0;
	while (size > i)
	{
		if (dstcpy > srccpy)
		{
			dstcpy[size -1] = srccpy[size -1];
			size --;
		}
		else
		{
			dstcpy[i] = srccpy[i];
			i++ ;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t size )
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	if (!dst && !src)
		return (NULL);
	dstcpy = (unsigned char *) dst;
	srccpy = (unsigned char *) src;
	functioncentral(dstcpy, srccpy, size);
	return (dstcpy);
}
