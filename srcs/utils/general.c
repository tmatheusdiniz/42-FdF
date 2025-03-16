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

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	clear_gnl(int fd)
{
	char	*temp;

	temp = get_next_line(fd);
	while (temp != NULL)
	{
		free(temp);
		temp = get_next_line(fd);
	}
}

void	find_z_bounds(t_meta *meta)
{
	int	i;
	int	j;

	meta->map.min_z = 2147483647;
	meta->map.max_z = -2147483648;
	i = 0;
	while (i < meta->map.height)
	{
		j = 0;
		while (j < meta->map.width)
		{
			meta->map.min_z = fmin(meta->map.min_z, meta->map.coords[i][j]);
			meta->map.max_z = fmax(meta->map.max_z, meta->map.coords[i][j]);
			j++;
		}
		i++;
	}
}
