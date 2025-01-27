/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:26:34 by gpaupher          #+#    #+#             */
/*   Updated: 2024/01/30 18:22:45 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	char	*str;
	int		i;

	str = (char *) s;
	ptr = NULL;
	i = 0;
	if (!s || !f)
		return (NULL);
	ptr = (char *) malloc(sizeof(char) * ft_strlen(str) + 1);
	if (ptr == (NULL))
		return (NULL);
	while (str[i])
	{
		ptr[i] = (*f)((unsigned int) i, str[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
