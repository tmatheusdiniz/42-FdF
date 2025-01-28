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

void	calculate_offset(t_meta *meta)
{
	int	wireframe_x;
	int	wireframe_y;

	meta->map.spacing = min((WINDOW_WIDTH / 2) / meta->map.width,
			(WINDOW_HEIGHT / 2) / meta->map.height);
	if (meta->map.spacing < 1)
		meta->map.spacing = 1;
	wireframe_x = (meta->map.width - 1) * meta->map.spacing;
	wireframe_y = (meta->map.height - 1) * meta->map.spacing;
	meta->map.offset_x = (WINDOW_WIDTH - wireframe_x) / 2.0;
	meta->map.offset_y = (WINDOW_HEIGHT - wireframe_y) / 2.0;
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
	int max_iterations = WINDOW_WIDTH + WINDOW_HEIGHT; // Número máximo de iterações esperadas
	int iteration_count = 0;
	dx = meta->point.dx;
	dy = meta->point.dy;
	while (1)
	{
		if (meta->point.x0 >= 0 && meta->point.x < WINDOW_WIDTH &&
        	meta->point.y0 >= 0 && meta->point.y < WINDOW_HEIGHT)
        {
            put_pixel(meta, meta->point.x0, meta->point.y0);
        }
		//put_pixel(meta, meta->point.x0, meta->point.y0);
		if (meta->point.x0 == meta->point.x && meta->point.y0 == meta->point.y)
			break ;
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
		iteration_count++;
    	if (iteration_count > max_iterations)
    	{
			ft_printf("%i\n", iteration_count);
        	ft_printf("Erro: Loop infinito detectado!\n");
        	break;
    	}
	}
}

void	draw_line(t_meta *meta)
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

void	draw_map(t_meta *meta)
{
	int	i;
	int	j;

	i = 0;
	calculate_offset(meta);
	while (i < meta->map.height)
	{
		j = 0;
		while (j < meta->map.width)
		{
			meta->point.x = j;
			meta->point.y = i;
			meta->point.z = meta->map.coords[i][j];
			project_isometric(meta, &meta->map.screen_x, &meta->map.screen_y);
			meta->point.color = get_color(meta->point.z);
			aux_draw_map(meta, &i, &j);
			j ++;
		}
		i ++;
	}
}
