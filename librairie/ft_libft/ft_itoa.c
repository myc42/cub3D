/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 23:29:17 by macoulib          #+#    #+#             */
/*   Updated: 2025/05/12 19:33:01 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countlen(int n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	count;
	char	*dest_n;
	long	nb;

	count = ft_countlen(n);
	dest_n = (char *)malloc((count + 1));
	if (!dest_n)
		return (NULL);
	dest_n[count] = '\0';
	nb = n;
	if (nb < 0)
	{
		dest_n[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		dest_n[0] = '0';
	while (count-- > (n < 0))
	{
		dest_n[count] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (dest_n);
}

/* int	main(void)
{
	int		num;
	char	*str;

	num = -2147483648;
	str = ft_itoa(num);
	if (str)
	{
		printf("Integer: %d\n", num);
		printf("String: %s\n", str);
		free(str);
	}
	else
	{
		printf("Memory allocation failed\n");
	}
	return (0);
}
 */