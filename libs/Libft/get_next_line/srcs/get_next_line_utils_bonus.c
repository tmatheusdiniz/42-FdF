/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:04:50 by mreinald          #+#    #+#             */
/*   Updated: 2024/12/29 17:21:40 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

void	*get_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;
	size_t			n;

	i = 0;
	n = nmemb * size;
	p = malloc(n);
	if (!p)
		return (NULL);
	while (i < n)
	{
		p[i] = 0;
		i ++;
	}
	return (p);
}

char	*get_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*strjoin;

	i = get_strlen(s1);
	j = get_strlen(s2);
	strjoin = (char *)get_calloc(sizeof(char), i + j + 1);
	if (!strjoin)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		strjoin[i + j] = s2[j];
		j++;
	}
	strjoin[i + j] = '\0';
	free (s1);
	return (strjoin);
}

char	*get_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s ++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	get_strlen(char *s)
{
	size_t	count;

	count = 0;
	while (s && s[count])
		count ++;
	return (count);
}
