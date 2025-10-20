/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:33:46 by ngeny             #+#    #+#             */
/*   Updated: 2025/03/24 18:40:02 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*get_map_line(t_data *data, int i, int end)
{
	char	*dest;

	dest = ft_strdup(data->file[i]);
	i++;
	while (i <= end)
	{
		dest = ft_strjoin_gnl(dest, data->file[i]);
		i++;
	}
	return (dest);
}

int	check_map(int i, int end, char **file)
{
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (i <= end)
	{
		j = 0;
		while (file[i][j])
		{
			if (is_ok_value(file[i][j]) == 1)
				return (ft_putstr_fd(ERR_MAP, 2), 1);
			if (check_start(file[i][j]) == 1)
				flag++;
			j++;
		}
		if (!check_empty_line(file[i]))
			return (ft_putstr_fd(ERR_WALL, 2), 1);
		i++;
	}
	if (flag != 1)
		return (ft_putstr_fd(ERR_START, 2), 1);
	return (0);
}

int	check_wall(int i, int end, char **file)
{
	int	j;

	j = 0;
	while (i <= end)
	{
		j = 0;
		while (file[i][j])
		{
			if (file[i][j] == '0' || check_start(file[i][j]))
			{
				if (wall_open(file[i][j - 1], i, j) == 1)
					return (ft_putstr_fd("  left\n", 2), 1);
				if (wall_open(file[i][j + 1], i, j) == 1)
					return (ft_putstr_fd("  right\n", 2), 1);
				if (wall_open(file[i - 1][j], i, j) == 1)
					return (ft_putstr_fd("  up\n", 2), 1);
				if (wall_open(file[i + 1][j], i, j) == 1)
					return (ft_putstr_fd("  down\n", 2), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	mapping(t_data *data)
{
	char	*one_line;
	char	**map;

	if (ft_istab(data->map_start, data->map_end, data->file))
		return (1);
	if (check_map(data->map_start, data->map_end, data->file) == 1)
		return (1);
	if (check_wall(data->map_start, data->map_end, data->file) == 1)
		return (1);
	one_line = get_map_line(data, data->map_start, data->map_end);
	map = ft_split(one_line, '\n');
	free(one_line);
	if (!map)
		return (1);
	data->map = map;
	return (0);
}
