/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:52:13 by gpaupher          #+#    #+#             */
/*   Updated: 2024/01/30 18:21:59 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr;
	char	*src_bis;
	size_t	i;

	i = 0;
	ptr = (char *)dest;
	src_bis = (char *)src;
	if (!ptr && !src_bis)
		return (NULL);
	while (i < n)
	{
		*ptr = *src_bis;
		ptr++;
		src_bis++;
		i++;
	}
	return (dest);
}
