/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:28:31 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/29 19:48:27 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static float	to_radians(float degree)
{
	return (degree * M_PI / 180.0f);
}

void	rotation(t_meta *meta, float *x, float *y, float *z)
{
	meta->rotations.x = *x;
	meta->rotations.y = *y;
	meta->rotations.z = *z;
	rotation_x(meta, meta->view.x_r);
	rotation_y(meta, meta->view.y_r);
	rotation_z(meta, meta->view.z_r);
	*x = meta->rotations.x;
	*y = meta->rotations.y;
	*z = meta->rotations.z;
}

void	rotation_x(t_meta *meta, float degree)
{
	float	rad;
	float	currently_y;
	float	currently_z;

	rad = to_radians(degree);
	currently_y = meta->rotations.y;
	currently_z = meta->rotations.z;
	meta->rotations.y = currently_y * cos(rad) - currently_z * sin(rad);
	meta->rotations.z = currently_y * sin(rad) + currently_z * cos(rad);
}

void	rotation_y(t_meta *meta, float degree)
{
	float	rad;
	float	currently_x;
	float	currently_z;

	rad = to_radians(degree);
	currently_x = meta->rotations.x;
	currently_z = meta->rotations.z;
	meta->rotations.x = currently_x * cos(rad) + currently_z * sin(rad);
	meta->rotations.z = currently_z * cos(rad) - currently_x * sin(rad);
}

void	rotation_z(t_meta *meta, float degree)
{
	float	rad;
	float	currently_x;
	float	currently_y;

	rad = to_radians(degree);
	currently_x = meta->rotations.x;
	currently_y = meta->rotations.y;
	meta->rotations.x = currently_x * cos(rad) - currently_y * sin(rad);
	meta->rotations.y = currently_x * sin(rad) + currently_y * cos(rad);
}
