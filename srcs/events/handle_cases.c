/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:51:44 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/28 16:52:11 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void setup_hooks(t_meta *meta)
{
	mlx_hook(meta->fdf.win, 2, 1L<<0, handle_key_press, meta);
	//mlx_mouse_hook(meta->fdf.win, handle_mouse_press, meta);
	mlx_hook(meta->fdf.win, 17, 0, clean_all, meta);
	//mlx_hook(meta->fdf.win, 5, 1L<<3, handle_mouse_release, meta);
	//mlx_hook(meta->fdf.win, 6, 1L<6, handle_mouse_move, meta);
}

