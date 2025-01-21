/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:27:18 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/28 16:09:07 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	char_handler(va_list args, t_flags *flags)
{
	int		count;
	char	c;

	count = 0;
	c = va_arg(args, int);
	if (flags->left_aligment && flags->width)
	{
		count += ft_putchar(c);
		while ((flags->width)-- > 1)
			count += ft_putchar(' ');
	}
	else if (flags->width && !(flags->left_aligment))
	{
		while ((flags->width)-- > 1)
			count += ft_putchar(' ');
		count += ft_putchar(c);
	}
	else
		count += ft_putchar(c);
	return (count);
}
