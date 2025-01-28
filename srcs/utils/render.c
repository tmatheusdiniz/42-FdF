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

int	get_color(int z)
{
	if (z == 0)
		return (WHITE);
	else if (z > 0)
		return (PURPLE);
	else
		return (YELLOW);
}
