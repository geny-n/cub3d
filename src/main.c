/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:38:05 by gpaupher          #+#    #+#             */
/*   Updated: 2025/01/28 13:56:20 by ngeny            ###   ########.fr       */
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



int	main(int argc, char **argv)
{
	t_data	data;
	(void) argc;
	(void) argv;
	// if (argc != 2)
	// 	return (ft_putstr_fd(ERR_ARG, 2), 1);
	// if (init_data(&data, argv))
	// 	return (1); // in case of error;
	init_data(&data);
	return (0);
}