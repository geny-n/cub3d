/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:17:52 by ngeny             #+#    #+#             */
/*   Updated: 2025/01/28 16:00:07 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_img(t_img *img)
{
	img->
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080, "cub3D");
	data->imge = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->addr = mlx_get_data_addr(data->imge, &data->bits_per_pixel, &data->line_length,
								&data->endian);
	my_mlx_pixel_put(data, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imge, 0, 0);
	mlx_loop(data->mlx_ptr);
	return (0);
}
