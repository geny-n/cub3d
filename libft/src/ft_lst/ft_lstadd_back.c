/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:37:59 by gpaupher          #+#    #+#             */
/*   Updated: 2025/02/24 22:49:09 by ngeny            ###   ########.fr       */
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
