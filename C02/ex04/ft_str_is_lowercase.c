/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:33:54 by eharyaha          #+#    #+#             */
/*   Updated: 2025/10/29 11:34:06 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	char	*str= "tuttolowercase";
	printf("\n\n%s : %d\n", str, ft_str_is_lowercase(str));
	char	*str2 = "tuttoCamelCase";
	printf("%s : %d\n", str2, ft_str_is_lowercase(str2));
	char	*str3 = "stringa con spazi";
	printf("%s : %d\n", str3, ft_str_is_lowercase(str3));
	char	*str4 = "numeri12345";
	printf("%s : %d\n\n\n", str4, ft_str_is_lowercase(str4));
	char *str5 = "";
	printf("\"%s\" : %d\n", str5, ft_str_is_lowercase(str5));

}*/

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
