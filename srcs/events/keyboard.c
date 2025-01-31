/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:12:14 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/15 20:22:53 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/keys.h"

static void	move_map(t_meta *meta, int dx, int dy);
static void	reset_view(t_meta *meta);

int	handle_key_press(int keycode, t_meta *meta)
{
	if (keycode == KEY_ESC)
		clean_all(meta);
	else if (keycode == KEY_W)
		move_map(meta, 0, -10);
	else if (keycode == KEY_S)
		move_map(meta, 0, 10);
	else if (keycode == KEY_A)
		move_map(meta, -10, 0);
	else if (keycode == KEY_D)
		move_map(meta, 10, 0);
	else if (keycode == KEY_I || keycode == KEY_O)
		z_scale(meta, keycode);
	else if (keycode == K_ARROW_UP || keycode == K_ARROW_DOWN
		|| keycode == K_ARROW_LEFT || keycode == K_ARROW_RIGHT
		|| keycode == KEY_Q || keycode == KEY_E)
		all_rot(meta, keycode);
	else if (keycode == KEY_X || keycode == KEY_Y || keycode == KEY_Z)
		define_axis(meta, keycode);
	else if (keycode == KEY_R)
		reset_view(meta);
	render_map(meta);
	return (0);
}

static void	move_map(t_meta *meta, int dx, int dy)
{
	meta->view.offset_x += dx;
	meta->view.offset_y += dy;
}

void	zoom_map(t_meta *meta, float factor)
{
	meta->view.zoom *= factor;
	if (meta->view.zoom < 0.1)
		meta->view.zoom = 0.1;
	if (meta->view.zoom > 10)
		meta->view.zoom = 10;
}

static void	reset_view(t_meta *meta)
{
	meta->view.zoom = 1.0;
	meta->view.z_scale = 1.0;
	meta->view.x_r = 0;
	meta->view.y_r = 0;
	meta->view.z_r = 0;
	meta->view.offset_x = meta->view.init_offset_x;
	meta->view.offset_y = meta->view.init_offset_y;
	meta->map.spacing = meta->view.init_spacing;
}
