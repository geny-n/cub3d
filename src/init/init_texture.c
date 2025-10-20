/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:04:36 by gpaupher          #+#    #+#             */
/*   Updated: 2025/03/17 01:20:51 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*get_path(char *file)
{
	int		start;
	int		i;
	char	*path;

	i = 2;
	while (file[i] && ft_isspace(file[i]))
		i++;
	start = i;
	while (file[i] && ft_ischar(file[i]))
		i++;
	path = ft_substr(file, start, (i - start));
	if (!path)
		return (ft_putstr_fd(ERR_MALLOC, 2), NULL);
	return (path);
}

char	**color_extract(int i, char *file, char **colors)
{
	int		start;
	char	*str;

	while (file[i])
	{
		while (file[i] && ft_isspace(file[i]))
			i++;
		if (ft_isdigit(file[i]))
		{
			start = i;
			while (file[i] && ft_isdigit(file[i]))
				i++;
			str = ft_substr(file, start, (i - start));
			if (!str)
				return (ft_putstr_fd(ERR_MALLOC, 2), NULL);
			colors = tab_join(colors, str);
			free(str);
			if (!colors)
				return (ft_putstr_fd(ERR_MALLOC, 2), NULL);
		}
		if (file[i])
			i++;
	}
	return (colors);
}

char	**get_colors(char **colors, char *file)
{
	int		i;

	i = 1;
	if (!file)
		return (ft_putstr_fd("Error: file is NULL\n", 2), NULL);
	colors = color_extract(i, file, colors);
	return (colors);
}

int	init_walls(t_data *data, char *path)
{
	char	*img;
	int		fd;

	img = get_path(path);
	if (!img)
		return (1);
	fd = open(img, O_RDONLY, 0777);
	if (fd == -1)
	{
		free(img);
		return (ft_putstr_fd(ERR_IMG, 2), 1);
	}
	close(fd);
	if (ft_strncmp(path, "NO", 2) == 0)
		data->no_texture.path = img;
	else if (ft_strncmp(path, "SO", 2) == 0)
		data->so_texture.path = img;
	else if (ft_strncmp(path, "EA", 2) == 0)
		data->ea_texture.path = img;
	else if (ft_strncmp(path, "WE", 2) == 0)
		data->we_texture.path = img;
	return (0);
}

int	init_colors(t_data *data, char *code)
{
	char	**colors;

	colors = NULL;
	colors = malloc(sizeof(char *) * 4);
	if (!colors)
		return (ft_putstr_fd(ERR_MALLOC, 2), 1);
	colors[0] = NULL;
	colors = get_colors(colors, code);
	if (!colors)
		return (free(colors), ft_putstr_fd("Error: get_colors failed\n", 2), 1);
	if (!colors[0] || !colors[1] || !colors[2])
		return (free_tab(colors), ft_putstr_fd(ERR_COL_VAL, 2), 1);
	if (ft_tablen(colors) != 3)
		return (free_tab(colors), ft_putstr_fd(ERR_COL_VAL, 2), 1);
	if (ft_strncmp(code, "F", 1) == 0)
		data->img.floor = get_hexa_color(colors);
	else if (ft_strncmp(code, "C", 1) == 0)
		data->img.ceiling = get_hexa_color(colors);
	free_tab(colors);
	if (data->img.floor == -1 || data->img.ceiling == -1)
		return (ft_putstr_fd(ERR_COLOR, 2), 1);
	return (0);
}
