/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:42:33 by gpaupher          #+#    #+#             */
/*   Updated: 2025/01/27 18:25:29 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# define ERR_MLX	"cub3d error: Minilibx's function"
# define ERR_OPEN	"cub3d error: Open function"
# define ERR_MALLOC	"cub3d error: Malloc function"

# define ERR_ARG	"cub3d error: Invalid number of arguments"
# define ERR_FILE	"cub3d error: Invalid file"
# define ERR_MAP	"cub3d error: Invalid map"
# define ERR_IMG	"cub3d error: texture not correctly loaded"

typedef struct s_img
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_img;

typedef struct s_item
{
	char	player;
	char	wall;
	char	floor;
}	t_item;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**file;
	char	**map;

	t_item	item;
	t_img	img;
}	t_data;

#endif