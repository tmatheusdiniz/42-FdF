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
	*screen_x = (meta->point.x - meta->point.y) * cos(ISO_ANGLE);
	*screen_y = (meta->point.x + meta->point.y)
		* sin(ISO_ANGLE) - meta->point.z;
	*screen_x += meta->map.offset_x;
	*screen_y += meta->map.offset_y;
}
