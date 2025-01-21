/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:06:54 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/10 00:20:03 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	n;
	void	*p;

	n = nmemb * size;
	p = malloc(n);
	if (!p)
		return (NULL);
	ft_bzero(p, n);
	return (p);
}
