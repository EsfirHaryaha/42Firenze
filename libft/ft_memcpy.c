/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <eharyaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:19:29 by eharyaha          #+#    #+#             */
/*   Updated: 2025/12/11 15:20:41 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char   *d = dest;
    const unsigned char   *s = src;

    while(n--)
    {
        *d++ = *s++;
    }
    return dest;
}