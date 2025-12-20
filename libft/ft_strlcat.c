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
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst[dst_len] && dst_len < dsize)
		dst_len++;
	src_len = ft_strlen(src);
	if (dst_len == dsize)
		return (dsize + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < dsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < dsize)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
