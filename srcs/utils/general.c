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

void	find_z_bounds(t_meta *meta, int *min_z, int *max_z)
{
	int	i;
	int	j;

	*min_z = 2147483647;
	*max_z = -2147483648;
	i = 0;
	while (i < meta->map.height)
	{
		j = 0;
		while (j < meta->map.width)
		{
			*min_z = fmin(*min_z, meta->map.coords[i][j]);
			*max_z = fmax(*max_z, meta->map.coords[i][j]);
			j++;
		}
		i++;
	}
}
