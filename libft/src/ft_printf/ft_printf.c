/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:54:56 by gpaupher          #+#    #+#             */
/*   Updated: 2024/01/30 18:30:53 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_check(va_list ag, char c)
{
	int	len;

	len = 0;
	if (c == '%')
		len += print_char('%');
	else if (c == 'c')
		len += print_char(va_arg(ag, int));
	else if (c == 's')
		len += print_str(va_arg(ag, char *));
	else if (c == 'd' || c == 'i')
		len += print_nbr(va_arg(ag, int));
	else if (c == 'p')
		len += print_ptr(va_arg(ag, unsigned long));
	else if (c == 'u')
		len += print_utoa(va_arg(ag, unsigned int));
	else if (c == 'x')
		len += print_hexalow(va_arg(ag, unsigned int));
	else if (c == 'X')
		len += print_hexaupp(va_arg(ag, unsigned int));
	else
		return (0);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	i;
	int		len;

	len = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			len += ft_check(arg, str[i + 1]);
			i++;
		}
		else
			len += print_char(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
