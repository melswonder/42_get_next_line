/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:47:36 by loremipsum        #+#    #+#             */
/*   Updated: 2024/11/20 22:56:52 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
// char	*ft_strdup(const char *s)
// {
// 	char	*dest;
// 	char	*start;

// 	dest = (char *)malloc(ft_strlen(s) + 1);
// 	if (!dest)
// 		return (NULL);
// 	start = dest;
// 	while (*s)
// 	{
// 		*dest = *s;
// 		dest++;
// 		s++;
// 	}
// 	*dest = '\0';
// 	return (start);
// }
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;
    size_t  s1_len;
    size_t  s2_len;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
	dest = malloc(s1_len + s2_len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
void	ft_bzero(void *s, size_t n)
{
	unsigned char *p;
	int i;

	i = 0;
	p = (unsigned char *)s;
	if (n == 0 || !s)
		return ;
	while (n--)
	{
		p[i] = '\0';
		i++;
	}
}