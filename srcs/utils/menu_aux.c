/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:27:49 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/30 17:42:27 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	print_string(t_meta *meta, int x, int y, char *str)
{
	mlx_string_put(meta->fdf.mlx, meta->fdf.win, x, y, M_STR_COLOR, str);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
