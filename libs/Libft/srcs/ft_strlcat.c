/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:04:28 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/03 16:05:55 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	n;
	size_t	dst_len;

	n = 0;
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
	{
		return (size + ft_strlen(src));
	}
	while (src[n] != '\0' && n < size - dst_len - 1)
	{
		dst[dst_len + n] = src[n];
		n ++;
	}
	dst[dst_len + n] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[n]));
}
