/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:22:07 by gpaupher          #+#    #+#             */
/*   Updated: 2024/11/11 22:35:23 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	nbr_baselen(unsigned long nbr, int base)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr <= 0)
		i++;
	while (nbr > 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

static void	putnbr_base(unsigned long nbr, char *base, unsigned int base_len)
{
	long long	div;
	long long	mod;

	if (nbr > (base_len - 1))
	{
		div = nbr / base_len;
		mod = nbr % base_len;
		putnbr_base(div, base, base_len);
	}
	if (nbr > (base_len - 1))
		print_char(base[mod]);
	else
		print_char(base[nbr]);
	return ;
}

int	print_ptr(unsigned long ptr)
{
	char	*base;
	int		len;
	int		base_len;

	len = 0;
	base = "0123456789abcdef";
	base_len = 16;
	if (ptr == 0)
	{
		print_str("(nil)");
		return (5);
	}
	else
	{
		len += print_str("0x");
		len += nbr_baselen(ptr, base_len);
		putnbr_base(ptr, base, base_len);
	}
	return (len);
}
