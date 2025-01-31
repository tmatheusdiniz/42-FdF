/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:39:48 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/30 19:57:03 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static unsigned int	rgb_c(t_meta *meta, unsigned int color_1,
						unsigned int color_2, float alpha);

static unsigned int	rgb_c(t_meta *meta,
		unsigned int color_1, unsigned int color_2, float alpha)
{
	meta->bg.r1 = (color_1 >> 16) & 0xFF;
	meta->bg.g1 = (color_1 >> 8) & 0xFF;
	meta->bg.b1 = color_1 & 0xFF;
	meta->bg.r2 = (color_2 >> 16) & 0xFF;
	meta->bg.g2 = (color_2 >> 8) & 0xFF;
	meta->bg.b2 = color_2 & 0xFF;
	meta->bg.r = meta->bg.r1 + (meta->bg.r2 - meta->bg.r1) * alpha;
	meta->bg.g = meta->bg.g1 + (meta->bg.g2 - meta->bg.g1) * alpha;
	meta->bg.b = meta->bg.b1 + (meta->bg.b2 - meta->bg.b1) * alpha;
	return ((meta->bg.r << 16) | (meta->bg.g << 8) | meta->bg.b);
}

void	draw_menu_background(t_meta *meta)
{
	int				i;
	int				j;
	int				pixel;
	float			fade;

	meta->bg.apply = (unsigned int *)meta->menu.addr;
	i = 0;
	while (i < MENU_HEIGHT)
	{
		j = 0;
		while (j < MENU_WIDTH)
		{
			pixel = (i * MENU_WIDTH) + j;
			fade = (float)j / B_W;
			if (j < B_W)
				meta->bg.apply[pixel] = rgb_c(meta, M_B_COLOR, M_BG_C, fade);
			else if (j > MENU_WIDTH - B_W)
				meta->bg.apply[pixel] = rgb_c(meta, M_BG_C, M_B_COLOR,
						(float)(j - (MENU_WIDTH - B_W)) / B_W);
			else
				meta->bg.apply[pixel] = M_BG_C;
			j++;
		}
		i++;
	}
}

void	draw_menu(t_meta *meta)
{
	ft_memset(meta->menu.addr, 0, MENU_WIDTH * MENU_HEIGHT
		* (meta->menu.bits_p_pixel / 8));
	draw_menu_background(meta);
	mlx_put_image_to_window(meta->fdf.mlx, meta->fdf.win,
		meta->menu.img_ptr, 0, 0);
	render_menu(meta);
}
