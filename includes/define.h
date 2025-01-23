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

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define SCALE 20
# define TRUE 1
# define FALSE 0
# define PURPLE 0x800080
# define YELLOW 0xFFFF00
# define WHITE 0xFFFFFF
# define OFFSET_X 100
# define OFFSET_Y 50

// Structs
typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		shift_x;
	int		shift_y;
	int		projection;
	double	scale;
	double	angle;
} t_fdf;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	float	dx;
	float	dy;
	int		color;
} t_point;

typedef struct s_map
{
	int	width;
	int	heigth;
	int	**coords;
	int	**colors;
} t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_img;
typedef struct s_mouse
{
	int		is_pressed;
	int		last_x;
	int		last_y;
} t_mouse;

typedef struct s_meta
{
	t_fdf	fdf;
	t_point	point;
	t_map	map;
	t_img	img;
	t_mouse	mouse;
} t_meta;

#endif
