/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marubio- <marubio-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:42:20 by marubio-          #+#    #+#             */
/*   Updated: 2023/02/27 15:00:21 by marubio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/**
 * It reads the file until it finds a new line, then it copies the line into
 * a new string and returns it
 * 
 * @param fd file descriptor
 * 
 * @return A string that contains the line that was read from the file.
 */

char	*get_next_line(int fd)
{
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	static char	*rest = NULL;
	char		*tmp;
	int			i;

	i = 1;
	tmp = NULL;
/* Checking if the file descriptor is valid and if the buffer size is valid. */
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// printf("TMP_pre_bucle=%s\n", tmp);
/* Reading the file until it finds a new line. */
	while (!ft_strchr(rest, '\n')  && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);	
		// printf("_I:=%d\n", i);
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
		// printf("REST1=%s %s %d\n", rest, ft_strchr(rest, '\n'),!ft_strchr(rest, '\n')  && i > 0);
	}
	line = ft_strdup_limit(rest, '\n');
		//  printf("TMP=%s\n", tmp);
		// printf("REST=%s\n", rest);
	// printf("condition=%c,NEWlinepos=%zu\n", rest[ft_strlen(line)],ft_strlen(line));
	
	if (rest && rest[ft_strlen(line) - 1] == '\n')
	{
		tmp = ft_strdup(rest + ft_strlen(line));
		//  printf("tmp=%s\n", tmp);
		free(rest);
		rest = NULL;
		rest = tmp;
		// printf("rest=%s\n", rest);
		tmp = NULL;
	}
	/* Freeing the rest string if there is no new line in it. */
	else
	{
		free(rest);
		rest = NULL;
	}
	return (line);
}
// void f()
// {
// 	system("leaks -q a.out");
// }
// int main()
// {
// 	// atexit(f);
// 	char *line;
// 	int fd;
// 	int i = 0;

// 	fd = open("lines.txt", O_RDONLY);
// 	line = get_next_line(fd);

// 	while(line) // && i < 5)
// 	{
// 		printf("%s\n", line);
// 		// write(1, line, ft_strlen(line));
// 		free(line);
// 		// free(line);
// 		line = get_next_line(fd);
// 		++i;
// 	}
// 	// free(line);
// 	return(0);
// }
// int main ()
// {
// 	// atexit(f);
// 	int fd;
// 	// fd = open("lines.txt", O_RDONLY);
// 	fd = 100;
// 	char *c = get_next_line(fd);
// 	printf("%s", c);
// 	free(c);
	
// 	c = get_next_line(fd);
// 	printf("%s", c);
// 	free(c);
	
// 	c = get_next_line(fd);
// 	printf("%s", c);
// 	free(c);
	
// 	c = get_next_line(fd);
// 	printf("%s", c);
// 	free(c);

// }
