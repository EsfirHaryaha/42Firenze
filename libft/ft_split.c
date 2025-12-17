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

#include "libft.c"

char    **ft_split(char const *s, char c)
{
    int n;

    if (!s)
        return (NULL);
    ft_strtrim(s, c);
    n = count(s, c);
}

int count(char const *s, char c)
{
    int i;
    int n;

    while(s[i] != '\0')
    {
        if (s[i] == )
    }
}