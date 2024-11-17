/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:21:05 by hirwatan          #+#    #+#             */
/*   Updated: 2024/11/17 21:24:58 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define FD_MAX 1024 + 1
typedef struct
{
	char	*str;//文字列
	size_t	len;//文字列の長さ
	size_t	capa;//確保した領域の長さ
}			t_string;

char		*ft_read_line(int fd);
char		*get_next_line(int fd);

#endif