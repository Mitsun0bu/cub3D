/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:22:50 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/16 19:16:22 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The header.h file is where we :
	- include pre-existing header files,
	- define our macros and enums,
	- declare typedefs for our structures.
*/

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ ENUMS ~~~                                */
/*                                                                            */
/* ************************************************************************** */

enum e_result {
	SUCCESS,
	FAILED
};

enum e_found {
	FOUND,
	NOT_FOUND
};

enum e_err_type {
	open_err,
	config_err,
	map_err
};

enum e_err_no {
	n_arg,
	extension,
	dir,
	fail,
	missing,
	invalid,
	new_line,
	n_player,
	walls
};

enum e_check {
	YES,
	NO
};

enum e_key {
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53,
	left_arrow = 123,
	right_arrow = 124
};

enum e_color {
	BLACK = 0x000000,
	WHITE = 0xFFFFFF,
	GREY = 0xE0E0E0,
	RED = 0xFF0000,
	PINK = 0xFF99FF,
	YELLOW = 0xFFFF66
};

enum e_orientation {
	NE,
	NW,
	SW,
	SE
};

enum e_grid {
	HORIZONTAL,
	VERTICAL
};

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_config
{
	char	*no_texture_path;
	char	*so_texture_path;
	char	*we_texture_path;
	char	*ea_texture_path;
	char	*floor_rgb_str;
	char	*ceiling_rgb_str;
	int		*floor_rgb_int_tab;
	int		*ceiling_rgb_int_tab;
	int		floor_hex_code;
	int		ceiling_hex_code;
	char	player_orientation;
}	t_config;

typedef struct map
{
	char	**tab;
	int		hgt;
	int		wdth;
	int		cell_size;
} t_map;

typedef struct s_win
{
	void	*mlx;
	void	*edge;
	void	*img_ptr;
	int		wdth;
	int		hgt;
	int		x;
	int		y;
}	t_win;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_texture
{
	char	*path;
	void	*tex;
	int		wdth;
	int		hgt;
	void	*ptr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_rect
{
	int	x;
	int	y;
	int	wdth;
	int	hgt;
	int	color;
}	t_rect;

typedef struct s_line
{
	double	x_start;
	double	y_start;
	double	x_end;
	double	y_end;
	int	color;
}	t_line;

typedef struct s_circle
{
	int	x;
	int	y;
	int	radius;
	int	color;
}	t_circle;

typedef struct s_player
{
	double	x;
	double	y;
	int		radius;
	char	orientation;
	int		turn_direction;
	int		walk_direction;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;
	double	fov;
}	t_player;

typedef struct s_ray
{
	// int		n_rays;
	// int		wall_strip_wdth;
	double	angle;
	double	wall_hit_x;
	double	wall_hit_y;
	int		is_facing_up;
	int		is_facing_down;
	int		is_facing_left;
	int		is_facing_right;
	int		grid_hit;
	// double	dir_x_start;
	// double	dir_y_start;
	// double	dir_x_end;
	// double	dir_y_end;
	// double	x_intercept;
	// double	y_intercept;
	// double	x_step;
	// double	y_step;
	// double	horizontal_wall_hit_x;
	// double	horizontal_wall_hit_y;
	// double	next_horizontal_touch_x;
	// double	next_horizontal_touch_y;
	// double	vertical_wall_hit_x;
	// double	vertical_wall_hit_y;
	// double	next_vertical_touch_x;
	// double	next_vertical_touch_y;
	// double	x_to_check;
	// double	y_to_check;
	// double	horizontal_hit_distance;
	// double	vertical_hit_distance;
	// double	len;
	// int		orientation;
	// t_line	line;
}	t_ray;

typedef struct s_data
{
	t_config	config;
	t_map		map;
	t_win		win;
	t_player	player;

	int			n_rays;
	int			wall_strip_wdth;
	t_ray		*ray_tab;
	// t_ray		ray;

	t_img		mini_map;
	t_img		walls;

	t_texture	east_texture;
	t_texture	north_texture;
	t_texture	south_texture;
	t_texture	west_texture;
}	t_data;

#endif
