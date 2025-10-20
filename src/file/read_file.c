/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:06:38 by gpaupher          #+#    #+#             */
/*   Updated: 2025/03/24 18:31:58 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**read_file(int fd)
{
	char	*buffer;
	char	**tab;

	tab = malloc (sizeof(char *));
	if (!tab)
		return (NULL);
	tab[0] = NULL;
	buffer = get_next_line(fd);
	if (!buffer)
		return (ft_putstr_fd(ERR_FILE, 2), free_tab(tab), NULL);
	while (buffer)
	{
		tab = tab_join(tab, buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	return (tab);
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
	close(fd);
	if (!file)
		return (NULL);
	return (file);
}
