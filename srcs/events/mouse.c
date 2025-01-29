/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:50:04 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/16 14:53:40 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	h_mouse_press(int button, int x, int y, t_meta *meta)
{
	if (button == MOUSE_LEFT)
	{
		meta->mouse.is_pressed = TRUE;
		meta->mouse.last_x = x;
		meta->mouse.last_y = y;
	}
	else if (button == M_SCROLL_UP)
		zoom_map(meta, 1.1);
	else if (button == M_SCROLL_DOWN)
		zoom_map(meta, 0.9);
	render_map(meta);
	return (0);
}

int	h_mouse_release(int button, int x, int y, t_meta *meta)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT)
		meta->mouse.is_pressed = FALSE;
	return (0);
}

int	h_mouse_move(int x, int y, t_meta *meta)
{
	float	dx;
	float	dy;

	if (meta->mouse.is_pressed)
	{
		dx = x - meta->mouse.last_x;
		dy = y - meta->mouse.last_y;
		meta->mouse.last_x = x;
		meta->mouse.last_y = y;
		meta->view.offset_x += dx;
		meta->view.offset_y += dy;
		render_map(meta);
	}
	return (0);
}
