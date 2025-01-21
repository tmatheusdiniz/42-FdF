/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:58:20 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/25 16:07:24 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putchar(int c)
{
	int	printed;

	printed = write(STDOUT_FILENO, &c, 1);
	if (printed == -1)
		return (-1);
	else
		return (printed);
}
