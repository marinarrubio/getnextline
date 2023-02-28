/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marubio- <marubio-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:53:33 by marubio-          #+#    #+#             */
/*   Updated: 2023/02/28 11:06:44 by marubio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

/**
 * It reads from the file descriptor until it finds a newline character or
 * until it reaches the end of
 * the file
 * 
 * @param fd file descriptor
 * @param rest the string that contains the rest of the line from the 
 * previous read
 * 
 * @return A pointer to a string.
 */
char	*read_and_rest(int fd, char *rest)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;
	int			i;

	i = 1;
	while (!ft_strchr(rest, '\n') && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0 || (!i && !ft_strlen(rest)))
		{
			free(rest);
			return (NULL);
		}	
		buffer[i] = '\0';
		tmp = ft_strjoin(rest, buffer);
		free(rest);
		rest = NULL;
		rest = tmp;
		tmp = NULL;
	}
	return (rest);
}

/**
 * It reads from a file descriptor and returns a line from it
 * 
 * @param fd the file descriptor from which to read
 * 
 * @return A line of text from a file descriptor.
 */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest[OPEN_MAX];
	char		*tmp;
	int			i;

	i = 1;
	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest[fd] = read_and_rest(fd, rest[fd]);
	line = ft_strdup_limit(rest[fd], '\n');
	if (rest[fd] && *(rest[fd] + ft_strlen(line) - 1) == '\n')
	{
		tmp = ft_strdup(rest[fd] + ft_strlen(line));
		free(rest[fd]);
		rest[fd] = NULL;
		rest[fd] = tmp;
		tmp = NULL;
	}
	else
	{
		free(rest[fd]);
		rest[fd] = NULL;
	}
	return (line);
}

/*int main()
{
	char *line;
	int fd;
	int i = 0;

	fd = open("lines.txt", O_RDONLY);
	line = get_next_line(fd);

	while(line) // && i < 5)
	{
		printf("%s", line);
		// write(1, line, ft_strlen(line));
		free(line);
		// free(line);
		line = get_next_line(fd);
		++i;
	}
	// free(line);
	return(0);
}*/
/*int main ()
{
	int fd;
	// fd = open("lines.txt", O_RDONLY);
	fd = 100;
	char *c = get_next_line(fd);
	printf("%s", c);
	free(c);
	
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
}*/
