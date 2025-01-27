/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:43:53 by gpaupher          #+#    #+#             */
/*   Updated: 2024/02/02 14:52:22 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else if (*lst != NULL)
	{
		last = *lst;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}	
	return ;
}
