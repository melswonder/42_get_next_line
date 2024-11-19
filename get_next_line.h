/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:21:05 by hirwatan          #+#    #+#             */
/*   Updated: 2024/11/19 18:01:52 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define FD_MAX 20000000

// typedef struct
// {
// 	char	*str;//文字列
// 	size_t	len;//文字列の長さ
// 	size_t	capa;//確保した領域の長さ
// }			t_string;

//util
size_t ft_strlen(const char *s);
char *ft_strdup(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);

#endif