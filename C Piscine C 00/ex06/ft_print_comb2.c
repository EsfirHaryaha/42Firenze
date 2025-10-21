/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:36:17 by eharyaha          #+#    #+#             */
/*   Updated: 2025/10/21 16:36:39 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_second_comb(char a, char b, char c, char d);

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0';
	b = '0';
	c = '0';
	while (a <= '9')
	{
		while (b <= '8')
		{
			while (c <= '9')
			{
				while (d <= '9')
				{
					d = b + 1;
					ft_print_caratteri( a, b, c, d);
					d++;
				}
				d = c + 1;
				c++;
			}
			c = b + 1;
			b++;
		}
		b = a + 1;
		a++;
	}
}

void	ft_print_caratteri(char a, char b, char c, char d)
{
	if (a != c || b != d)
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, " ", 1);
		write(1, &c, 1);
		write(1, &d, 1);
		if (a == '9' && b == '8' && c == '9' && d == '9')
		{
		}
		else
		{
			write(1, ", ", 2);
		}
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
