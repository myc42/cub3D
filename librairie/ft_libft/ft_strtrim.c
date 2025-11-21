/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:49:26 by macoulib          #+#    #+#             */
/*   Updated: 2025/05/13 18:21:24 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	starttrim(const char *s1, const char *set)
{
	int	found;
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s1[k])
	{
		found = 0 ;
		i = 0;
		while (set[i])
		{
			if (s1[k] == set[i])
			{
				found = 1;
				break ;
			}
			i++;
		}
		if (found == 1)
			k ++;
		else
			break ;
	}
	return (k);
}

int	endstrim(int end, const char *s1, const char *set)
{
	int	found;
	int	i;

	i = 0 ;
	while (end > 0)
	{
		found = 0;
		while (set[i])
		{
			if (s1[end - 1] == set[i])
			{
				found = 1;
				break ;
			}
			i ++;
		}
		if (found == 1)
		{
			end--;
			i = 0;
		}
		else
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		start;
	int		end;
	int		s1len;
	int		i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	s1len = ft_strlen(s1);
	start = starttrim(s1, set);
	end = endstrim(s1len, s1, set);
	if (start >= end)
		return (ft_strdup(""));
	strtrim = malloc(((end - start) + 1));
	if (!strtrim)
		return (NULL);
	while (start < end)
	{
		strtrim[i] = s1[start];
		i++;
		start ++;
	}
	strtrim[i] = '\0' ;
	return (strtrim);
}
/* int	main(void)
{
	char	*s1;
	char	*set;
	char	*result;

	s1 = "xxxz  test with x and z and x .  zx  xx z";
	set = "z x";
	result = ft_strtrim(s1, set);
	if (result)
	{
		printf("Original: '%s'\n", s1);
		printf("Trimmed: '%s'\n", result);
		free(result);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}
 */