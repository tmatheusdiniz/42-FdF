/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:47:14 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/26 22:47:50 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	project_isometric(t_meta *meta, int *screen_x, int *screen_y)
{
	float	x;
	float	y;
	float	z;

	if (meta->conic.projection_on)
	{
		project_conic(meta, screen_x, screen_y);
		return ;
	}
	x = meta->point.x * meta->map.spacing * meta->view.zoom;
	y = meta->point.y * meta->map.spacing * meta->view.zoom;
	z = meta->point.z * (meta->map.spacing * Z_SCALE)
		* meta->view.zoom * meta->view.z_scale;
	if (meta->view.x_r != 0 || meta->view.y_r != 0 || meta->view.z_r != 0)
		rotation(meta, &x, &y, &z);
	*screen_x = (x - y) * cos(ISO_ANGLE);
	*screen_y = (x + y)
		* sin(ISO_ANGLE) - z;
	*screen_x += meta->view.offset_x;
	*screen_y += meta->view.offset_y;
}

void	handle_conic(t_meta *meta)
{
	meta->conic.projection_on = !meta->conic.projection_on;
	if (meta->conic.projection_on)
	{
		meta->view.zoom = 0.8f;
		meta->view.offset_x = 0;
		meta->view.offset_y = 0;
		meta->view.x_r = 0;
		meta->view.y_r = 0;
		meta->view.z_r = 0;
		meta->view.z_scale = 1.0;
	}
	else
		reset_view(meta);
}

void	project_conic(t_meta *meta, int *screen_x, int *screen_y)
{
	float	x;
	float	y;
	float	z;
	float	z_perspec;
	float	z_offset;

	x = meta->point.x * meta->map.spacing;
	y = meta->point.y * meta->map.spacing;
	z = meta->point.z * (meta->map.spacing * Z_SCALE)
		* meta->view.z_scale;
	if (meta->view.x_r != 0 || meta->view.y_r != 0 || meta->view.z_r != 0)
		rotation(meta, &x, &y, &z);
	meta->conic.distance = 2000.0f;
	z_offset = 1000.0f;
	z_perspec = z + z_offset;
	if (z_perspec <= 0)
		z_perspec = 1;
	*screen_x = (int)(x * meta->conic.distance / z_perspec);
	*screen_y = (int)(y * meta->conic.distance / z_perspec);
	*screen_x = (int)(*screen_x - WINDOW_WIDTH / 6.1) // 2.5
		* meta->view.zoom + WINDOW_WIDTH / 2.0;
	*screen_y = (int)(*screen_y - WINDOW_HEIGHT / 3) // 4.0
		* meta->view.zoom + WINDOW_HEIGHT / 2.0;
	*screen_x += meta->view.offset_x;
	*screen_y += meta->view.offset_y;
}

void	init_conic(t_meta *meta)
{
	meta->conic.fov = 60.0;
	meta->conic.near = 0.1;
	meta->conic.far = 1000.0;
	meta->conic.projection_on = 0;
	meta->conic.distance = 2000.0f;
}

void	reset_conic(t_meta *meta)
{
	meta->view.zoom = 0.8f;
	meta->view.z_scale = 1.0;
	meta->view.x_r = 0;
	meta->view.y_r = 0;
	meta->view.z_r = 0;
	meta->view.offset_x = 0;
	meta->view.offset_y = 0;
	meta->map.spacing = meta->view.init_spacing;
}
