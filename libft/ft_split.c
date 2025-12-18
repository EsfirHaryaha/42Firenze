/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <eharyaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:28:00 by eharyaha          #+#    #+#             */
/*   Updated: 2025/12/17 20:40:42 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int  count_words(char const *s, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
            count++;
        while (s[i] && s[i] != c)
            i++;
    }
    return (count);
}

static char *get_word(char const *s, char c, int *i)
{
    int start;
    int len;

    while (s[*i] == c)
        (*i)++;
    start = *i;
    len = 0;
    while (s[*i] && s[*i] != c)
    {
        (*i)++;
        len++;
    }
    return (ft_substr(s, start, len));
}

char    **ft_split(char const *s, char c)
{
    char    **array;
    int     i;
    int     j;
    int     words;

    if (!s)
        return (NULL);

    words = count_words(s, c);
    array = malloc(sizeof(char *) * (words + 1));
    if (!array)
        return (NULL);

    i = 0;
    j = 0;
    while (j < words)
    {
        array[j] = get_word(s, c, &i);
        if (!array[j])
            return (NULL);
        j++;
    }
    array[j] = NULL;
    return (array);
}
