/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:10:30 by gpaupher          #+#    #+#             */
/*   Updated: 2024/03/27 17:42:47 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*ft_join(char *ptr, char *str1, char *str2)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (str1[pos])
	{
		ptr[pos] = str1[pos];
		pos++;
	}
	while (str2[i])
	{
		ptr[pos] = str2[i];
		i++;
		pos++;
	}
	ptr[pos] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*ptr;

	str1 = (char *)s1;
	str2 = (char *)s2;
	ptr = NULL;
	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (ptr == NULL)
		return (NULL);
	ft_join(ptr, str1, str2);
	return (ptr);
}
