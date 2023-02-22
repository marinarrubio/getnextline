/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marubio- <marubio-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:42:31 by marubio-          #+#    #+#             */
/*   Updated: 2023/02/22 14:08:28 by marubio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		k;
	int		lens1;
	int		lens2;

	i = 0;
	k = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	newstr = malloc(lens1 + lens2 + 1);
	if (!newstr)
		return (NULL);
	while (s1 && s1[i])
	{
		newstr[k++] = s1[i++];
	}
	i = 0;
	while (s2 && s2[i])
	{
		newstr[k++] = s2[i++];
	}
	newstr[k] = '\0';
	return (newstr);
}

char	*ft_strchr(const char *s, int c)
{
	while (s && *s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i])
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	i = 0;
	if (dst == NULL)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup_limit(const char *str, char limit)
{
	char	*dst;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (str == NULL)
		return (NULL);
	while (str[len] && str[len] != (limit + 1))
		len++;
	dst = (char *)malloc(sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str && str[n])
		n++;
	return (n);
}
