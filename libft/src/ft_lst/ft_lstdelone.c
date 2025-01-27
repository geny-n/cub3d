/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:33:54 by gpaupher          #+#    #+#             */
/*   Updated: 2024/02/02 14:53:13 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstdelone(t_lst *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	else
	{
		if (del && lst->content)
			(del)(lst->content);
		free(lst);
		lst = NULL;
	}
}
