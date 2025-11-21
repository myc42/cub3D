/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:52:08 by macoulib          #+#    #+#             */
/*   Updated: 2025/09/16 12:59:02 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	nbr_word(const char *s, char c)
{
	size_t	i;
	size_t	is_word;
	size_t	nbrword;

	i = 0;
	nbrword = 0;
	is_word = 0;
	while (s[i])
	{
		if (s[i] != c && is_word == 0)
		{
			is_word = 1;
			nbrword++;
		}
		else if (s[i] == c)
		{
			is_word = 0;
		}
		i++;
	}
	return (nbrword);
}

size_t	alloc_bloc(const char *s, char c, size_t nbrword, char **tabword)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (i < nbrword)
	{
		k = 0;
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			k++;
			j++;
		}
		if (k > 0)
		{
			tabword[i] = malloc((k + 1) * sizeof(char));
			if (!tabword[i])
				return (0);
		}
		i++;
	}
	return (1);
}

void	write_bloc(const char *s, char c, size_t nbrword, char **tabword)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < nbrword)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			tabword[i][k] = s[j];
			k++;
			j++;
		}
		tabword[i][k] = '\0';
		k = 0;
		i++;
	}
}

char	**ft_split(const char *s, char c)
{
	size_t	nbrword;
	size_t	i;
	char	**tabword;

	if (!s)
		return (NULL);
	nbrword = 0;
	nbrword = nbr_word(s, c);
	tabword = malloc((nbrword + 1) * sizeof(char *));
	if (!tabword)
		return (NULL);
	tabword[nbrword] = NULL;
	if (!alloc_bloc(s, c, nbrword, tabword))
	{
		i = 0;
		while (i < nbrword && tabword[i])
		{
			free(tabword[i]);
			i++;
		}
		free(tabword);
		return (NULL);
	}
	write_bloc(s, c, nbrword, tabword);
	return (tabword);
}
// int	main(void)
// {

// 	char	**result;
// 	int		i = 0;

// 	result = ft_split("hello!", 32);
// 	if (!result)
// 	{
// 		printf("ft_split returned NULL\n");
// 		return (1);
// 	}
// 	while (result[i])
// 	{
// 		printf("split[%d] = \"%s\"\n", i, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }
