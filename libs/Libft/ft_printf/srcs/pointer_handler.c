/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:18:52 by mreinald          #+#    #+#             */
/*   Updated: 2024/12/05 23:17:29 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	pointer_handler(va_list args, t_flags *flags)
{
	int		count;
	int		size_address;
	size_t	address;

	count = 0;
	address = va_arg(args, size_t);
	size_address = ft_hexsize(address);
	if (address == 0)
		return (count += print_null(flags->left_aligment, flags->width), count);
	if (flags->left_aligment || flags->width > 0)
		count += print_width(flags->width,
				flags->left_aligment, size_address, address);
	else if (address != 0)
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base(address, HEXBASE);
	}
	return (count);
}

int	print_width(int width, int left_aligment, int size_address, size_t number)
{
	int	count;

	count = 0;
	if (left_aligment && width > size_address + 2)
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base(number, HEXBASE);
		while (width-- > size_address + 2)
			count += ft_putchar(' ');
	}
	else if (width > size_address + 2)
	{
		while (width-- > size_address + 2)
			count += ft_putchar(' ');
		count += ft_putstr("0x");
		count += ft_putnbr_base(number, HEXBASE);
	}
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base(number, HEXBASE);
	}
	return (count);
}

int	print_null(int left_aligment, int width)
{
	int	count;

	count = 0;
	if (left_aligment)
	{
		count += ft_putstr("(nil)");
		while (width-- > 5)
			count += ft_putchar(' ');
	}
	else
	{
		while (width-- > 5)
			count += ft_putchar(' ');
		count += ft_putstr("(nil)");
	}
	return (count);
}
