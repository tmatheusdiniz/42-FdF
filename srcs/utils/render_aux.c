/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 01:22:55 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/27 01:27:12 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	put_points_x(t_meta *meta, int *i, int *j);
static void	put_points_y(t_meta *meta, int *i, int *j);

void	aux_draw_map(t_meta *meta, int *i, int *j)
{
	int	screen_next_x;
	int	screen_next_y;

	meta->map.current_x = meta->map.screen_x;
	meta->map.current_y = meta->map.screen_y;
	if (*(j) < meta->map.width - 1)
	{
		put_points_x(meta, i, j);
		project_isometric(meta, &screen_next_x, &screen_next_y);
		meta->point.x0 = meta->map.current_x;
		meta->point.y0 = meta->map.current_y;
		meta->point.x = screen_next_x;
		meta->point.y = screen_next_y;
		draw_line(meta);
	}
	if (*i < meta->map.height - 1)
	{
		put_points_y(meta, i, j);
		project_isometric(meta, &screen_next_x, &screen_next_y);
		meta->point.x0 = meta->map.current_x;
		meta->point.y0 = meta->map.current_y;
		meta->point.x = screen_next_x;
		meta->point.y = screen_next_y;
		draw_line(meta);
	}
}

static void	put_points_x(t_meta *meta, int *i, int *j)
{
	meta->point.x = *j + 1;
	meta->point.y = *i;
	meta->point.z = meta->map.coords[*i][*j + 1];
}

static void	put_points_y(t_meta *meta, int *i, int *j)
{
	meta->point.x = *j;
	meta->point.y = *i + 1;
	meta->point.z = meta->map.coords[*i + 1][*j];
}

int	get_color(t_meta *meta, int z, int min_z, int max_z)
{
	double	norm_z;

	if (z == 0)
		return (WHITE);
	if (min_z != max_z)
		norm_z = (double)(z - min_z) / (max_z - min_z);
	else
		norm_z = 0.5;
	if (z > 0)
	{
		meta->point.r = (int)(norm_z * 255);
		meta->point.g = (int)((1 - norm_z) * 128);
		meta->point.b = (int)((1 - norm_z) * 255);
	}
	else
	{
		meta->point.r = (int)((1 - norm_z) * 128);
		meta->point.g = (int)(norm_z * 255);
		meta->point.b = (int)(norm_z * 255);
	}
	meta->point.r = fmin(fmax(meta->point.r, 0), 255);
	meta->point.g = fmin(fmax(meta->point.g, 0), 255);
	meta->point.b = fmin(fmax(meta->point.b, 0), 255);
	return ((meta->point.r << 16) | (meta->point.g << 8) | meta->point.b);
}

int	color_aux(t_meta *meta, int *i, int *j)
{
	int	z;

	z = meta->map.coords[*i][*j];
	return (get_color(meta, z, meta->map.min_z, meta->map.max_z));
}
