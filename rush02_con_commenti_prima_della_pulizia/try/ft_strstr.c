/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabagaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:09:25 by kabagaev          #+#    #+#             */
/*   Updated: 2025/10/28 19:08:32 by kabagaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] != '\0' && str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*skip_to_value(char *found)
{
	while (*found && *found != ':')
		found++;
	found++;
	while (*found == ' ' || *found == '\t')
		found++;
	return (found);
}

char	*copy_value(char *found)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (found[i] && found[i] != '\n')
		i++;
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (j < i)
	{
		result[j] = found[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*find_value(char *dict, char *key)
{
	char	search[100];
	char	*found;
	int		i;

	i = 0;
	while (key[i])
	{
		search[i] = key[i];
		i++;
	}
	search[i] = ':';
	search[i + 1] = '\0';
	found = ft_strstr(dict, search);
	if (!found)
		return (NULL);
	found = skip_to_value(found);
	return (copy_value(found));
}
