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
