/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:38:05 by gpaupher          #+#    #+#             */
/*   Updated: 2025/01/27 18:27:45 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	init_img(t_data *data, int fd)
// {

// }

// char	**mapping(t_data *data)
// {
// 	//check map function checks walls holes in floor and number of players
// }

char	*read_file(int fd)
{
	char	*buffer;
	char	*file_line;
	char	**file;
	
	file_line = ft_strdup("");
	if (!file_line)
		return (NULL);
	buffer = get_next_line(fd);
	while (buffer)
	{
		file_line = ft_strjoin_gnl(file_line, buffer);
		free(buffer);
		if (!file_line)
			return (NULL);
		buffer = get_next_line(fd);
	}
	free(buffer);
	file = ft_split(file_line, '\n');
	free(file_line);
	if (!file)
		return (NULL);
	return (file);
}

char	**get_file(char *cub)
{
	int		fd;
	char	*buffer;
	char	*file_line;
	char	**file;

	//if (is_cub(cub))//check if file as parameter is a .cub file
		// return (ft_putstr_fd(ERR_FILE, 2), NULL);
	fd = open(cub, O_RDONLY);
	if (!fd)
		return (ft_putstr_fd(ERR_OPEN, 2), NULL);	
	file_line = read_file(fd);
	if (!file_line)
		return (ft_putstr_fd(ERR_MALLOC, 2), NULL);
	return (file);
}

int	init_data(t_data *data, char **argv)
{
	char	**file;

	file = get_file(argv[1]);
	if (!file)
		return (1);
	// init_img(data, argv);
	// mapping(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc != 2)
		return (ft_putstr_fd(ERR_ARG, 2), 1);
	if (init_data(&data, argv))
		return (1); // in case of error;
	return (0);
}