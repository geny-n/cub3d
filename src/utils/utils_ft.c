/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:05:38 by gpaupher          #+#    #+#             */
/*   Updated: 2025/03/24 18:39:31 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_isspace(char c)
{
	if (c && (c == 32 || (9 <= c && c <= 13)))
		return (1);
	return (0);
}

int	ft_ischar(int c)
{
	if ((32 < c && c <= 126))
		return (1);
	else
		return (0);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int	ft_istab(int start, int end, char **file)
{
	int	i;
	int	j;

	i = start;
	while (i < end)
	{
		j = 0;
		while (file[i][j])
		{
			if (file[i][j] == '\t')
				return (ft_putstr_fd(ERR_TAB, 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}
