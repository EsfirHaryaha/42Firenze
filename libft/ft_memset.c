/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <eharyaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:25:31 by eharyaha          #+#    #+#             */
/*   Updated: 2025/12/11 15:04:21 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void    *ft_memset(void *s, int c, size_t n)
{
    if (n == 0)
        return (s);
    unsigned char *p = (unsigned char *)s;
    while (n--)
    {
        p[n] = c;
    }
    return (s);
}