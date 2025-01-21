/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsignedint_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:58:15 by mreinald          #+#    #+#             */
/*   Updated: 2024/12/08 00:58:47 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	unsignedint_handler(va_list args, t_flags *flags)
{
	unsigned int	number;
	int				count;
	int				numbersize;

	number = va_arg(args, unsigned int);
	count = 0;
	numbersize = ft_numsize_unsig(number);
	if ((flags->left_aligment || flags->width > 0)
		&& (number == 0 && flags->precision <= 1))
		return (count += aux_unsigned(flags), count);
	if (flags->left_aligment)
		count += unsignedint_leftalig(number, numbersize,
				flags, flags->precision - 1);
	else if (flags->width && flags->width > 0)
		count += unsignedint_w(number, numbersize, flags, flags->precision - 1);
	else if (flags->precision && flags->precision > 0)
	{
		if (number == 0 && flags->precision - 1 == 0)
			return (0);
		count += unsignedint_prec(number, flags->precision - 1);
	}
	else
		count += ft_putnbr_unsig(number);
	return (count);
}

int	unsignedint_leftalig(long int number, int numbersize,
		t_flags *flags, int precision)
{
	int	count;

	count = 0;
	if (number == 0 && precision <= 0 && !flags->width)
	{
		while (flags->width-- > 0)
			count += ft_putchar(' ');
		return (count);
	}
	if (flags->width > 0)
		count += unsignedint_w_l(number, flags, precision);
	else if (precision > numbersize)
		count += unsignedint_prec(number, precision);
	else
		count += ft_putnbr(number);
	return (count);
}

int	unsignedint_prec(long int number, int precision)
{
	int	count;
	int	numbersize;

	count = 0;
	numbersize = ft_numsize(number);
	if (precision > numbersize)
	{
		while (precision-- > numbersize)
			count += ft_putchar('0');
		count += ft_putnbr(number);
	}
	else
		count += ft_putnbr(number);
	return (count);
}

int	unsignedint_w(long int number, int numbersize,
		t_flags *flags, int precision)
{
	int	count;

	count = 0;
	if (precision > 0 && precision > numbersize)
		numbersize = precision;
	if (flags->zero && precision <= 0)
	{
		while (flags->width-- > numbersize)
			count += ft_putchar('0');
		count += ft_putnbr(number);
	}
	else if (flags->precision)
	{
		while (flags->width-- > numbersize)
			count += ft_putchar(' ');
		count += unsignedint_prec(number, precision);
	}
	else
	{
		while (flags->width-- > numbersize)
			count += ft_putchar(' ');
		count += ft_putnbr(number);
	}
	return (count);
}

int	unsignedint_w_l(long int number, t_flags *flags, int precision)
{
	int	count;

	count = 0;
	if (flags->zero && precision <= 0)
	{
		count += ft_putnbr(number);
		while (flags->width > count)
			count += ft_putchar('0');
	}
	else if (precision > 0)
	{
		count += unsignedint_prec(number, precision);
		while (flags->width > count)
			count += ft_putchar(' ');
	}
	else
	{
		count += ft_putnbr(number);
		while (flags->width > count)
			count += ft_putchar(' ');
	}
	return (count);
}
