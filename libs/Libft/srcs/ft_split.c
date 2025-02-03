/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:10:33 by mreinald          #+#    #+#             */
/*   Updated: 2024/11/10 00:17:12 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (flag)
				flag = 0;
		}
		else
		{
			if (!flag)
			{
				flag = 1;
				count ++;
			}
		}
		i ++;
	}
	return (count);
}

static	void	free_words(char **s, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free (s[i]);
		i ++;
	}
	free(s);
}

static char	*insert_words(char const *s, char c)
{
	int		i;
	char	*insert;

	i = 0;
	while (s[i] && s[i] != c)
		i ++;
	insert = (char *)malloc((i + 1) * sizeof(char));
	if (!insert)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		insert [i] = s[i];
		i ++;
	}
	insert[i] = '\0';
	return (insert);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**matrix;

	if (!s)
		return (NULL);
	matrix = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			matrix[i] = insert_words(s, c);
			if (!matrix[i])
				return (free_words(matrix, i), NULL);
			while (*s && *s != c)
				s ++;
			i ++;
		}
		else
			s ++;
	}
	matrix[i] = 0;
	return (matrix);
}
