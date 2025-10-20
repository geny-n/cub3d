/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:40:36 by gpaupher          #+#    #+#             */
/*   Updated: 2024/01/30 18:22:40 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*ptr;
	int		len;

	ptr = (char *) src;
	len = ft_strlen(ptr);
	if (!ptr || !dst)
		return (0);
	if (size > 0)
	{
		while (*ptr && --size)
		{
			*dst = *ptr;
			dst++;
			ptr++;
		}
		*dst = '\0';
	}
	return (len);
}
