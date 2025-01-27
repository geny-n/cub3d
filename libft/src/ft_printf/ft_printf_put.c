/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:01:42 by gpaupher          #+#    #+#             */
/*   Updated: 2024/01/30 18:30:27 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	put_lenstr(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += print_char(str[i]);
		i++;
	}
	return (len);
}

int	print_str(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
		return (put_lenstr("(null)"));
	while (str[i])
	{
		len += print_char(str[i]);
		i++;
	}
	return (len);
}
