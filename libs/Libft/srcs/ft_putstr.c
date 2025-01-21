/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:10:47 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/25 16:16:39 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putstr(char	*s)
{
	if (!s)
		return (-1);
	if (write(STDOUT_FILENO, s, ft_strlen(s)) == -1)
		return (-1);
	else
		return (ft_strlen(s));
}
