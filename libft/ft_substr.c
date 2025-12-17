/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <eharyaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:30:21 by eharyaha          #+#    #+#             */
/*   Updated: 2025/12/17 19:30:21 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*ptr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len > ft_strlen(s) - start)
		str_len = ft_strlen(s) - start;
	else
		str_len = len;
	ptr = malloc(str_len + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s + start, str_len);
	ptr[str_len] = '\0';
	return (ptr);
}
