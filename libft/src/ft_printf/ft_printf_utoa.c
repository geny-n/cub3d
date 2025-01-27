/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:39:43 by gpaupher          #+#    #+#             */
/*   Updated: 2024/11/11 22:36:51 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	nbr_len(unsigned int nb)
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

void	utoa_2(unsigned int nb, int len, char *ptr)
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

int	print_utoa(unsigned int n)
{
	int		len;
	char	*ptr;

	len = nbr_len(n);
	ptr = NULL;
	ptr = (char *) malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (0);
	if (n <= 0)
		return (1);
	utoa_2(n, len, ptr);
	ptr[len] = '\0';
	print_str(ptr);
	free(ptr);
	return (len);
}
