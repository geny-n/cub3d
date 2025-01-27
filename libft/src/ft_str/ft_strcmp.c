/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:37:38 by gpaupher          #+#    #+#             */
/*   Updated: 2024/04/18 16:45:34 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strcmp(char *cmp, char *to_cmp)
{
	int	i;

	i = 0;
	while (cmp[i] == to_cmp[i])
	{
		if (cmp[i] == '\0' || to_cmp[i] == '\0')
			break ;
		i++;
	}
	if (cmp[i] == '\0' && to_cmp[i] == '\0')
		return (0);
	else
		return (cmp[i] - to_cmp[i]);
}
