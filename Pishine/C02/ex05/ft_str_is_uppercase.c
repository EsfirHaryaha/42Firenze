/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:56:06 by eharyaha          #+#    #+#             */
/*   Updated: 2025/10/29 14:56:10 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	char	*str= "TUTTOUPPERCASE";
	printf("\n\n%s : %d\n", str, ft_str_is_uppercase(str));
	char	*str2 = "CAMELcASEiNVERTITO";
	printf("%s : %d\n", str2, ft_str_is_uppercase(str2));
	char	*str3 = "CON SPAZI";
	printf("%s : %d\n", str3, ft_str_is_uppercase(str3));
	char	*str4 = "NUMERI123";
	printf("%s : %d\n\n\n", str4, ft_str_is_uppercase(str4));
}*/

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'Z')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
