/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marubio- <marubio-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:42:20 by marubio-          #+#    #+#             */
/*   Updated: 2023/02/14 12:52:47 by marubio-         ###   ########.fr       */
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
	printf("%i\n", 1);	
	while(!ft_strchr(rest, '\n') && (i = read(fd, buffer, BUFFER_SIZE) > 0))
	{
		buffer[i] = '\0';
		tmp = ft_strjoin(rest, buffer);
		free(rest);
		rest = tmp;
		printf("%i\n", 1);	
	}
	if(fd == -1)
		return(NULL);
	line = ft_strdup_limit(rest, '\n');
	tmp = ft_strdup(rest + ft_strlen(line) + 1);
	free(rest);
	rest = tmp;
	return(line);
		
}
int main ()
{
	// atexit(get_next_line);
	int fd;

	fd = open("lines.txt", O_RDWR);
	printf("%s", get_next_line(fd));
}