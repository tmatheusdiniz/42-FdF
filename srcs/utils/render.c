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

void	aux_draw_map(t_meta *meta, int *i, int *j)
{
	int	screen_next_x;
	int	screen_next_y;

	if (*(j) < meta->map.width - 1)
	{
		meta->point.x ++;
		meta->point.z = meta->map.coords[*i][*j + 1];
		project_isometric(meta, &screen_next_x, &screen_next_y);
		meta->point.x0 = meta->map.screen_x;
		meta->point.y0 = meta->map.screen_y;
		meta->point.x = screen_next_x;
		meta->point.y = screen_next_y;
		draw_line(meta);
	}
	if (*(i) < meta->map.height)
	{
		meta->point.y ++;
		meta->point.z = meta->map.coords[*i + 1][*j];
		project_isometric(meta, &screen_next_x, &screen_next_y);
		meta->point.x0 = meta->map.screen_x;
		meta->point.y0 = meta->map.screen_y;
		meta->point.x = screen_next_x;
		meta->point.y = screen_next_y;
		draw_line(meta);
	}
}

int	get_color(int z)
{
	if (z == 0)
		return (WHITE);
	else if (z > 0)
		return (PURPLE);
	else
		return (YELLOW);
}
