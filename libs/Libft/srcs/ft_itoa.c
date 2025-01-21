/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:30:00 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/09 23:58:14 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	length_number(int n)
{
	int			size;
	long int	num;

	num = n;
	size = 0;
	if (n < 0)
	{
		num = -num;
		size ++;
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		size ++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int				i;
	long int		num;
	char			*itoa;

	i = length_number(n);
	num = n;
	itoa = (char *)malloc((i + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	itoa [i--] = '\0';
	if (num < 0)
	{
		itoa[0] = '-';
		num = -num;
	}
	else if (num == 0)
		itoa[0] = '0';
	while (i >= 0 && num != 0)
	{
		itoa[i --] = num % 10 + '0';
		num /= 10;
	}
	return (itoa);
}
