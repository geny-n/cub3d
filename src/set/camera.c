/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:56:16 by ngeny             #+#    #+#             */
/*   Updated: 2025/03/25 16:01:27 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	camera_player_move(t_data *data)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(data->player.direction);
	sin_angle = sin(data->player.direction);
	camera_move(data);
	player_move(data, cos_angle, sin_angle);
}

void	camera_move(t_data *data)
{
	float	acc;

	acc = 1 + expf(50 / data->distance) / 50;
	if (data->player.rotate_right)
	{
		data->player.direction += ROT_SPEED * acc;
		if (data->player.direction > 2 * PI)
			data->player.direction -= 2 * PI;
	}
	if (data->player.rotate_left)
	{
		data->player.direction -= ROT_SPEED * acc;
		if (data->player.direction < 0)
			data->player.direction += 2 * PI;
	}
}
