/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:16:38 by gpaupher          #+#    #+#             */
/*   Updated: 2024/01/30 18:23:07 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		i;
	int		neg;
	long	nbr;

	i = 0;
	neg = 1;
	nbr = 0;
	str = (char *) nptr;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		neg *= -neg;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * neg);
}
