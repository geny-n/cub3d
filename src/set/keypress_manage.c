/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_manage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:40:26 by ngeny             #+#    #+#             */
/*   Updated: 2025/03/24 21:05:11 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end(data);
	if (keysym == XK_w)
		data->player.key_up = true;
	if (keysym == XK_s)
		data->player.key_down = true;
	if (keysym == XK_a)
		data->player.key_left = true;
	if (keysym == XK_d)
		data->player.key_right = true;
	if (keysym == XK_Left)
		data->player.rotate_left = true;
	if (keysym == XK_Right)
		data->player.rotate_right = true;
	return (0);
}

int	out_keypress(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->player.key_up = false;
	if (keysym == XK_s)
		data->player.key_down = false;
	if (keysym == XK_a)
		data->player.key_left = false;
	if (keysym == XK_d)
		data->player.key_right = false;
	if (keysym == XK_Left)
		data->player.rotate_left = false;
	if (keysym == XK_Right)
		data->player.rotate_right = false;
	return (0);
}

static void	player_move2(t_data *dt, float cos, float sin)
{
	if (dt->player.key_left
		&& (!touch(dt, dt->player.p_x + 7 * sin * MV_SPEED, dt->player.p_y))
		&& (!touch(dt, dt->player.p_x, dt->player.p_y - 7 * cos * MV_SPEED)))
	{
		dt->player.p_x += 3 * sin * MV_SPEED;
		dt->player.p_y -= 3 * cos * MV_SPEED;
	}
	if (dt->player.key_right
		&& (!touch(dt, dt->player.p_x - 7 * sin * MV_SPEED, dt->player.p_y))
		&& (!touch(dt, dt->player.p_x, dt->player.p_y + 7 * cos * MV_SPEED)))
	{
		dt->player.p_x -= 3 * sin * MV_SPEED;
		dt->player.p_y += 3 * cos * MV_SPEED;
	}
}

void	player_move(t_data *dt, float cos, float sin)
{
	if (dt->player.key_up
		&& (!touch(dt, dt->player.p_x + 7 * cos * MV_SPEED, dt->player.p_y))
		&& (!touch(dt, dt->player.p_x, dt->player.p_y + 7 * sin * MV_SPEED)))
	{
		dt->player.p_x += 3 * cos * MV_SPEED;
		dt->player.p_y += 3 * sin * MV_SPEED;
	}
	if (dt->player.key_down
		&& (!touch(dt, dt->player.p_x - 7 * cos * MV_SPEED, dt->player.p_y))
		&& (!touch(dt, dt->player.p_x, dt->player.p_y - 7 * sin * MV_SPEED)))
	{
		dt->player.p_x -= 3 * cos * MV_SPEED;
		dt->player.p_y -= 3 * sin * MV_SPEED;
	}
	player_move2(dt, cos, sin);
}
