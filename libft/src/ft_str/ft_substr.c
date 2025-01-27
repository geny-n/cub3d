/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:26:25 by gpaupher          #+#    #+#             */
/*   Updated: 2024/12/23 17:34:02 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*newstr(size_t len)
{
	char	*ptr;

	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	else if (len > (ft_strlen(s) - start))
			len = ft_strlen(s) - start;
	str = newstr(len);
	if (!str)
		return (NULL);
	s += start;
	ptr = str;
	*(str + len) = '\0';
	while (len-- && *s)
		*str++ = *s++;
	return (ptr);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*str;
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	if (ft_strlen(s) < start)
// 		len = 0;
// 	else if (len > (ft_strlen(s) - start))
// 			len = ft_strlen(s) - start;
// 	str = (char *) malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	s += start;
// 	*(str + len) = '\0';
// 	while (len-- && *s)
// 		*str++ = *s++;
// 	return (str);
// }
