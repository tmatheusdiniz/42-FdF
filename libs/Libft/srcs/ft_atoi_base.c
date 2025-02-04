/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:28:12 by mreinald          #+#    #+#             */
/*   Updated: 2025/02/04 16:52:22 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	check_all(char *str, char *base);
static int	get_position(char *base, char str);
static void	get_number_pos(char **str, int *sign);

static int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == '-' || base[i] == '+'
			|| base[i] == 32)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j ++;
		}
		++ i;
	}
	if (i < 2)
		return (0);
	return (i);
}

// Here i check if the number received is written with the base caracters!
static int	check_all(char *str, char *base)
{
	int	i;
	int	j;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i ++;
	while (str[i])
	{
		j = 0;
		while (base[j] && (str[i] != base[j]
				|| (str[i] == '+' || str[i] == '-')))
			++j;
		if (str[i] != base[j] && str[i] != '+' && str[i] != '-')
			return (0);
		i ++;
	}
	if (i < 1)
		return (0);
	return (i);
}

static int	get_position(char *base, char str)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != str)
		i ++;
	return (i);
}

static void	get_number_pos(char **str, int *sign)
{
	while ((**str >= 9 && **str <= 13) || **str == 32
		|| **str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign *= -1;
		++ (*str);
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int			sign;
	int			i;
	int			j;
	int			b_length;
	long int	res;

	if (!str || !base)
		return (0);
	if (!(check_base(base) && check_all(str, base)))
		return (0);
	res = 0;
	sign = 1;
	i = 0;
	get_number_pos(&str, &sign);
	b_length = check_base(base);
	while (str[i])
	{
		j = get_position(base, str[i]);
		res = res * b_length + j;
		i ++;
	}
	if (ft_count_bits(res) > 32)
		res &= 0xFFFFFFFF;
	return (res * sign);
}
