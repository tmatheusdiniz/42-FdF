/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:12:14 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/15 20:22:53 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/keys.h"

int handle_key_press(int keycode, t_meta *meta)
{
	if (keycode == KEY_ESC)
		handler_errors(meta, "exit esc");
	else if (keycode == KEY_W)
		move_map(meta, 0, -10);
	else if (keycode == KEY_S)
		move_map(meta, 0, 10);
	else if (keycode == KEY_A)
		move_map(meta, -10, 0);
	else if (keycode == KEY_D)
		move_map(meta, 10, 0);
	else if (keycode == KEY_PLUS)
		zoom_map(meta, 1.1);
	else if (keycode == KEY_MINUS)
		zoom_map(meta, 0.9);
	else if (keycode == KEY_R)
		reset_view(meta);
	render_map(meta);
	return (0);
}

void setup_hooks(t_meta *meta)
{
	mlx_hook(meta->fdf.win, 2, 1L<<0, handle_key_press, meta);
	mlx_hook(meta->fdf.win, 17, 0, handle_close, meta);
	mlx_mouse_hook(meta->fdf.win, handle_mouse_press, meta);
	mlx_hook(meta->fdf.win, 5, 1L<<3, handle_mouse_release, meta);
	mlx_hook(meta->fdf.win, 6, 1L<<6, handle_mouse_move, meta);
}

int handle_close(void *param)
{
    t_meta *meta = (t_meta *)param;

    // Clean up MLX resources
    mlx_destroy_image(meta->fdf.mlx, meta->img.img_ptr);
    mlx_destroy_window(meta->fdf.mlx, meta->fdf.win);

    // Exit the program
    exit(0);
    return (0);
}
