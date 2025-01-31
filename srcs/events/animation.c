/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:08:37 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/30 13:35:48 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	init_animation(t_meta *meta)
{
	meta->animation.animation_on = FALSE;
	meta->animation.speed = 0;
	meta->animation.rotation_x = FALSE;
	meta->animation.rotation_y = FALSE;
	meta->animation.rotation_z = FALSE;
}

//this approach of making
//meta->animation.rotation_x = !meta->animation.rotation_x,
//and the same for all axes
//is to it can be stopped case the user clicks on x, y or z again.
void	choose_rotation(t_meta *meta, int flag)
{
	if (flag == 1)
		meta->animation.rotation_x = !meta->animation.rotation_x;
	if (flag == 2)
		meta->animation.rotation_y = !meta->animation.rotation_y;
	if (flag == 3)
		meta->animation.rotation_z = !meta->animation.rotation_z;
}

int	start_animation(t_meta *meta)
{
	if (!meta->animation.animation_on)
		return (0);
	if (!meta->animation.speed && meta->animation.animation_on)
		meta->animation.speed = 1.5;
	if (meta->animation.rotation_x)
		meta->view.x_r += meta->animation.speed;
	if (meta->animation.rotation_y)
		meta->view.y_r += meta->animation.speed;
	if (meta->animation.rotation_z)
		meta->view.z_r += meta->animation.speed;
	meta->view.x_r = fmod(meta->view.x_r, 360.0);
	meta->view.y_r = fmod(meta->view.y_r, 360.0);
	meta->view.z_r = fmod(meta->view.z_r, 360.0);
	ft_memset(meta->img.addr, 0, WINDOW_WIDTH * WINDOW_HEIGHT
		* (meta->img.bits_per_pixel / 8));
	draw_map(meta);
	mlx_put_image_to_window(meta->fdf.mlx, meta->fdf.win,
		meta->img.img_ptr, 0, 0);
	draw_menu(meta);
	return (0);
}

void	define_axis(t_meta *meta, int keycode)
{
	if (keycode == KEY_X)
		choose_rotation(meta, 1);
	if (keycode == KEY_Y)
		choose_rotation(meta, 2);
	if (keycode == KEY_Z)
		choose_rotation(meta, 3);
}
