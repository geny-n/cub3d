/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:06:56 by ngeny             #+#    #+#             */
/*   Updated: 2025/03/25 16:07:45 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	fix_dist(t_player *player, t_data *data)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = player->ray_x - player->p_x;
	delta_y = player->ray_y - player->p_y;
	angle = atan2(delta_y, delta_x) - data->player.direction;
	fix_dist = sqrt(delta_x * delta_x + delta_y * delta_y) * cos(angle);
	return (fix_dist);
}

float	get_dist(t_data *data, t_player *player, float the_angle, char ray)
{
	float	dist;

	if (ray == 'y')
	{
		player->ray_y -= the_angle / 3;
		dist = fix_dist(player, data);
		data->distance = dist;
		return (dist);
	}
	else
	{
		player->ray_x -= the_angle / 3;
		dist = fix_dist(player, data);
		data->distance = dist;
		return (dist);
	}
	return (0);
}

float	dist_to_wall(t_player *player, t_data *data, float fov_start)
{
	float	cos_angle;
	float	sin_angle;
	float	dist;

	cos_angle = cos(fov_start);
	sin_angle = sin(fov_start);
	player->ray_x = player->p_x;
	player->ray_y = player->p_y;
	while (!touch(data, player->ray_x, player->ray_y))
	{
		if (touch(data, player->ray_x, player->ray_y + sin_angle / 3))
			return (get_dist(data, player, sin_angle, 'y'));
		else
			player->ray_y += sin_angle / 3;
		if (touch(data, player->ray_x + cos_angle / 3, player->ray_y))
			return (get_dist(data, player, cos_angle, 'x'));
		else
			player->ray_x += cos_angle / 3;
	}
	return (dist);
}
