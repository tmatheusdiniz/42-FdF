/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:47:14 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/26 22:47:50 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	project_isometric(t_meta *meta, int *screen_x, int *screen_y)
{
	float	x;
	float	y;
	float	z;

	x = meta->point.x * meta->map.spacing;
	y = meta->point.y * meta->map.spacing;
	z = meta->point.z * (meta->map.spacing * Z_SCALE);
	*screen_x = (x - y) * cos(ISO_ANGLE);
	*screen_y = (x + y)
		* sin(ISO_ANGLE) - z;
	*screen_x += meta->map.offset_x;
	*screen_y += meta->map.offset_y;
}
