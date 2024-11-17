/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:06:46 by hirwatan          #+#    #+#             */
/*   Updated: 2024/11/17 21:34:50 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

size_t	str_n_len(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (i);
}
char *get_next_line(int fd) {
    // 今回の場合はt_string　 *retではなく、 t_string retとしておけば、
    // 構造体をmalloc & freeする必要がないので実装が楽になります。
    t_string ret; 
    char c;

    // 初期化
    ret.str = NULL;
    ret.len = 0;
    ret.capa = 0;

    while(1) {　// 無限ループ
        c = ft_getc(fd); // 1文字読み込む

        if(c == EOF) {
            break;　// ファイルの最後ならループから抜ける
        }
        ft_putc(&ret, c);　// 1文字詰める
        if(c == '\n') {
            break;　// 改行だったらループから抜ける
        }
    }
    if(ret.len > 0) {
        ft_putc(&ret, '\0');　// 最後にNULL文字を詰める
    }
    return ret.str;
}

int	ft_putc(t_string *str, char c)
{
	if (str->len + 1 > str->capa)
	{
		//容量が足りない時は新たに確保してコピー
		
	}
	str->str[str->len] = c;
	str->len++;
	return (0);
}

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
	if (--n >= 0)
		return ((unsigned char)*bufp++);
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