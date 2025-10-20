/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:55:55 by ngeny             #+#    #+#             */
/*   Updated: 2025/03/24 18:37:15 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	wall_open(char c, int i, int j)
{
	if (c != '1' && c != '0' && !check_start(c))
	{
		ft_putstr_fd(ERR_WALL, 2);
		ft_putstr_fd("i = ", 2);
		ft_putnbr_fd(i, 2);
		ft_putstr_fd("   j = ", 2);
		ft_putnbr_fd(j, 2);
		return (1);
	}
	return (0);
}

int	check_up(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 && map[0][j] == '0')
				return (ft_putstr_fd(ERR_WALL, 2), 1);
			else if (i != 0 && (map[i][j] == '0' || check_start(map[i][j])))
			{
				if (wall_open(map[i - 1][j], i, j) == 1)
					return (ft_putstr_fd(" up\n", 2), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_down(char **map, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == size && map[size][j] == '0')
				return (ft_putstr_fd(ERR_WALL, 2), 1);
			else if (i != size && (map[i][j] == '0' || check_start(map[i][j])))
			{
				if (wall_open(map[i + 1][j], i, j) == 1)
					return (ft_putstr_fd("  down\n", 2), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_other_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || check_start(map[i][j]))
			{
				if (wall_open(map[i][j - 1], i, j) == 1)
					return (ft_putstr_fd("  left\n", 2), 1);
				if (wall_open(map[i][j + 1], i, j) == 1)
					return (ft_putstr_fd("  right\n", 2), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
