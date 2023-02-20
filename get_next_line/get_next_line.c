/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marubio- <marubio-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:42:20 by marubio-          #+#    #+#             */
/*   Updated: 2023/02/20 14:32:22 by marubio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


char	*get_next_line(int fd)
{
	char *line;
	char buffer[BUFFER_SIZE + 1]; 
	static char *rest;
	char *tmp;
	int i;

	i = 1;
	if(fd <= 0 || BUFFER_SIZE <= 0)
		return(0);
	while(!ft_strchr(rest, '\n') && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if(i == 0)
			break;
		buffer[i] = '\0';
		tmp = ft_strjoin(rest, buffer);
		free(rest);
		rest = tmp;
	}
	line = ft_strdup_limit(rest, '\n');
	if(rest && *(rest + ft_strlen(line)) == '\n')
	{
		tmp = ft_strdup(rest + ft_strlen(line) + 1);
		free(rest);
		rest = tmp;
	}
	else
		rest = NULL;
	if(line && *line != '\0')
	{
		line = ft_strjoin(line, "\n");
		return(line);
	}
	return(NULL);
	
}
// void f()
// {
// 	system("leaks -q a.out");
// }
// int main ()
// {
// 	atexit(f);
// 	int fd;
// 	fd = open("lines.txt", O_RDWR);
// 	char *c = get_next_line(fd);

// 	printf("%s", c);

// 	free(c);
// 	// c = get_next_line(fd);
// 	// printf("%s", c);

// 	// free(c);
// 	// c = get_next_line(fd);
// 	// printf("%s", c);

// 	// free(c);
// 	// c = get_next_line(fd);
// 	// printf("%s", c);

// 	// free(c);

// }
int main()
{
	// atexit(f);
	char *line;
	int fd;
	int i = 0;

	fd = open("lines.txt", O_RDONLY);
	line = get_next_line(fd);

	while(line) // && i < 5)
	{
		write(1, line, ft_strlen(line));
		//printf("%s", line);
		free(line);
		line = get_next_line(fd);
		++i;
	}
	free(line);
	return(0);
}