/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <eharyaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:15:00 by eharyaha          #+#    #+#             */
/*   Updated: 2025/12/11 15:17:42 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void    *ft_bzero(void *s, size_t n)
{
    size_t i;

    i = 0;
    unsigned char   *p = (unsigned char *)s;
    while(i < n)
    {
        p[i] = 0;
        i++;
    }
    return (s);
}