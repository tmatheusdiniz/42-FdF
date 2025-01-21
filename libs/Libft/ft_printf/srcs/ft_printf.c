/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:29:15 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/18 20:40:46 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	formats(const char *string, size_t *i, va_list args, t_flags *flags)
{
	int		count;
	char	c;

	count = 0;
	while (ft_memchr(FLAGS, string[*i], 6) || ft_isdigit(string[*i]))
		flags = flags_handler(string, i, flags);
	if (string[*i] == 's')
		count += string_handler(args, flags);
	else if (string[*i] == 'c')
		count += char_handler(args, flags);
	else if (string[*i] == 'i' || string[*i] == 'd')
		count += integer_handler(va_arg(args, int), flags);
	else if (string[*i] == 'u')
		count += unsignedint_handler(args, flags);
	else if (string[*i] == 'p')
		count += pointer_handler(args, flags);
	else if (string[*i] == '%')
		count += percentage_handler();
	else if (string[*i] == 'x' || string[*i] == 'X')
	{
		c = string[*i];
		count += hexdecimal_handler(va_arg(args, unsigned int), flags, c);
	}
	(*i)++;
	return (count);
}

int	ft_printf(const char *string, ...)
{
	int		count;
	size_t	i;
	t_flags	flags;
	va_list	args;

	if (!string || (string[0] == '%' && string[1] == '\0'))
		return (-1);
	i = 0;
	count = 0;
	va_start(args, string);
	while (string[i])
	{
		ft_bzero(&flags, sizeof(t_flags));
		if (string[i] == '%')
		{
			i ++;
			count += formats(string, &i, args, &flags);
		}
		else
			count += ft_putchar(string[i++]);
	}
	va_end(args);
	return (count);
}
