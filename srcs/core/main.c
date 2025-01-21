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
#include "../../includes/errors.h"

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
			WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100);
	if (!meta->img.img_ptr)
	{
		mlx_destroy_window(meta->fdf.mlx, meta->fdf.win);
		free (meta->fdf.mlx);
		return (0);
	}
	meta->img.img_ptr = mlx_get_data_addr(meta->img.img_ptr,
			&meta->img.bits_per_pixel,
			&meta->img.line_length, &meta->img.endian);
	return (1);
}

int	main(int c, char **str)
{
	t_meta	meta;

	ft_memset(&meta, 0, sizeof(t_meta));
	if (c != 2)
		ft_printf("Usage: ./bin/fdf /maps/choose a map");
	if (!(initialize_mlx(&meta)))
		handler_errors(&meta, ERR_MLX);
	mlx_loop(meta.fdf.mlx);
}
