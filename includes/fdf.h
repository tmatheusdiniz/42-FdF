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
void	render_map(t_meta *meta);
void	draw_map(t_meta *meta);
void	draw_line(t_meta *meta);
void	draw_line_loop(t_meta *meta, int sx, int sy, int err);
void	put_pixel(t_meta *meta, float x, float y);
void	calculate_offset(t_meta *meta);

// Map
void	read_map(t_meta *meta, char *path);
void	get_coordinates(t_meta *meta, char *path);
void	init_map(t_meta *meta);
int		map_columns(t_meta *meta, char *line);

//  -- Projections --

// Isomtric
void	project_isometric(t_meta *meta, int *screen_x, int *screen_y);

// Conic
void	project_conic(t_meta *meta, int *screen_x, int *screen_y);
void	handle_conic(t_meta *meta);
void	init_conic(t_meta *meta);

// -- --!

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

// -- Events --
void	setup_hooks(t_meta *meta);

// Events Mouse
int		h_mouse_press(int button, int x, int y, t_meta *meta);
int		h_mouse_release(int button, int x, int y, t_meta *meta);
int		h_mouse_move(int x, int y, t_meta *meta);

// Events keycodes
int		handle_key_press(int keycode, t_meta *meta);
void	zoom_map(t_meta *meta, float factor);
void	z_scale(t_meta *meta, int keycode);
void	all_rot(t_meta *meta, int keycode);

// -- --!

// -- Utils --

// Handle Errors - Clean
void	handler_errors(t_meta *meta, char *message);
int		clean_all(t_meta *meta);

// Aux Render
void	aux_draw_map(t_meta *meta, int *i, int *j);

// Aux Check Map
void	check_map(int v, char *path);
int		check_is_number(const char *str);
int		check_after_comma(const char *str);
int		check_hex(const char *str);

// Aux Background
void	draw_m_background(t_meta *meta);
int		get_color(t_meta *meta, int z, int min_z, int max_z);
int		color_aux(t_meta *meta, int *i, int *j);

// General
int		min(int a, int b);
void	reset_conic(t_meta *meta);
void	reset_view(t_meta *meta);

// -- --!

#endif
