/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:57:27 by lgreco            #+#    #+#             */
/*   Updated: 2025/11/02 17:39:40 by lgreco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_create_array(int n)
{
	int	*ptr;

	ptr = malloc(n * sizeof(int));
	if (!ptr)
		return (NULL);
	return (ptr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_calculate_3c(char *str)
{
	int	num;
	int	i;

	i = 1;
	num = 1;
	while (*str)
	{
		if (i % 3 == 0)
			num++;
		str++;
		i++;
	}
	return (num);
}
