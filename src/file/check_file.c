/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:29:22 by gpaupher          #+#    #+#             */
/*   Updated: 2025/02/05 13:36:48 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_map(char *file)
{
	int	i;

	i = 0;
	while (file[i] && ft_isspace(file[i]))
		i++;
	if (file[i] == '1' || file[i] == '0')
		return (1);
	return (0);
}

int	is_path(char *path)
{
	int	i;

	i = 0;
	while (path[i] && ft_ischar(path[i]))
		i++;
	if (i == 0)
		return (0);
	while (path[i] && ft_isspace(path[i]))
		i++;
	if (!path[i])
		return (1);
	return (0);
}

int	is_color(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!str[i])
		return (0);
	i = 0;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == ','
			|| ft_isspace(str[i])))
	{
		if (str[i] == ',' && flag == 1)
			return (0);
		if (str[i] == ',')
			flag = 1;
		else if (str[i] != ',')
			flag = 0;
		i++;
	}
	if (!str[i])
		return (1);
	return (0);
}

int	check_line(char *file)
{
	int	i;

	i = 0;
	if (ft_strncmp(file, "NO", 2) == 0 || ft_strncmp(file, "SO", 2) == 0
		|| ft_strncmp(file, "EA", 2) == 0 || ft_strncmp(file, "WE", 2) == 0)
	{
		i = 2;
		while (file[i] && ft_isspace(file[i]))
			i++;
		if (is_path(file + i))
			return (1);
	}
	else if (ft_strncmp(file, "F", 1) == 0 || ft_strncmp(file, "C", 1) == 0)
	{
		i = 1;
		while (file[i] && ft_isspace(file[i]))
			i++;
		if (is_color(file + i))
			return (1);
	}
	return (0);
}

int	check_file(t_data *data, char **file)
{
	int	i;
	int	y;
	int	nb_line;

	i = -1;
	nb_line = 0;
	while (file[++i])
	{
		y = 0;
		while (file[i][y] && ft_isspace(file[i][y]))
			y++;
		if (!file[i][y])
			continue ;
		else if (!is_map(file[i] + y) && check_line(file[i] + y))
			nb_line++;
		else
		{
			data->map_start = i;
			break ;
		}
	}
	if (nb_line != 6)
		return (ft_putstr_fd(ERR_DATA, 2), 1);
	return (0);
}
