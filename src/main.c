/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:41:46 by ngeny             #+#    #+#             */
/*   Updated: 2025/03/24 17:40:11 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_putstr_fd(ERR_ARG, 2), 1);
	if (init_data(&data, argv))
		return (1);
	free_data(&data);
	return (0);
1}
