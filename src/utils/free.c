/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:48:44 by gpaupher          #+#    #+#             */
/*   Updated: 2025/03/24 18:35:15 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}

void	clear_img(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, 0, data);
			x++;
		}
		y++;
	}
}

void	free_data(t_data *data)
{
	if (data->file)
		free_tab(data->file);
	if (data->map)
		free_tab(data->map);
	if (data->img.c)
		free_tab(data->img.c);
	if (data->img.f)
		free_tab(data->img.f);
	if (data->no_texture.path)
		free(data->no_texture.path);
	if (data->so_texture.path)
		free(data->so_texture.path);
	if (data->ea_texture.path)
		free(data->ea_texture.path);
	if (data->we_texture.path)
		free(data->we_texture.path);
}

void	free_img(t_data *data)
{
	if (data->no_texture.img)
		mlx_destroy_image(data->mlx_ptr, data->no_texture.img);
	if (data->so_texture.img)
		mlx_destroy_image(data->mlx_ptr, data->so_texture.img);
	if (data->ea_texture.img)
		mlx_destroy_image(data->mlx_ptr, data->ea_texture.img);
	if (data->we_texture.img)
		mlx_destroy_image(data->mlx_ptr, data->we_texture.img);
}

int	end(t_data *data)
{
	if (!data)
		return (1);
	free_data(data);
	free_img(data);
	if (data->imge)
		mlx_destroy_image(data->mlx_ptr, data->imge);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
