/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:42:19 by ngeny             #+#    #+#             */
/*   Updated: 2025/02/24 22:41:51 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_player(t_data *data)
{
	data->player.key_up = 0;
	data->player.key_down = 0;
	data->player.key_right = 0;
	data->player.key_left = 0;
	data->player.rotate_left = 0;
	data->player.rotate_right = 0;
}

void	p_start_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (check_start(data->map[i][j]) == 1)
			{
				data->player.p_x = (j * SIZE) + SIZE / 2;
				data->player.p_y = (i * SIZE) + SIZE / 2;
			}
			j++;
		}
		i++;
	}
}

void	p_start_direction(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				data->player.direction = 0;
			if (data->map[i][j] == 'N')
				data->player.direction = 3 * PI / 2;
			if (data->map[i][j] == 'W')
				data->player.direction = PI;
			if (data->map[i][j] == 'S')
				data->player.direction = PI / 2;
			j++;
		}
		i++;
	}
}
