/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:09:30 by mreinald          #+#    #+#             */
/*   Updated: 2025/02/02 15:09:50 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
	}
	return (1);
}

int	check_is_number(const char *str)
{
	while (*str && *str != ',')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str ++;
	}
	return (1);
}
