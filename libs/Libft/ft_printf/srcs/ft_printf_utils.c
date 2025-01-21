/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:15:47 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/22 22:16:39 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_numsize(long long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count += 1;
	}
	while (n > 9)
	{
		n /= 10;
		count ++;
	}
	return (count);
}

int	ft_hexsize(size_t n)
{
	int	count;

	count = 1;
	if (n >= 16)
		count += ft_hexsize(n / 16);
	return (count);
}

int	ft_putnbr(long long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count += ft_putchar('-');
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr_base(unsigned long long n, char *base)
{
	int					count;
	unsigned long long	base_size;

	count = 0;
	base_size = ft_strlen(base);
	if (n >= base_size)
		count += ft_putnbr_base (n / base_size, base);
	count += ft_putchar(base[n % base_size]);
	return (count);
}

int	int_wid(t_flags *flags)
{
	int		count;
	char	token;

	count = 0;
	if (flags->sign_plus)
		token = '+';
	else if (flags->space)
		token = ' ';
	if (flags->sign_plus || flags->space)
	{
		while (flags->width -- > 1)
			count += ft_putchar(' ');
		return (count += ft_putchar(token), count);
	}
	while (flags->width-- > 0)
		count += ft_putchar(' ');
	return (count);
}
