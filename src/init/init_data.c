/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:20:25 by gpaupher          #+#    #+#             */
/*   Updated: 2025/03/24 17:42:47 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->imge = NULL;
	data->img.img_width = 64;
	data->img.img_height = 64;
	data->img.ceiling = 0;
	data->img.floor = 0;
	data->file = NULL;
	data->map = NULL;
	data->no_texture.path = NULL;
	data->so_texture.path = NULL;
	data->ea_texture.path = NULL;
	data->we_texture.path = NULL;
	data->no_texture.img = NULL;
	data->so_texture.img = NULL;
	data->ea_texture.img = NULL;
	data->we_texture.img = NULL;
	data->distance = 0;
	data->img.f = NULL;
	data->img.c = NULL;
	set_player(data);
}

static int	init_img(t_data *data, char **file)
{
	int	i;
	int	y;

	i = 0;
	while (file[i] && !is_map(file[i]))
	{
		y = 0;
		while (file[i][y] && ft_isspace(file[i][y]))
			y++;
		if (file[i][y] && (ft_strncmp(file[i] + y, "F", 1) == 0
			|| ft_strncmp(file[i] + y, "C", 1) == 0))
		{
			if (init_colors(data, file[i] + y))
				return (1);
		}
		else if (file[i][y])
		{
			if (init_walls(data, file[i] + y))
				return (1);
		}
		i++;
	}
	return (0);
}

int	init_data(t_data *data, char **argv)
{
	set_data(data);
	data->file = get_file(argv[1]);
	if (!data->file)
		return (1);
	if (check_file(data, data->file))
		return (free_data(data), 1);
	if (init_img(data, data->file))
		return (free_data(data), 1);
	data->map_end = end_map(data);
	if (mapping(data) == 1)
		return (free_data(data), 1);
	p_start_position(data);
	p_start_direction(data);
	data->player.fov = FOV * (PI / 180);
	init_mlx(data);
	return (0);
}
