/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:59:50 by eharyaha          #+#    #+#             */
/*   Updated: 2025/11/02 10:59:57 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int		str_size(char *str);
char	*create_new_string(char *str, int start, int end, int size);

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return 0;
	if (str[0] == '0' && str[1] != '\0')
		return 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_strtrim(char *str)
{
	int		start;
	int		end;
	char	*newstr;

	start = 0;
	end = str_size(str);
	end--;
	while (str[start] == ' ')
	{
		start++;
	}
	while (str[end] == ' ')
	{
		end--;
	}
	newstr = create_new_string(str, start, end, (end - start + 1));
	return (newstr);
	//fare il free del newstr appena usato!!!!!
}

char	*create_new_string(char *str, int start, int end, int size)
{
	int		i;
	char	*newstr;
	//printf("\n\nstart vale: %d, end vale: %d\n\n", start, end);
	newstr = malloc(sizeof(char) * (size + 1));
	//fare il controllo malloc per memoria non allocata
	i = 0;
	while (start <= end)
	{
		newstr[i] = str[start];
		start++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

int	str_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	**slice_str(char *str, char	*str_sliced[])
{
	int		i;
	int		end;

	i = 0;
	while (str[i] != ':')
	{
		i++;
	}
	end = i - 1;
	str_sliced[0] = ft_strtrim(create_new_string(str, 0, end, (end + 1)));
	end = str_size(str);
	str_sliced[1] = ft_strtrim(
			create_new_string(str, (i + 1), end, (end - (i + 1) + 1)));
// Debug (opzionale)
//printf("\n\nprima stringa:%s\n\n", str_sliced[0]);
//printf("\n\nseconda stringa:%s\n\n", str_sliced[1]);
	return (str_sliced);
}
