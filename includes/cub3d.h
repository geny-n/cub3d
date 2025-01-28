/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:42:33 by gpaupher          #+#    #+#             */
/*   Updated: 2025/01/28 14:07:24 by gpaupher         ###   ########.fr       */
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

# define ERR_MLX	"cub3d error: Minilibx's function\n"
# define ERR_OPEN	"cub3d error: Open function\n"
# define ERR_MALLOC	"cub3d error: Malloc function\n"

# define ERR_ARG	"cub3d error: Invalid number of arguments\n"
# define ERR_FILE	"cub3d error: Invalid file\n"
# define ERR_DATA	"cub3d error: Invalid data in .cub\n"
# define ERR_MAP	"cub3d error: Invalid map\n"
# define ERR_IMG	"cub3d error: texture not correctly loaded\n"

typedef struct s_img
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;

	char	*f;
	char	*c;
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


char	**read_file(int fd);
char	**get_file(char *dot_cub);
int		is_cub(char *file);

#endif