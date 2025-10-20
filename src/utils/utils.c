/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:15:25 by gpaupher          #+#    #+#             */
/*   Updated: 2025/03/24 16:43:19 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**tab_join(char **tab, char *str)
{
	int		i;
	int		len;
	char	**new_tab;

	i = 0;
	len = ft_tablen(tab) + 1;
	if (!str)
		return (free_tab(tab), NULL);
	new_tab = malloc (sizeof(char *) * (len + 1));
	if (!new_tab)
		return (NULL);
	while (tab[i])
	{
		new_tab[i] = ft_strdup(tab[i]);
		if (!new_tab)
			return (free_tab(new_tab), free_tab(tab), NULL);
		i++;
	}
	new_tab[i] = ft_strdup(str);
	if (!new_tab)
		return (free_tab(new_tab), free_tab(tab), NULL);
	new_tab[++i] = NULL;
	free_tab(tab);
	return (new_tab);
}

int	check_color(char **color)
{
	int	i;
	int	y;

	i = 0;
	while (color[i])
	{
		y = 0;
		while (color[i][y])
		{
			if (y > 2)
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}

int	get_hexa_color(char **color)
{
	int	r;
	int	g;
	int	b;
	int	hex_color;

	if (check_color(color))
		return (-1);
	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	hex_color = ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
	return (hex_color);
}
