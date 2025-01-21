/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:46:11 by mreinald          #+#    #+#             */
/*   Updated: 2024/12/27 22:15:24 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//              HEADERS

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

//              BUFFER SIZE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//              Functions

char	*get_next_line(int fd);
char	*get_next(char *next_str);
char	*get_line(char *str);
char	*get_read(int fd, char *str);
void	*get_calloc(size_t nmemb, size_t size);
char	*get_strjoin(char *s1, char *s2);
char	*get_strchr(char *s, int c);
size_t	get_strlen(char *s);

#endif
