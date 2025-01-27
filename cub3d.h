/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:37:21 by ngeny             #+#    #+#             */
/*   Updated: 2025/01/27 17:44:04 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/includes/libft.h"
#include "stdio.h"
#include "stdlib.h"
# include "./minilibx-linux/mlx.h"


typedef struct s_img
{
	char space;
}	t_item;

typedef struct s_item
{
	char space;
}	t_item;

typedef struct s_player
{
	int	x;
	int	y;
}	t_item;

typedef struct s_map
{
	char **map;
	int			map_w;
	int			map_h;
}	t_data;

typedef struct s_data
{
	int i;
	int			start_x;
	int			start_y;
	t_item item;
}	t_data;


#endif