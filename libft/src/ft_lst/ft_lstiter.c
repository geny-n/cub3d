/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:46:59 by gpaupher          #+#    #+#             */
/*   Updated: 2024/02/02 14:53:17 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstiter(t_lst *lst, void (*f)(void *))
{
	if (lst)
	{
		while (lst)
		{
			(*f)(lst->content);
			lst = lst->next;
		}
	}
	return ;
}
