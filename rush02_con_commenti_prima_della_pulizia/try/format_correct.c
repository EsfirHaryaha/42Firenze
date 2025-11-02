/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_correct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:05:04 by eharyaha          #+#    #+#             */
/*   Updated: 2025/11/02 21:05:09 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	is_format_correct(char *str)
{
	int	i;

	i = 0;
	if (str[0] == ' ')
	{
		write (1, "Dict Error\n", 11);
		return (0);
	}
	while (str[i] != ':')
	{
		if (str[i] == ' ')
		{
			write (1, "Dict Error\n", 11);
			return (0);
		}
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write (1, "Dict Error\n", 11);
			return (0);
		}
		i++;
	}
	return (1);
}
