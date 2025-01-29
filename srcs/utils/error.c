/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:38:42 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/15 14:46:34 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	free_mlx_data(t_meta *meta);

static void	free_map_data(t_meta *meta)
{
	int	i;

	i = 0;
	if (meta->map.coords)
	{
		i = 0;
		while (i < meta->map.height)
		{
			free(meta->map.coords[i]);
			i++;
		}
		free(meta->map.coords);
	}
}

static void	free_mlx_data(t_meta *meta)
{
	if (meta->img.img_ptr)
		mlx_destroy_image(meta->fdf.mlx, meta->img.img_ptr);
	if (meta->fdf.win)
		mlx_destroy_window(meta->fdf.mlx, meta->fdf.win);
	if (meta->fdf.mlx)
	{
		mlx_destroy_display(meta->fdf.mlx);
		free (meta->fdf.mlx);
	}
}

int	clean_all(t_meta *meta)
{
	free_map_data(meta);
	free_mlx_data(meta);
	exit(0);
	return (0);
}

void	handler_errors(t_meta *meta, char *message)
{
	if (message)
		ft_printf("%s\n", message);
	if (meta)
	{
		free_map_data(meta);
		free_mlx_data(meta);
	}
	exit (1);
}
