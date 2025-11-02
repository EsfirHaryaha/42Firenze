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

void	*ft_create_array(int *ptr, int n)
{
	ptr = (int*) malloc(n * sizeof (int));
	if (!ptr)
	{
		return (0);
	}
	return (ptr);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = src[i];
	return (dest);
}

void	ft_allocate_dict_key(int *ptr, int n3c, char *str)
{
	int **ptr2;

	ptr2[0] = n3c;
	ft_strcpy(ptr2[1], str);
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


void	ft_allocate_dict_value(int *ptr, char *str)
{
	ft_strcpy(ptr, str);
}
