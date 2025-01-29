/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:26:11 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/29 16:27:23 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	z_scale(t_meta *meta, int keycode)
{
	float	scale;

	scale = 0.1;
	if (keycode == KEY_O)
	{
		if (meta->view.z_scale < 0.0)
			meta->view.z_scale += 2 * scale;
		else if (meta->view.z_scale >= 0 && meta->view.z_scale < 1)
			meta->view.z_scale *= 2.0;
		else
			meta->view.z_scale *= 1.1;
	}
	else if (keycode == KEY_I)
	{
		if (meta->view.z_scale > 0.0)
			meta->view.z_scale -= 2 * scale;
		else
			meta->view.z_scale -= 2 * scale;
	}
}

void	all_rot(t_meta *meta, int keycode)
{
	if (keycode == K_ARROW_UP)
		meta->view.x_r += 5;
	else if (keycode == K_ARROW_DOWN)
		meta->view.x_r -= 5;
	else if (keycode == K_ARROW_LEFT)
		meta->view.y_r += 5;
	else if (keycode == K_ARROW_RIGHT)
		meta->view.y_r -= 5;
	else if (keycode == KEY_Q)
		meta->view.z_r += 5;
	else if (keycode == KEY_E)
		meta->view.z_r -= 5;
}
