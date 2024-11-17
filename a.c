/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:11:25 by hirwatan          #+#    #+#             */
/*   Updated: 2024/11/17 21:06:28 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_getc(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	static char	*bufp;
	static int	n = 0;

	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		bufp = buf;
	}
	if(--n >= 0)
		return((unsigned char)*bufp++);
	else
		return (EOF);
}

int	main(void)
{
	int fd;
	int c;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break ;
		printf("%c", c);
	}
	close(fd);
	return (0);
}
