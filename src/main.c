/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:38:05 by gpaupher          #+#    #+#             */
/*   Updated: 2025/01/23 13:59:18 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	init_img(t_data *data, int fd)
// {

// }

char	**mapping(t_data *data)
{
	//check map function checks walls holes in floor and number of players
}

char	**read_file(char *cub)
{
	int		fd;
	int		i;
	char	*file;

	fd = open(cub, O_RDONLY);
	if (!fd)
		return (ft_putstr_fd(ERR_OPEN, 2), NULL);
	return (file);
}

int	init_data(t_data *data, char **argv)
{
	char	**file;

	file = read_file(argv[1]);
	if (!file)
		return (1);
	init_img(data, argv);
	mapping(data);
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