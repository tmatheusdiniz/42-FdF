/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:08:17 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/11 15:09:39 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/Libft/include/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "./define.h"
# include "./error.h"
# include "./keys.h"
# include <math.h>

// Core
int			main(int v, char **str);
static int	initialize_mlx(t_meta *meta);

// Utils
void	handler_errors(t_meta *meta, char *message);

// Events
int handle_key_press(int keycode, t_meta *meta);
void setup_hooks(t_meta *meta);
int handle_mouse_press(int button, int x, int y, t_meta *meta);
int handle_mouse_release(int button, int x, int y, t_meta *meta);
int handle_mouse_move(int x, int y, t_meta *meta);

#endif
