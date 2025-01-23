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

#include "../../includes/define.h"

void	put_pixel(t_meta *meta, float x, float y, int color)
{
	int	pixel;

	x += OFFSET_X;
	y += OFFSET_Y;
	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT) 
		return;
	pixel = ((int)y * meta->img.line_length)
		+ ((int)x * (meta->img.bits_per_pixel / 8));
	*(unsigned int *)(meta->img.addr + pixel) = color;
}

void	draw_line(t_meta *meta, float old_x, float old_y, int color)
{
	float	p;
	float	x;
	float	y;

	x = meta->point.x;
	y = meta->point.y;
	meta->point.dx = x - old_x;
	meta->point.dy = y - old_y;
	p = 2 * meta->point.dy - meta->point.dx;
	while (old_x <= x)
	{
		put_pixel(meta, old_x, old_y, color);
		old_x++;
		if (p < 0)
			p = p + 2 * meta->point.dy;
		else
		{
			p = p + 2 * (meta->point.dy - meta->point.dx);
			old_y ++;
		}
	}
}

void    draw_wireframe(t_meta *meta)
{
    int x, y;

    for (x = 0; x < 800; x += 50)
    {
        for (y = 0; y < 600; y++)
        {
            put_pixel(meta, x, y, 0x00FF00);  // Vertical green lines
        }
    }
    for (y = 0; y < 600; y += 50)
    {
        for (x = 0; x < 800; x++)
        {
            put_pixel(meta, x, y, 0x0000FF);  // Horizontal blue lines
        }
    }
    put_pixel(meta, 400, 100, 0xFF0000);  // Top point (red)
    put_pixel(meta, 350, 200, 0xFF0000);  // Bottom left point (red)
    put_pixel(meta, 450, 200, 0xFF0000);  // Bottom right point (red)
}
