/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:22:48 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/25 23:24:46 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	check_map(int v, char **matrix)
{
	int	size;
	int	fd;

	if (v != 2 || !matrix[1])
	{
		ft_printf("%s\n", ERR_ARGS);
		exit (1);
	}
	size = ft_strlen(matrix[1]);
	if (size <= 4 || ft_strncmp(&matrix[1][size - 4], ".fdf", 4))
	{
		ft_printf("%s\n", ERR_MAP);
		exit (1);
	}
	fd = open(matrix[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s\n", ERR_OPEN);
		exit (1);
	}
	close (fd);
	return ;
}
