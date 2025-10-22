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

void	ft_print_caratteri(char a, char b, char c, char d);
void	calcolo_secondo_numero(char a, char b);

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			calcolo_secondo_numero(a, b);
			b++;
		}
		a++;
	}
	write(1, "\n", 1);
}

void	calcolo_secondo_numero(char a, char b)
{
	char	c;
	char	d;

	c = a;
	while (c <= '9')
	{
		if (c == a)
		{
			d = b + 1;
		}
		else
		{
			d = '0';
		}
		while (d <= '9')
		{
			ft_print_caratteri(a, b, c, d);
			d++;
		}
		c++;
	}
}

void	ft_print_caratteri(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (!(a == '9' && b == '8' && c == '9' && d == '9'))
		write(1, ", ", 2);
}

/*int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
