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
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define SCALE 20
# define TRUE 1
# define FALSE 0
# define ISO_ANGLE 0.523599
# define Z_SCALE 0.07

// Colors
# define PURPLE 0x800080
# define YELLOW 0xFFFF00
# define WHITE 0xFFFFFF

// Structs
typedef struct s_fdf
{
	void	*mlx;
	void	*win;
}	t_fdf;

typedef struct s_rotations
{
	float	x;
	float	y;
	float	z;
}	t_rotations;

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

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;
typedef struct s_mouse
{
	int		is_pressed;
	int		last_x;
	int		last_y;
}	t_mouse;

typedef struct s_meta
{
	t_fdf		fdf;
	t_point		point;
	t_map		map;
	t_img		img;
	t_mouse		mouse;
	t_view		view;
	t_rotations	rotations;
}	t_meta;

#endif
