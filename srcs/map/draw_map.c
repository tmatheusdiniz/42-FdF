/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:04:26 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/30 23:04:50 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	render_map(t_meta *meta)
{
	ft_memset(meta->img.addr, 0, WINDOW_WIDTH * WINDOW_HEIGHT
		* (meta->img.bits_per_pixel / 8));
	draw_map(meta);
	mlx_put_image_to_window(meta->fdf.mlx, meta->fdf.win,
		meta->img.img_ptr, 0, 0);
	draw_menu(meta);
}
