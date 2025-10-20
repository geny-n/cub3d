/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:52:06 by gpaupher          #+#    #+#             */
/*   Updated: 2024/01/30 18:22:58 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;
	int		pos;

	i = 0;
	pos = -1;
	ptr = (char *)s;
	while (ptr[i])
	{
		if (ptr[i] == (unsigned char)c)
			pos = i;
		i++;
	}
	if (ptr[i] == (unsigned char) c)
		return (ptr + i);
	else if (pos >= 0)
		return (ptr + pos);
	else
		return (NULL);
}
