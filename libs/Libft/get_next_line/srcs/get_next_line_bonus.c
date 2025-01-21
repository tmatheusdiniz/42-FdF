/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:12:34 by mreinald          #+#    #+#             */
/*   Updated: 2024/12/27 22:13:19 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

char	*get_read(int fd, char *str)
{
	char	*readed;
	int		aux;	

	readed = get_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!readed)
		return (NULL);
	aux = 1;
	while (!(get_strchr(str, '\n')) && aux != 0)
	{
		aux = read(fd, readed, BUFFER_SIZE);
		if (aux < 0)
		{
			free (readed);
			free(str);
			return (NULL);
		}
		readed[aux] = 0;
		str = get_strjoin(str, readed);
	}
	free (readed);
	return (str);
}

char	*get_line(char *str)
{
	char			*line;
	unsigned int	aux;	

	aux = 0;
	if (!str[aux])
		return (NULL);
	while (str[aux] && str[aux] != '\n')
		aux ++;
	if (str[aux] == '\0')
		line = get_calloc(sizeof(char), aux + 1);
	else
		line = get_calloc(sizeof(char), aux + 2);
	if (!line)
		return (NULL);
	aux = 0;
	while (str[aux] && str[aux] != '\n')
	{
		line[aux] = str[aux];
		aux ++;
	}
	if (str[aux] == '\n')
		line[aux++] = '\n';
	line[aux] = '\0';
	return (line);
}

char	*get_next(char *str)
{
	char			*next;
	unsigned int	aux;
	unsigned int	aux_next;

	aux = 0;
	while (str[aux] && str[aux] != '\n')
		aux ++;
	if (!str[aux])
	{
		free (str);
		return (NULL);
	}
	next = get_calloc(sizeof(char), (get_strlen(str) - aux + 1));
	if (!next)
	{
		free (str);
		return (NULL);
	}
	++aux;
	aux_next = 0;
	while (str[aux])
		next[aux_next++] = str[aux++];
	next[aux_next] = '\0';
	return (free(str), next);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[FDS_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = get_read(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = get_line(save[fd]);
	save[fd] = get_next(save[fd]);
	return (line);
}
