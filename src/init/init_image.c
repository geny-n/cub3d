/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:24:28 by ngeny             #+#    #+#             */
/*   Updated: 2025/03/24 18:40:19 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	draw_loop(t_data *data)
{
	int		i;
	float	dist;
	float	fov_start;

	i = 0;
	camera_player_move(data);
	clear_img(data);
	fov_start = data->player.direction - (data->player.fov / 2);
	while (i < WIDTH)
	{
		dist = dist_to_wall (&data->player, data, fov_start);
		draw_line(&data->player, data, i);
		fov_start += data->player.fov / (WIDTH);
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imge, 0, 0);
	return (0);
}

void	get_img(t_data *data, t_texture *texture)
{
	texture->img = mlx_xpm_file_to_image(data->mlx_ptr, texture->path,
			&data->img.img_width, &data->img.img_height);
	if (!texture->img)
	{
		ft_putstr_fd(ERR_LOAD_IMG, 2);
		ft_putstr_fd(texture->path, 2);
		ft_putstr_fd("\n", 2);
		end(data);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_length, &texture->endian);
}

int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	get_img(data, &data->no_texture);
	get_img(data, &data->so_texture);
	get_img(data, &data->ea_texture);
	get_img(data, &data->we_texture);
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	data->imge = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->imge, &data->bpp, &data->line_length,
			&data->endian);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imge, 0, 0);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &on_keypress, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &out_keypress, data);
	mlx_loop_hook(data->mlx_ptr, draw_loop, data);
	mlx_hook(data->mlx_win, 17, 0, &end, data);
	mlx_loop(data->mlx_ptr);
	end(data);
	return (0);
}
