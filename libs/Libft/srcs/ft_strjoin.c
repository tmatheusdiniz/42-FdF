/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:37:06 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/10 00:31:53 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*strjoin;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	strjoin = (char *)malloc((i + j + 1) * sizeof(char));
	i = 0;
	if (!strjoin)
		return (NULL);
	while (*s1)
		strjoin[i++] = *s1++;
	while (*s2)
		strjoin[i++] = *s2++;
	strjoin[i] = '\0';
	return (strjoin);
}
