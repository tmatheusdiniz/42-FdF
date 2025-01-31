/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:08:17 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/11 15:09:39 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/Libft/include/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "./define.h"
# include "./error.h"
# include "./keys.h"

// Core
int		main(int v, char **str);

// Render
void	draw_line(t_meta *meta);
void	draw_line_loop(t_meta *meta, int sx, int sy, int err);
void	draw_map(t_meta *meta);
void	put_pixel(t_meta *meta, float x, float y);
void	calculate_offset(t_meta *meta);
void	render_map(t_meta *meta);

// Map
void	read_map(t_meta *meta, char *path);
void	get_coordinates(t_meta *meta, char *path);
void	init_map(t_meta *meta);
int		map_columns(t_meta *meta, char *line);

// Projections
void	project_isometric(t_meta *meta, int *screen_x, int *screen_y);

// Rotations
void	rotation(t_meta *meta, float *x, float *y, float *z);
void	rotation_x(t_meta *meta, float degree);
void	rotation_y(t_meta *meta, float degree);
void	rotation_z(t_meta *meta, float degree);

// Background
void	draw_menu(t_meta *meta);
void	draw_menu_background(t_meta *meta);

// Animation
int		start_animation(t_meta *meta);
void	init_animation(t_meta *meta);
void	choose_rotation(t_meta *meta, int flag);
void	define_axis(t_meta *meta, int keycode);

// Menu
void	start_menu(t_meta *meta);
void	render_menu(t_meta *meta);
void	move_box(t_meta *meta);
void	put_pixel_menu(t_meta *meta, float x, float y);

// Events
void	setup_hooks(t_meta *meta);

// Events Mouse
int		h_mouse_press(int button, int x, int y, t_meta *meta);
int		h_mouse_release(int button, int x, int y, t_meta *meta);
int		h_mouse_move(int x, int y, t_meta *meta);

// Events keycodes
int		handle_key_press(int keycode, t_meta *meta);
void	zoom_map(t_meta *meta, float factor);

// Utils
void	aux_draw_map(t_meta *meta, int *i, int *j);
void	handler_errors(t_meta *meta, char *message);
void	check_map(int v, char *path);
void	print_string(t_meta *meta, int x, int y, char *str);
void	z_scale(t_meta *meta, int keycode);
void	all_rot(t_meta *meta, int keycode);
void	draw_m_background(t_meta *meta);
int		clean_all(t_meta *meta);
int		get_color(int z);
int		min(int a, int b);

#endif
