/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:53:56 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/11 14:54:11 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	init_view(t_meta *meta);

static int	initialize_mlx(t_meta *meta)
{
	meta->fdf.mlx = mlx_init();
	if (!meta->fdf.mlx)
		return (0);
	meta->fdf.win = mlx_new_window(meta->fdf.mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	if (!meta->fdf.win)
	{
		mlx_destroy_display(meta->fdf.mlx);
		free (meta->fdf.mlx);
		return (0);
	}
	meta->img.img_ptr = mlx_new_image(meta->fdf.mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!meta->img.img_ptr)
	{
		mlx_destroy_window(meta->fdf.mlx, meta->fdf.win);
		mlx_destroy_display(meta->fdf.mlx);
		free (meta->fdf.mlx);
		return (0);
	}
	meta->img.addr = mlx_get_data_addr(meta->img.img_ptr,
			&meta->img.bits_per_pixel,
			&meta->img.line_length, &meta->img.endian);
	init_view(meta);
	return (1);
}

static void	init_view(t_meta *meta)
{
	if (meta->map.width <= 0 || meta->map.height <= 0)
		handler_errors(meta, "Invalid map dimensions");
	meta->view.zoom = 1.0;
	calculate_offset(meta);
	meta->view.init_offset_x = meta->map.offset_x;
	meta->view.init_offset_y = meta->map.offset_y;
	meta->view.offset_x = meta->view.init_offset_x;
	meta->view.offset_y = meta->view.init_offset_y;
	meta->view.init_spacing = meta->map.spacing;
}

int	main(int c, char **str)
{
	t_meta	meta;

	check_map(c, str);
	ft_memset(&meta, 0, sizeof(t_meta));
	read_map(&meta, str[1]);
	if (!(initialize_mlx(&meta)))
		handler_errors(&meta, ERR_MLX);	
	draw_map(&meta);
	mlx_put_image_to_window(meta.fdf.mlx, meta.fdf.win, meta.img.img_ptr, 0, 0);
	setup_hooks(&meta);
	mlx_loop(meta.fdf.mlx);
}
