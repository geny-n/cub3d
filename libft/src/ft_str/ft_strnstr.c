/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:29:37 by gpaupher          #+#    #+#             */
/*   Updated: 2024/01/30 18:22:51 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;
	char	*to_find;
	size_t	i;
	size_t	j;

	str = (char *) big;
	to_find = (char *) little;
	i = 0;
	if (!str && !len)
		return (NULL);
	if (to_find[i] == '\0')
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while ((str[i + j] == to_find[j]) && (str[i + j])
			&& (i < len || i + j < len))
		{
			j++;
			if (to_find[j] == '\0' && (i + ft_strlen(little) <= len))
				return (str + i);
		}
		i++;
	}
	return (NULL);
}
