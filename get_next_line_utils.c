/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:47:36 by loremipsum        #+#    #+#             */
/*   Updated: 2024/11/20 13:01:32 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t i;
    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}
char *ft_strdup(const char *s)
{
    char *dest;
    char *start;

    dest = (char *)malloc(ft_strlen(s) + 1);
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
    return (dest);
}
