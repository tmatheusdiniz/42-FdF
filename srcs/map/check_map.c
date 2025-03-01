/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:22:48 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/25 23:24:46 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <fcntl.h>

static int	check_line(char *line);
static int	is_number(const char *str);
static void	map_guard(int fd);
static int	aux_check(int fd);

int	aux_check(int fd)
{
	int		count;
	int		temp;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (3);
	temp = check_line(line);
	if (temp == 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		count = check_line(line);
		if (count == 0 || count != temp)
			return (0);
		line = get_next_line(fd);
	}
	return (1);
}

static void	map_guard(int fd)
{
	int	i;

	i = aux_check(fd);
	if (i == 0)
	{
		clear_gnl(fd);
		ft_printf("%s\n", "Invalid Map");
		exit (1);
	}
	else if (i == 3)
	{
		clear_gnl(fd);
		ft_printf("%s\n", ERR_READ);
		exit(1);
	}
	else
		return ;
}

static int	is_number(const char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
	{
		if (!check_hex(str))
			return (0);
	}
	if (!check_is_number(str))
		return (0);
	if (*str == ',')
	{
		str ++;
		if (!check_hex(str) && !check_after_comma(str))
			return (0);
	}
	return (1);
}

static int	check_line(char *line)
{
	int		i;
	char	*trimed;
	char	**split;

	trimed = ft_strtrim(line, "\n ");
	free (line);
	split = ft_split(trimed, ' ');
	free (trimed);
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		if (!is_number(split[i]) && split[i][0] != 10)
		{
			while (split[i])
				free(split[i++]);
			free(split);
			return (0);
		}
		free (split[i]);
		i ++;
	}
	free (split);
	return (i);
}

void	check_map(int v, char *path)
{
	int	size;
	int	fd;

	if (v != 2 || !path)
	{
		ft_printf("%s\n", ERR_ARGS);
		exit (1);
	}
	size = ft_strlen(path);
	if (size <= 4 || ft_strncmp(&path[size - 4], ".fdf", 4))
	{
		ft_printf("%s\n", ERR_MAP);
		exit (1);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s\n", ERR_OPEN);
		exit (1);
	}
	map_guard(fd);
	close (fd);
	return ;
}
