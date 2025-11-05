/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:47:29 by eharyaha          #+#    #+#             */
/*   Updated: 2025/10/29 15:47:31 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	char *tests[] = {
		"123456",
		"0000",
		"123 456",
		"12a45",
		"",
		"42",
		NULL
	};

	int i = 0;
	while (tests[i])
	{
		printf("\"%s\" -> %d\n", tests[i], ft_str_is_numeric(tests[i]));
		i++;
	}
	return (0);
}
*/

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
