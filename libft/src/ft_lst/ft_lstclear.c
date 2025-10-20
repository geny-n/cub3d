/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:36:14 by gpaupher          #+#    #+#             */
/*   Updated: 2024/02/02 14:53:08 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstclear(t_lst **lst, void (*del)(void*))
{
	t_lst	*supp;
	t_lst	*temp;

	if (!lst)
		return ;
	supp = *lst;
	while (supp)
	{
		temp = supp->next;
		ft_lstdelone(supp, (del));
		supp = temp;
	}
	*lst = NULL;
	return ;
}
