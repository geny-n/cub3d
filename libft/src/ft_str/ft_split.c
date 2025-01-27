/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:37:00 by gpaupher          #+#    #+#             */
/*   Updated: 2024/03/28 15:02:30 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	ft_countword(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
		else if (str[i] == c)
			i++;
	}
	return (count);
}

static void	free_me(size_t pos, char **ptr)
{
	while (pos > 0)
	{
		free(*(ptr + pos));
		pos--;
	}
	free(ptr);
}

static char	**ft_addword(const char *str, char c, char **ptr, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	pos;

	i = 0;
	pos = 0;
	while (pos < count)
	{
		j = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i + j] && str[i + j] != c)
			j++;
		ptr[pos] = ft_substr(str, i, j);
		if (!ptr[pos])
		{
			free_me(pos, ptr);
			return (NULL);
		}
		while (str[i] != c && str[i])
			i++;
		pos++;
	}
	ptr[pos] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_countword(s, c);
	ptr = (char **) malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (NULL);
	ptr = ft_addword(s, c, ptr, count);
	return (ptr);
}
