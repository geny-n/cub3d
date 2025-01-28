/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:38:05 by gpaupher          #+#    #+#             */
/*   Updated: 2025/01/28 16:16:39 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	get_img(t_data *data, char *file)
// {
// 	int	i;

// 	i = 0;
// 	while(file[i])
// 	{
		
// 		i++;
// 	}
// 	return (0);
// }

// int	init_img(t_data *data, char **file)
// {
// 	int	i;

// 	i = 0;
// 		return (ft_putstr_fd(ERR_DATA, 2), NULL);
// 	while (file[i])
// 	{
// 		if (get_img(data, file[i]))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char	**mapping(t_data *data)
// {
// 	//check map function checks walls holes in floor and number of players
// }

// int	ft_isspace(char c)
// {
// 	if (c && (c == 32 || (9 <= c && c <= 13)))
// 		return (1);
// 	return (0);
// }

// int	is_img

// int	check_file(char **file)
// {
// 	int	i;
// 	int	y;
// 	int	nb_line;

// 	i = -1;
// 	nb_line = 0;
// 	while (file[++i])
// 	{
// 		y = 0;
// 		while (file[i][y] && ft_isspace(file[i][y]))
// 			y++;
// 		if (!file[i][y])
// 			continue;
// 		else if (ft_strncmp(file[i] + y, "NO ", 3) == 0 || ft_strncmp(file[i] + y, "SO ", 3) == 0 
// 			|| ft_strncmp(file[i] + y, "EA ", 3) == 0 || ft_strncmp(file[i] + y, "WE ", 3) == 0
// 			|| ft_strncmp(file[i] + y, "F ", 2) == 0 || ft_strncmp(file[i] + y, "C ", 2) == 0)
// 			nb_line++;
// 		else
// 			break;		
// 	}
// 	if (nb_line != 6)
// 		return (1);
	
// 	return (0);
// }

int	init_data(t_data *data, char **argv)
{
	char	**file;

	file = get_file(argv[1]);
	if (!file)
		return (1);
	// if (check_file(file))
	// 	return (1);
	// if (init_img(data, file))
	// 	return (1);// error with the data in file
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