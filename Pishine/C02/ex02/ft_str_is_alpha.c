/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:46:13 by eharyaha          #+#    #+#             */
/*   Updated: 2025/10/29 15:46:16 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int	ft_str_is_alpha(char *str);

int	main(void)
{
	char *tests[] = {
		"stringaConSoloLettere",
		"StringaMista123",
		"Con Spazi",
		"",
		"ABCxyz",
		"@lfa",
		NULL
	};

	int i = 0;
	while (tests[i])
	{
		printf("\"%s\" -> %d\n", tests[i], ft_str_is_alpha(tests[i]));
		i++;
	}
	return (0);
}
*/

int	ft_str_is_alpha(char *str)
{
	int	n;
	int	i;

	n = 1;
	i = 0;
	while (n == 1 && str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
		{
			n = 0;
		}
		i++;
	}
	return (n);
}
