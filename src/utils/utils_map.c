/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:27:58 by ngeny             #+#    #+#             */
/*   Updated: 2025/03/24 18:36:24 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	end_map(t_data *data)
{
	int	i;
	int	j;

	i = data->map_start;
	j = 0;
	while (data->file[i])
		i++;
	i--;
	while (i > data->map_start)
	{
		j = 0;
		while (data->file[i][j])
		{
			if (!ft_isspace(data->file[i][j]))
				return (i);
			j++;
		}
		i--;
	}
	return (0);
}

int	is_ok_value(char c)
{
	if (c == '1' || c == '0'
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W' || ft_isspace(c))
		return (0);
	return (1);
}

int	check_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_start(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

bool	touch(t_data *data, float px, float py)
{
	int	x;
	int	y;

	x = px / SIZE;
	y = py / SIZE;
	if (data->map[y][x] == '1')
		return (true);
	return (false);
}
