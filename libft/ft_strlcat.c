/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <eharyaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:29:43 by eharyaha          #+#    #+#             */
/*   Updated: 2025/12/17 19:29:43 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	ds;
	size_t	i;

	i = 0;
	ds = ft_strlen(dst);
	if (ds < dsize)
	{
		while (ds + i < dsize - 1 && src[i] != '\0')
		{
			dst[ds + i] = src[i];
			i++;
		}
		dst[ds + i] = '\0';
	}
	return (ds + ft_strlen(src));
}
