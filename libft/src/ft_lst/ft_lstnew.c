/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:46:27 by gpaupher          #+#    #+#             */
/*   Updated: 2024/02/02 14:54:05 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_lst	*ft_lstnew(void *content)
{
	t_lst	*new;

	new = (t_lst *) malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
