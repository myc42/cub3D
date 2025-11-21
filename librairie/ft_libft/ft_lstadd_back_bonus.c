/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:34:26 by macoulib          #+#    #+#             */
/*   Updated: 2025/11/08 14:36:13 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstnew;

	lstnew = *lst;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{	
		*lst = new;
		return ;
	}
	while (lstnew ->next != NULL)
	{
		lstnew = lstnew -> next;
	}
	lstnew->next = new;
}
