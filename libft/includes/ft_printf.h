/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:57:17 by gpaupher          #+#    #+#             */
/*   Updated: 2024/01/30 18:27:32 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_char(int c);
int	print_str(char *str);
int	print_nbr(int n);
int	print_hexaupp(unsigned int nbr);
int	print_hexalow(unsigned int nbr);
int	print_utoa(unsigned int n);
int	print_ptr(unsigned long ptr);

#endif