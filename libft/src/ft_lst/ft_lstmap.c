/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:24:19 by gpaupher          #+#    #+#             */
/*   Updated: 2024/02/02 14:53:58 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_lst	*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *))
{
	t_lst	*lst_origin;
	t_lst	*lst_new;
	void	*dock;

	if (!lst || !f || !del)
		return (NULL);
	lst_origin = NULL;
	while (lst)
	{
		dock = (*f)(lst->content);
		lst_new = ft_lstnew(dock);
		if (!lst_new)
		{
			ft_lstclear(&lst_new, (*del));
			return (lst_origin);
		}
		ft_lstadd_back(&lst_origin, lst_new);
		lst = lst->next;
	}
	return (lst_origin);
}
