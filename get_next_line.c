/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loremipsum <loremipsum@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:21:09 by hirwatan          #+#    #+#             */
/*   Updated: 2024/11/19 14:43:23 by loremipsum       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(const char *s)
{
	char *dest;
	char *start;
	size_t i;

	i = 0;
	while(s[i] != '\0')
		i++;
	dest = (char *)malloc(i + 1);
	if (!dest)
		return (NULL);
	start = dest;
	while (*s)
	{
		*dest = *s;
		dest++;
		s++;
	}
	*dest = '\0';
	return (start);
}
int find_new_line(char *str)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *dest;
	size_t i;
	size_t j;

	if (!s1 || !s2)
		return (NULL);
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	free(s1);
	free(s2);
	return (dest);
}

char *left_over(char *str)
{
	size_t i;
	size_t j;
	char *new_str;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	new_str = (char *)malloc(ft_strlen(str + i + 1) + 1);
	if (!new_str)
		return (NULL);
	i++;
	while (str[i] != '\0')
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char *return_line(char *str)
{
	char *dest;
	size_t i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *get_next_line(int fd)
{
	// static char *stack[FD_MAX];	//残っている
	int byte_lead;		 // 読み込んだ数
	char *buf;			 // 残りと結合　+ 読むやつ
	static char *buffer; // nokori
	char *line;			 //

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL); // bufに入れる
	while (!find_new_line(buf))
	{
		byte_lead = read(fd, buf, BUFFER_SIZE);
		if (byte_lead < 0)
		{
			free(buf);
			free(buffer);
			return (NULL);
		}
		if (byte_lead == 0) // EOFの場合
			break;
		buf[byte_lead] = '\0';
		buffer = ft_strjoin(buffer, buf);
	}
	if (find_new_line(buffer))
	{
		line = return_line(buffer);
		buffer = left_over(buffer);
	}
	else if (*buffer)
	{
		line = ft_strdup(buffer); // 残ったデータ全体を返す
		free(buffer);
		buffer = NULL;
	}
	else
		line = NULL;
	free(buf);
	return (NULL);
}
