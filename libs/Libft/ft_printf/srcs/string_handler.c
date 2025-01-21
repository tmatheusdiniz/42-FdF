/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:19:12 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/28 23:23:50 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	string_handler(va_list args, t_flags *flags)
{
	int		count;
	char	*string;

	count = 0;
	string = va_arg(args, char *);
	if (flags->width > 0 && flags->precision)
		count += print_w_p(string, flags->width,
				flags->precision - 1, flags->left_aligment);
	else if (flags->width > 0)
		count += print_w(string, flags->width, flags->left_aligment);
	else if (flags->precision > 0)
		count += print_p(string, flags->precision - 1);
	else
		count += ft_putstr(string);
	return (count);
}

int	print_w_p(char *string, int width, int precision, int left_aligment)
{
	int	count;
	int	size_string;

	count = 0;
	if (string == NULL)
	{
		string = "(null)";
		if (precision < 6)
			precision = 0;
	}
	size_string = ft_strlen(string);
	if (precision < size_string)
		size_string = precision;
	if (size_string >= width)
		return (print_p(string, size_string));
	if (left_aligment)
	{
		count += print_p(string, precision);
		while (count < width)
			count += ft_putchar(' ');
		return (count);
	}
	while (count < width - size_string)
		count += ft_putchar(' ');
	return (count += print_p(string, size_string));
}

int	print_p(char *string, int precision)
{
	int	count;

	count = 0;
	if (string == NULL)
	{
		if (precision < 6)
			precision = 0;
		else
			count += ft_putstr("(null)");
		return (count);
	}
	while (string[count] && precision-- > 0)
		count += ft_putchar(string[count]);
	return (count);
}

int	print_w(char *string, int width, int left_aligment)
{
	int	count;
	int	size_string;

	count = 0;
	if (string == NULL)
		string = "(null)";
	size_string = ft_strlen(string);
	if (size_string >= width)
		return (count += ft_putstr(string), count);
	if (left_aligment)
	{
		count += ft_putstr(string);
		while (count < width)
			count += ft_putchar(' ');
		return (count);
	}
	while (width -- > size_string)
		count += ft_putchar(' ');
	count += ft_putstr(string);
	return (count);
}
