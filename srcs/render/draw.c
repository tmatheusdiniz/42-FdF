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

void	draw_line(t_meta *meta, float old_x, float old_y)
{
	int		pixel;
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
		pixel = ((int)old_y * meta->img.line_length)
			+ ((int)old_x * (meta->img.bits_per_pixel / 8));
		*(unsigned int *)(meta->img.img_ptr + pixel) = 0x000000;
		old_x ++;
		if (p < 0)
			p = p + 2 * meta->point.dy;
		else
		{
			p = p + 2 * (meta->point.dy - meta->point.dx);
			old_y ++;
		}
	}
}


