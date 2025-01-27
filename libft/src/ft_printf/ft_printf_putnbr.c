/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:06:37 by gpaupher          #+#    #+#             */
/*   Updated: 2024/11/11 22:36:20 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	nbr_baselen(int nbr, int base)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0 && base == 10)
	{
		nbr = -nbr;
		i++;
	}
	if (nbr < 0 && base == 16)
		return (8);
	while (nbr > 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

static void	putnbr_base(unsigned int nbr, char *base, unsigned int base_len)
{
	unsigned int	div;
	unsigned int	mod;

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

int	print_hexalow(unsigned int nbr)
{
	char			*base;
	int				len;
	unsigned int	base_len;

	base_len = 16;
	base = "0123456789abcdef";
	len = 0;
	if (nbr <= 0)
		return (1);
	putnbr_base(nbr, base, base_len);
	len += nbr_baselen(nbr, base_len);
	return (len);
}

int	print_hexaupp(unsigned int nbr)
{
	unsigned int			base_len;
	char					*base;
	int						len;

	base_len = 16;
	base = "0123456789ABCDEF";
	len = 0;
	if (nbr <= 0)
		return (1);
	putnbr_base(nbr, base, base_len);
	len += nbr_baselen(nbr, base_len);
	return (len);
}

int	print_nbr(int n)
{
	int		nb;

	nb = n;
	if (n == -2147483648)
		return (print_str("-2147483648"));
	if (n < 0)
	{
		print_char('-');
		n *= -1;
	}
	if (n < 10)
		print_char(n + '0');
	else if (n > 9)
	{
		print_nbr((n / 10));
		print_nbr((n % 10));
	}
	return (nbr_baselen(nb, 10));
}
