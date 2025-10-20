/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:55:29 by ngeny             #+#    #+#             */
/*   Updated: 2025/03/25 16:07:29 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(int x, int y, int color, t_data *data)
{
	char	*dst;

	dst = NULL;
	if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	get_colors_texture(t_texture *texture, t_img *img, int x, int y)
{
	int	color;

	if (x >= 0 && x < img->img_width && y >= 0 && y < img->img_height)
	{
		color = *(unsigned int *)(texture->addr
				+ (y * texture->line_length + x * (texture->bpp / 8)));
		return (color);
	}
	return (0);
}

void	draw_floor_ceiling(t_data *data, int x, int start_y, int end)
{
	int	i;

	i = 0;
	while (i < start_y)
	{
		put_pixel(x, i, data->img.ceiling, data);
		i++;
	}
	i = end;
	while (i < HEIGHT)
	{
		put_pixel(x, i, data->img.floor, data);
		i++;
	}
}

void	set_color_wall(t_data *data, t_player *player, int x, int tex_x)
{
	int	color;

	if (touch(data, player->ray_x, player->ray_y + 1))
	{
		color = get_colors_texture(&data->no_texture, &data->img,
				tex_x, data->img.tex_y);
	}
	else if (touch(data, player->ray_x, player->ray_y - 1))
	{
		color = get_colors_texture(&data->so_texture, &data->img,
				tex_x, data->img.tex_y);
	}
	else if (touch(data, player->ray_x + 1, player->ray_y))
	{
		color = get_colors_texture(&data->we_texture, &data->img,
				((int)(player->ray_y) % SIZE), data->img.tex_y);
	}
	else if (touch(data, player->ray_x - 1, player->ray_y))
	{
		color = get_colors_texture(&data->ea_texture, &data->img,
				((int)(player->ray_y) % SIZE), data->img.tex_y);
	}
	data->img.tex_y = (int)((data->img.start_y - data->img.d)
			* ((SIZE - 1) / data->img.wall_height));
	put_pixel(x, data->img.start_y, color, data);
}

void	draw_line(t_player *player, t_data *data, int x)
{
	float	dist;
	int		d;

	dist = fix_dist(player, data);
	data->img.wall_height = ((SIZE / dist) * (WIDTH)) / 1.11;
	data->img.start_y = (HEIGHT - data->img.wall_height) / 2;
	data->img.end = data->img.start_y + data->img.wall_height;
	data->img.d = data->img.start_y;
	data->img.tex_y = SIZE;
	data->img.tex_x = ((int)(player->ray_x) % SIZE);
	draw_floor_ceiling(data, x, data->img.start_y, data->img.end);
	while (data->img.start_y < data->img.end)
	{
		set_color_wall(data, player, x, data->img.tex_x);
		data->img.start_y++;
	}
	return ;
}
