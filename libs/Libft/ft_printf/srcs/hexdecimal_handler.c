/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdecimal_handler.c                               :+:      :+:    :+:   */
/*                                                  +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:30:13 by mreinald          #+#    #+#             */
/*   Updated: 2024/12/07 00:35:35 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	hexdecimal_handler(long unsigned int number, t_flags *flags, char token)
{
	int		count;
	char	flag;

	count = 0;
	flag = ' ';
	if (flags->zero)
		flag = '0';
	if (flags->width && flags->precision)
		flag = ' ';
	if (flags->left_aligment)
		count += print_hex_leftalig(flags, flags->precision - 1, number, token);
	else if (flags->width)
		count += print_hex_width(flags, number, flag, token);
	else if (flags->precision)
		count += print_h_p(number, flags, flags->precision - 1, token);
	else if (ft_isupper(token))
		return (count += print_hashtag(number, flags->hashtag, token),
			count += ft_putnbr_base(number, HEXBASEUP), count);
	else
	{
		count += print_hashtag(number, flags->hashtag, token);
		count += ft_putnbr_base(number, HEXBASE);
	}
	return (count);
}

int	print_hex_leftalig(t_flags *flags, int precision,
		long unsigned number, char token)
{
	int	count;

	count = 0;
	if (flags->hashtag)
	{
		if (number != 0)
			count += ft_putchar('0') + ft_putchar(token);
	}
	count += print_h_p(number, flags, precision, token);
	while (flags->width > count)
		count += ft_putchar(' ');
	return (count);
}

int	print_hex_width(t_flags *flags, long number, char flag, char token)
{
	int	count;
	int	parameter;

	count = 0;
	parameter = ft_hexsize(number);
	if (number == 0 && flags->precision <= 1)
		return (count += aux_unsigned(flags), count);
	if (flags->precision - 1 > parameter)
		parameter = flags->precision - 1;
	if (flags->hashtag)
		parameter += 2;
	while (flags->width-- > parameter)
		count += ft_putchar(flag);
	count += print_hashtag(number, flags->hashtag, token);
	if (flags->precision - 1 > ft_hexsize(number))
		return (count += print_h_p(number, flags, flags->precision - 1, token),
			count);
	if ((!(flags->precision <= 1) || flags->precision - 1 <= ft_hexsize(number))
		&& !ft_isupper(token))
		count += ft_putnbr_base(number, HEXBASE);
	else if ((!(flags->precision - 1)
			|| flags->precision - 1 <= ft_hexsize(number)) && ft_isupper(token))
		count += ft_putnbr_base(number, HEXBASEUP);
	return (count);
}

int	print_hashtag(long unsigned number, int hashtag, char token)
{
	int	count;

	count = 0;
	if (number != 0 && hashtag)
		count += ft_putchar('0') + ft_putchar(token);
	return (count);
}

int	print_h_p(long unsigned number, t_flags *flags, int precision, char token)
{
	int	count;
	int	parameter;

	count = 0;
	parameter = ft_hexsize(number);
	if (number == 0 && precision == 0)
		return (0);
	if (flags->hashtag && !flags->left_aligment && number != 0)
		count += ft_putchar('0') + ft_putchar(token);
	while (precision-- > parameter)
		count += ft_putchar('0');
	if (ft_isupper(token))
		count += ft_putnbr_base(number, HEXBASEUP);
	else
		count += ft_putnbr_base(number, HEXBASE);
	return (count);
}
