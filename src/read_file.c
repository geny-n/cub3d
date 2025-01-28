/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:06:38 by gpaupher          #+#    #+#             */
/*   Updated: 2025/01/28 14:07:00 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**read_file(int fd)
{
	char	*buffer;
	char	*file_line;
	char	**file;
	
	file_line = ft_strdup("");
	if (!file_line)
		return (NULL);
	buffer = get_next_line(fd);
	if (!buffer)
		return (ft_putstr_fd(ERR_FILE, 2), NULL);
	while (buffer)
	{
		file_line = ft_strjoin_gnl(file_line, buffer);
		free(buffer);
		if (!file_line)
			return (ft_putstr_fd(ERR_MALLOC, 2), NULL);
		buffer = get_next_line(fd);
	}
	free(buffer);
	file = ft_split(file_line, '\n');
	free(file_line);
	if (!file)
		return (ft_putstr_fd(ERR_MALLOC, 2), NULL);
	return (file);
}

int	is_cub(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '.')
		i++;
	if (ft_strcmp(file + i, ".cub") != 0)
		return (1);
	return (0);
}

char	**get_file(char *dot_cub)
{
	int		fd;
	char	**file;

	if (is_cub(dot_cub))
		return (ft_putstr_fd(ERR_FILE, 2), NULL);
	fd = open(dot_cub, O_RDONLY);
	if (!fd)
		return (ft_putstr_fd(ERR_OPEN, 2), NULL);	
	file = read_file(fd);
	if (!file)
		return (NULL);
	return (file);
}