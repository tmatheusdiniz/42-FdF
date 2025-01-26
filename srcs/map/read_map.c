/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:59:48 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/26 19:06:57 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	read_map(t_meta *meta, char *path)
{
	int		fd;
	int		i;
	char	**split;
	char	*line;

	fd = open(path, O_RDONLY);
	i = 0;
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	if (!line)
		handler_errors(meta, ERR_READ);
	meta->map.width = map_columns(line);
	i = 1;
	free (line);
	while ((line = get_next_line(fd)) != NULL)
	{
		free (line);
		i ++;
	}
	meta->map.height = i;
	get_coordinates(meta, path);
	close (fd);
}

void	get_coordinates(t_meta *meta, char *path)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**split;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		handler_errors(meta, ERR_OPEN);
	while ((line = get_next_line(fd)) != NULL)
	{
		split = ft_split(line, ' ');
		j = 0;
		while (split[j])
		{
			meta->map.coords[i][j] = ft_atoi(split[j]);
			free (split[j]);
			j ++;
		}
		free (split);
		free (line);
		i ++;
	}
	close (fd);
}

void	init_map(t_meta *meta)
{
	int	i;

	i = 0;
	meta->map.coords = (int **)malloc(sizeof(int *) * (meta->map.height));
	if (!meta->map.coords)
	{
		ft_printf("%s\n", ERR_MLC);
		exit (1);
	}
	while (i < meta->map.height)
	{
		meta->map.coords[i] = (int *)malloc(sizeof(int) * (meta->map.width));
		if (!meta->map.coords[i])
		{
			ft_printf("%s\n", ERR_MLC);
			free (meta->map.coords);
			exit (1);
		}
		i ++;
	}
}

int	map_columns(char *line)
{
	int		count;
	int		i;
	char	**split;

	split = ft_split(line, ' ');
	while (split[count])
		count ++;
	while (split[i])
		free (split[i]);
	free (split);
	return (count);
}

void	free_map(t_meta *meta)
{
	int	i;

	i = 0;
	while (i < meta->map.height)
		free (meta->map.coords[i]);
	free (meta->map.coords);
}
