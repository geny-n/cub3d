/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:08:58 by gpaupher          #+#    #+#             */
/*   Updated: 2024/01/30 18:23:10 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../includes/libft.h"

static int	nbr_len(int nb)
{
	size_t	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	itoa_2(long nb, int len, char *ptr)
{
	if (nb == 0)
		ptr[0] = '0';
	while (nb)
	{
		ptr[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len --;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*ptr;

	nb = n;
	len = nbr_len(n);
	ptr = NULL;
	ptr = (char *) malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		nb *= -1;
	}
	itoa_2(nb, len, ptr);
	ptr[len] = '\0';
	return (ptr);
}
