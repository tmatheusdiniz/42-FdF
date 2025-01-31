/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:14:11 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/15 14:23:43 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

// Defines
# define WINDOW_WIDTH	1920
# define WINDOW_HEIGHT	1080
# define SCALE			20
# define TRUE			1
# define FALSE			0
# define ISO_ANGLE		0.523599
# define Z_SCALE		0.07

// Colors
# define PURPLE	0x800080
# define YELLOW	0xFFFF00
# define WHITE	0xFFFFFF

// Menu
# define MENU_WIDTH		350
# define MENU_HEIGHT	1080
# define M_STR_COLOR	0xFFFF00
# define CONTROL_BOX	180
# define MOVES_BOX		350
# define MENU_X			30
# define SPACE_B_LINES	30
# define ROTATION_MSG	"left-a / right-a (Y-Axis), up-a / down-a (X-Axis)"
# define ROTATION_Z_MSG	"Q / E (Z-Axis)"
# define TRANSLATE_MSG	"A (Left) / D (Right), W (Up) / S (Down)"
# define ANIMATION_MSG	"Right Click + X / Y / Z to rotate on axis"
# define MOUSE_MSG		"Move: Hold Left Click & Drag to translate"

// Background
# define M_BG_C		0x1E1E1E // Menu Background color
# define M_B_COLOR	0x2D2D2D
# define B_W		2 // Border width

// Structs
typedef struct s_fdf
{
	void	*mlx;
	void	*win;
}	t_fdf;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	x0;
	int	y0;
	int	z0;
	int	dx;
	int	dy;
	int	color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	int		spacing;
	int		screen_x;
	int		screen_y;
	int		current_x;
	int		current_y;
	int		**coords;
	float	offset_x;
	float	offset_y;
}	t_map;

typedef struct s_view
{
	float	zoom;
	float	offset_x;
	float	offset_y;
	float	z_scale;
	float	init_offset_x;
	float	init_offset_y;
	float	init_spacing;
	float	x_r;
	float	y_r;
	float	z_r;
}	t_view;

typedef struct s_rotations
{
	float	x;
	float	y;
	float	z;
}	t_rotations;

typedef struct s_mouse
{
	int		is_pressed;
	int		last_x;
	int		last_y;
}	t_mouse;

typedef struct s_animation
{
	int		animation_on;
	int		rotation_x;
	int		rotation_y;
	int		rotation_z;
	float	speed;
}	t_animation;

typedef struct s_menu
{
	void	*img_ptr;
	char	*addr;
	int		bits_p_pixel;
	int		l_length;
	int		endian;
	int		color;
}	t_menu;

typedef struct s_bg
{
	unsigned char	r;
	unsigned char	r1;
	unsigned char	r2;
	unsigned char	g;
	unsigned char	g1;
	unsigned char	g2;
	unsigned char	b;
	unsigned char	b1;
	unsigned char	b2;
	unsigned int	*apply;
}	t_bg;

typedef struct s_meta
{
	t_fdf		fdf;
	t_point		point;
	t_map		map;
	t_img		img;
	t_mouse		mouse;
	t_view		view;
	t_rotations	rotations;
	t_animation	animation;
	t_menu		menu;
	t_bg		bg;
}	t_meta;

#endif
