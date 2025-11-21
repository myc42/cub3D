/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:45:59 by macoulib          #+#    #+#             */
/*   Updated: 2025/05/12 19:38:02 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t elementCount, size_t elementSize )
{
	void	*moncalloc;
	size_t	nbr;

	nbr = elementCount * elementSize;
	moncalloc = malloc(nbr);
	if (!moncalloc)
		return (NULL);
	ft_bzero(moncalloc, nbr);
	return (moncalloc);
}
