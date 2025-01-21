/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:06:58 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/26 14:25:35 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_flags	*initialization_flags(void)
{
	t_flags	*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->sign_plus = FALSE;
	flags->left_aligment = FALSE;
	flags->zero = FALSE;
	flags->width = FALSE;
	flags->precision = FALSE;
	flags->hashtag = FALSE;
	flags->space = FALSE;
	return (flags);
}

void	tratament_flags(const char *string, size_t *i, t_flags *flags)
{
	if (string[*i] == '.')
		flags->precision = ft_atoi(&string[++*i]) + 1;
	else
		flags->width = ft_atoi(&string[(*i)]);
	while (ft_isdigit(string[*i]))
		(*i)++;
}

t_flags	*flags_handler(const char *string, size_t *i, t_flags *flags)
{
	if (!flags)
		flags = initialization_flags();
	if (!flags)
		return (NULL);
	while (string[*i] == '-' || string[*i] == '+' || string[*i] == ' '
		|| string[*i] == '#' || string[*i] == '0')
	{
		if (string[*i] == '-')
			flags->left_aligment = TRUE;
		if (string[*i] == '+')
			flags->sign_plus = TRUE;
		if (string[*i] == ' ')
			flags->space = TRUE;
		if (string[*i] == '#')
			flags->hashtag = TRUE;
		if (string[*i] == '0')
			flags->zero = TRUE;
		(*i)++;
	}
	if (ft_isdigit(string[*i]) || string[*i] == '.')
		tratament_flags(string, i, flags);
	return (flags);
}
