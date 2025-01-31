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

int	check_hex(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
			i += 2;
		else
			return (0);
		if (!((str[i] >= '0' && str[i] <= '9')
				|| (str[i] >= 'a' && str[i] <= 'f')
				|| (str[i] >= 'A' && str[i] <= 'F')))
			return (0);
		i ++;
	}
	return (1);
}

int	check_after_comma(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
	}
	return (1);
}

int	check_is_number(const char *str)
{
	int	i;

	i = 0;
	while (*str && *str != ',')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str ++;
	}
	return (1);
}
