/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marubio- <marubio-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:42:20 by marubio-          #+#    #+#             */
/*   Updated: 2023/02/14 14:58:38 by marubio-         ###   ########.fr       */
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
	if (rest)
		// printf("- %s - ", rest);
	rest = NULL;
	// printf("%i\n", 1);
	// 	printf("%i\n", 2);
	while(!ft_strchr(rest, '\n') && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);	
		// printf("%i\n", i);	
		buffer[i] = '\0';
		tmp = ft_strjoin(rest, buffer);
		printf("TMP:__%s__\n", tmp);
		free(rest);
		rest = tmp;
		printf("REST:__%s__\n", rest);
	}
	// printf("%i\n", 4);
	if(fd == -1)
		return(NULL);
	line = ft_strdup_limit(rest, '\n');
	printf("LINE:--%s--\n", line);
	tmp = ft_strdup(rest + ft_strlen(line) + 1);
	free(rest);
	rest = tmp;
	return(line);
		
}
void f()
{
	system("leaks -q a.out");
}
int main ()
{
	atexit(f);
	int fd;
	fd = open("lines.txt", O_RDWR);
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

}