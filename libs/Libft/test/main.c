/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:10:25 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/07 21:21:31 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft.h"

int	main(void)
{
	int	test;

	test = ft_atoi("21474836488100");
	ft_printf("FT -> %i\n", test);
	test = atoi("21474836488100");
	ft_printf("OG -> %i\n", test);
	test = ft_atoi("-21474836488100");
	ft_printf("FT -> %i\n", test);
	test = atoi("-21474836488100");
	ft_printf("OG -> %i\n", test);
	test = ft_atoi("2147483648");
	ft_printf("FT -> %i\n", test);
	test = atoi("2147483648");
	ft_printf("OG -> %i\n", test);
	test = ft_atoi("2147483647");
	ft_printf("FT -> %i\n", test);
	test = atoi("2147483647");
	ft_printf("OG -> %i\n", test);
	test = ft_atoi("0");
	ft_printf("FT -> %i\n", test);
	test = atoi("0");
	ft_printf("OG -> %i\n", test);
	test = ft_atoi("-2147483649");
	ft_printf("FT -> %i\n", test);
	test = atoi("-2147483649");
	ft_printf("OG -> %i\n", test);
}
