/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:53:55 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/21 17:37:29 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/define.h"
#define ISO_ANGLE 0.523599

void	calculate_offset(t_meta *meta)
{
	int	wireframe_x;
	int	wireframe_y;

	meta->map.spacing = min(WINDOW_WIDTH / meta->map.width,
			WINDOW_HEIGHT / meta->map.height);
	wireframe_x = (meta->map.width - 1) * meta->map.spacing;
	wireframe_y = (meta->map.height - 1) * meta->map.spacing;
	meta->map.offset_x = (WINDOW_WIDTH - wireframe_x) / 2.0;
	meta->map.offset_y = (WINDOW_HEIGHT - wireframe_y) / 2.0;
}

void project_isometric(t_meta *meta, float x, float y, float z, int *screen_x, int *screen_y) {
    *screen_x = (x - y) * cos(ISO_ANGLE);
    *screen_y = (x + y) * sin(ISO_ANGLE) - z;
    *screen_x += meta->map.offset_x;
    *screen_y += meta->map.offset_y;
}

void	put_pixel(t_meta *meta, float x, float y)
{
	int	pixel;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	pixel = ((int)y * meta->img.line_length)
		+ ((int)x * (meta->img.bits_per_pixel / 8));
	*(unsigned int *)(meta->img.addr + pixel) = meta->point.color;
}

void	draw_line_loop(t_meta *meta, int sx, int sy, int err)
{
	int	dx;
	int	dy;
	int	e2;

	dx =  meta->point.dx;
	dy =  meta->point.dy;
	while (1)
	{
		put_pixel(meta, meta->point.x0, meta->point.y0);
		if (meta->point.x0 == meta->point.x && meta->point.y0 == meta->point.y)
			break;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			meta->point.x0 += sx;
        }
		if (e2 < meta->point.dx)
		{
			err += dx;
			meta->point.y0 += sy;
		}
	}
}

void draw_line(t_meta *meta)
{
	int	sx;
	int	sy;
	int	err;

	meta->point.dx = abs(meta->point.x - meta->point.x0);
	meta->point.dy = abs(meta->point.y - meta->point.y0);
	err = meta->point.dx - meta->point.dy;
	if (meta->point.x0 < meta->point.x)
		sx = 1;
	else
		sx = -1;
	if (meta->point.y0 < meta->point.y)
		sy = 1;
	else
		sy = -1;
	draw_line_loop(meta, sx, sy, err);
}

void draw_wireframe(t_meta *meta)
{
    //int x, y;

    // Set map dimensions (temporary, replace with actual map reading)
    meta->map.width = 1;  // Number of columns
	meta->map.height = 1; // Number of rows

    // Calculate spacing and offsets
    calculate_offset(meta);
	draw_triangles(meta);
}

void draw_triangles(t_meta *meta) {
    float x1 = 0, y1 = -100, z1 = 50;
    float x2 = -100, y2 = 100, z2 = 0;
    float x3 = 100, y3 = 100, z3 = -50;

    int screen_x1, screen_y1;
    int screen_x2, screen_y2;
    int screen_x3, screen_y3;

    project_isometric(meta, x1, y1, z1, &screen_x1, &screen_y1);
    project_isometric(meta, x2, y2, z2, &screen_x2, &screen_y2);
    project_isometric(meta, x3, y3, z3, &screen_x3, &screen_y3);


    meta->point.x0 = screen_x1;
    meta->point.y0 = screen_y1;
    meta->point.x = screen_x2;
    meta->point.y = screen_y2;
    meta->point.color = 0xFF0000;
    draw_line(meta);

    meta->point.x0 = screen_x2;
    meta->point.y0 = screen_y2;
    meta->point.x = screen_x3;
    meta->point.y = screen_y3;
    meta->point.color = 0x00FF00;
    draw_line(meta);

    meta->point.x0 = screen_x3;
    meta->point.y0 = screen_y3;
    meta->point.x = screen_x1;
    meta->point.y = screen_y1;
    meta->point.color = 0x0000FF;
    draw_line(meta);
}
