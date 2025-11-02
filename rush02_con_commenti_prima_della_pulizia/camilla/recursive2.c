/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabagaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:08:52 by kabagaev          #+#    #+#             */
/*   Updated: 2025/11/02 20:08:59 by kabagaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strncpy(char *dest, char *src, int n);
void	print_word(char *dict, char *key, int *first);
void	convert_number(char *num, char *dict, int *first);
int		str_size(char *str);
void	convert_tens(char *num, char *dict, int *first);
void	convert_hundreds(char *num, char *dict, int *first);

int not_all_zero(char *str, int len)
{
    for (int i = 0; i < len; i++)
        if (str[i] != '0')
            return 1;
    return 0; 
}

void	convert_thousands_and_up(char *num, char *dict, int *first, int len)
{
	char	group[100];
	int		size;
	int		rest;

	if (len % 3 == 0)
		size = 3;
	else
		size = len % 3;
	ft_strncpy(group, num, size);
	convert_number(group, dict, first);
	rest = len - size;
	if (rest >= 9)
		print_word(dict, "1000000000", first);
	else if (rest >= 6)
		print_word(dict, "1000000", first);
	else if (rest >= 3)
		print_word(dict, "1000", first);
	if (not_all_zero(&num[size], len - size))
    		convert_number(&num[size], dict, first);

}

void	convert_number(char *num, char *dict, int *first)
{
	int	len;
	
	while (*num == '0')
        	num++;
	if (*num == '\0')
	{
		print_word(dict, "0", first);
    		return;
    	}
	len = str_size(num);
	if (len == 1 || (len == 2 && num[0] == '1'))
		print_word(dict, num, first);
	else if (len == 2)
		convert_tens(num, dict, first);
	else if (len == 3)
		convert_hundreds(num, dict, first);
	else
		convert_thousands_and_up(num, dict, first, len);
}
