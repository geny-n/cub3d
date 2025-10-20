/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:42:33 by gpaupher          #+#    #+#             */
/*   Updated: 2025/03/25 16:12:10 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/includes/libft.h"
# include "../mlx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <math.h>

# define ERR_MLX		"cub3d error: Minilibx's function\n"
# define ERR_OPEN		"cub3d error: Open function\n"
# define ERR_LOAD_IMG	"cub3d error: Loading image\n"
# define ERR_MALLOC		"cub3d error: Malloc function\n"

# define ERR_ARG		"cub3d error: Invalid number of arguments\n"
# define ERR_FILE		"cub3d error: Invalid file\n"
# define ERR_DATA		"cub3d error: Invalid data in .cub\n"

# define ERR_IMG		"cub3d error: Invalid texture file\n"
# define ERR_COLOR		"cub3d error: Invalid color\n"
# define ERR_COL_VAL	"cub3d error: Invalid color value\n"
# define ERR_START		"cub3d error: None or too much start point\n"
# define ERR_MAP		"cub3d error: Invalid map\n"
# define ERR_WALL		"cub3d error: Map not closed\n"
# define ERR_TAB		"cub3d error: TAB character is not accepted\n"

# define SIZE 64
# define FOV 60
# define WIDTH 900
# define HEIGHT 900
# define MV_SPEED 2
# define ROT_SPEED 0.07
# define PI 3.14159265359

typedef struct s_player
{
	float	p_y;
	float	p_x;
	float	ray_x;
	float	ray_y;
	int		key_up;
	int		key_down;
	int		key_left;
	int		key_right;
	int		rotate_left;
	int		rotate_right;
	float	direction;
	float	fov;
}	t_player;

typedef struct s_texture
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	char	*path;
	int		wall_color;
}	t_texture;

typedef struct s_img
{
	char			**f;
	char			**c;
	unsigned long	floor;
	unsigned long	ceiling;
	int				img_width;
	int				img_height;
	int				tex_y;
	int				tex_x;
	int				start_y;
	int				end;
	int				d;
	float			wall_height;
}	t_img;

typedef struct s_item
{
	char	wall;
	char	floor;
}	t_item;

typedef struct s_data
{
	void		*imge;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	char		*pix;
	void		*mlx_ptr;
	void		*mlx_win;
	char		**file;
	char		**map;
	int			map_start;
	int			map_end;
	int			texture;
	float		distance;

	t_item		item;
	t_img		img;
	t_texture	no_texture;
	t_texture	so_texture;
	t_texture	ea_texture;
	t_texture	we_texture;
	t_player	player;
}	t_data;

/********INIT_DATA*******/
int		init_data(t_data *data, char **argv);

/*******INIT_MAP************/
char	*get_map_line(t_data *data, int i, int end);
int		check_map(int i, int end, char **file);
int		mapping(t_data *data);

/*******INIT_PLAYER************/
void	p_start_position(t_data *data);
void	p_start_direction(t_data *data);
void	set_player(t_data *data);

/********INIT_IMAGE*******/
int		draw_loop(t_data *data);
void	get_img(t_data *data, t_texture *texture);
int		init_mlx(t_data *data);

/*******RAY_CAST********/
float	fix_dist(t_player *player, t_data *data);
float	dist_to_wall(t_player *player, t_data *data, float fov_start);
void	create_ray_first_step(t_data *data, t_player *player, float fov_start);

/*******SET_IMAGE****/
void	put_pixel(int x, int y, int color, t_data *data);
int		get_colors_texture(t_texture *texture, t_img *img, int x, int y);
void	draw_floor_ceiling(t_data *data, int x, int start_y, int end);
void	set_color_wall(t_data *data, t_player *player, int x, int tex_x);
void	draw_line(t_player *player, t_data *data, int x);

/********INIT_TEXTURES*******/
char	*get_path(char *file);
char	**get_colors(char **colors, char *file);
int		init_walls(t_data *data, char *path);
int		init_colors(t_data *data, char *code);

/*******READ_FILE**********/
char	**read_file(int fd);
int		is_cub(char *file);
char	**get_file(char *dot_cub);

/*********CHECK_FILE************/
int		is_map(char *file);
int		is_path(char *path);
int		is_color(char *str);
int		check_line(char *file);
int		check_file(t_data *data, char **file);

/********UTILS_FT************* */
int		ft_isspace(char c);
int		ft_ischar(int c);
int		ft_tablen(char **tab);
int		ft_istab(int start, int end, char **file);

/********UTILS_MAP************* */
int		end_map(t_data *data);
int		is_ok_value(char c);
int		check_empty_line(char *line);
int		check_start(char c);
bool	touch(t_data *data, float px, float py);
int		wall_open(char c, int i, int j);
/********UTILS**************/
char	**tab_join(char **tab, char *str);
int		get_hexa_color(char **color);

/*******KEY_PRESS_MANAGER****** */
int		on_keypress(int keysym, t_data *data);
int		out_keypress(int keysym, t_data *data);
void	player_move(t_data *dt, float cos, float sin);
int		draw_loop(t_data *data);

/*******CAMERA****/
void	camera_move(t_data *data);
void	camera_player_move(t_data *data);

/*******FREE***********/
void	free_tab(char **tab);
void	free_data(t_data *data);
void	free_img(t_data *data);
void	clear_img(t_data *data);
int		end(t_data *data);

#endif