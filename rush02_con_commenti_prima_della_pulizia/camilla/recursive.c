/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabagaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:39:43 by kabagaev          #+#    #+#             */
/*   Updated: 2025/11/02 18:39:48 by kabagaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		str_size(char *str);
char	*find_value(char *dict, char *key);
void	convert_number(char *num, char *dict, int *first);
void	convert_tens(char *num, char *dict, int *first);
void	convert_hundreds(char *num, char *dict, int *first);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	print_word(char *dict, char *key, int *first)
{
	char	*word;

	if (*first == 0)
		write(1, " ", 1);
	*first = 0;
	word = find_value(dict, key);
	if (word)
	{
		ft_putstr(word);
		free(word);
	}
}

void	convert_tens(char *num, char *dict, int *first)
{
	char	key[3];

	key[0] = num[0];
	key[1] = '0';
	key[2] = '\0';
	print_word(dict, key, first);
	if (num[1] != '0')
		convert_number(&num[1], dict, first);
}

void	convert_hundreds(char *num, char *dict, int *first)
{
	char	key[2];

	key[0] = num[0];
	key[1] = '\0';
	print_word(dict, key, first);
	print_word(dict, "100", first);
	if (num[1] != '0' || num[2] != '0')
		convert_number(&num[1], dict, first);
}
