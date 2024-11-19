/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:21:09 by hirwatan          #+#    #+#             */
/*   Updated: 2024/11/19 20:04:35 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	find_new_line(char *str)
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

char	*left_over(char *str)
{
	size_t	i;
	size_t	j;
	char	*new_str;

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

char	*return_line(char *str)
{
	char	*dest;
	size_t	i;

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
	// dest[i++] = '\n'; // 改行がないときに改行が追加されてしまう
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	// static char *stack[FD_MAX];	//残っている
	int byte_lead;       // 読み込んだ数
	char *buf;           // 残りと結合　+ 読むやつ
	static char *buffer; // nokori
	char *line;        //ポインタと配列の違いと　ポインタ配列　宣言の意味 そもそも配列がポインタなのか　malloc
	ft_bzero(line, FD_MAX);
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
			break ;
		buf[byte_lead] = '\0';
		buffer = ft_strjoin(buffer, buf);
	}
	if (find_new_line(buffer))
	{
		*line = return_line(buffer);
		buffer = left_over(buffer);
	}
	else if (*buffer)
	{
		*line = ft_strdup(buffer); // 残ったデータ全体を返す
		free(buffer);
		buffer = NULL;
	}
	else
		*line = NULL;
	free(buf);
	return (&line);
}
