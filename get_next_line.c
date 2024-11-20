/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:21:09 by hirwatan          #+#    #+#             */
/*   Updated: 2024/11/20 17:52:21 by hirwatan         ###   ########.fr       */
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
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	new_str = (char *)malloc(ft_strlen(str + i) + 1);
	if (!new_str)
		return (NULL);
	i++; //改行の次の文字からコピー
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
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 2)); //改行とnull文字
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char	*line;// static char *stack[FD_MAX];	//残っている
	int byte_lead = 0;   // 読み込んだ数
	char *buf;           // 残りと結合　+ 読むやつ
	static char *buffer; // nokori
	//ポインタと配列の違いと　ポインタ配列　宣言の意味 そもそも配列がポインタなのか　malloc
	if (fd < 0 || BUFFER_SIZE <= 0) //無効なのを検索
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL); // bufに入れる
	byte_lead = 1;     //ループ会しよう
	if (!buffer)
		buffer = ft_strdup("");
	while (!find_new_line(buffer) && byte_lead > 0)
	{
		byte_lead = read(fd, buf, BUFFER_SIZE);
		if (byte_lead < 0)
		{
			free(buf);
			free(buffer);
			return (NULL);
		}
		buf[byte_lead] = '\0';
		buffer = ft_strjoin(buffer, buf);
		if (!buffer)
			break ;
	}
	free(buf);
	if (!buffer || buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = return_line(buffer);
	buffer = left_over(buffer);
	return (line);
}
int	main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	line = (char *)1;
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
}