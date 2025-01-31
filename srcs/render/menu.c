/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:39:48 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/30 16:42:32 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	start_menu(t_meta *meta)
{
	meta->menu.img_ptr = mlx_new_image(meta->fdf.mlx, MENU_WIDTH, MENU_HEIGHT);
	if (!meta->menu.img_ptr)
		handler_errors(meta, ERR_MLX);
	meta->menu.addr = mlx_get_data_addr(meta->menu.img_ptr,
			&meta->menu.bits_p_pixel, &meta->menu.l_length, &meta->menu.endian);
}

void	render_menu(t_meta *meta)
{
	int	y;

	y = CONTROL_BOX;
	print_string(meta, MENU_X, y, " /// CONTROLS ///");
	y += SPACE_B_LINES;
	print_string(meta, MENU_X + 10, y, "Zoom: Scroll Up / Down");
	y += SPACE_B_LINES;
	print_string(meta, MENU_X + 10, y, "For change perspective: Press c");
	y += SPACE_B_LINES;
	print_string(meta, MENU_X + 10, y, "For come back: Press f");
	move_box(meta);
}

void	move_box(t_meta *meta)
{
	int	y;

	y = MOVES_BOX;
	print_string(meta, MENU_X, y, " /// MOVEMENT CONTROLS ///");
	y += SPACE_B_LINES;
	print_string(meta, MENU_X + 10, y, "Translate:");
	y += SPACE_B_LINES - 10;
	print_string(meta, MENU_X + 20, y, TRANSLATE_MSG);
	y += SPACE_B_LINES - 10;
	print_string(meta, MENU_X + 20, y, "Z-Axis: I (Up) / O (Down)");
	y += SPACE_B_LINES - 10;
	print_string(meta, MENU_X + 20, y, MOUSE_MSG);
	y += SPACE_B_LINES;
	print_string(meta, MENU_X + 10, y, "Rotation:");
	y += SPACE_B_LINES - 10;
	print_string(meta, MENU_X + 20, y, ROTATION_MSG);
	y += SPACE_B_LINES - 10;
	print_string(meta, MENU_X + 20, y, ROTATION_Z_MSG);
	y += SPACE_B_LINES;
	print_string(meta, MENU_X + 10, y, "Animation:");
	y += SPACE_B_LINES - 10;
	print_string(meta, MENU_X + 10, y, ANIMATION_MSG);
	y += SPACE_B_LINES;
	print_string(meta, MENU_X + 10, y, "Press ESC for exit!!!");
}
