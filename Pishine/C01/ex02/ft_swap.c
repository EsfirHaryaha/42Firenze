/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:14:40 by eharyaha          #+#    #+#             */
/*   Updated: 2025/10/29 11:14:45 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>

void	ft_swap(int *a, int *b);
void	ft_print(int a, int b);

int	main(void)
{
	int	a;
	int	b;

	a = 2;
	b = 5;
	ft_print(a, b);
	ft_swap(&a, &b);
	ft_print(a, b);
	return(0);
}

void	ft_print(int a, int b)
{
	char	ca;
	char	cb;

	ca = a + '0';
	cb = b + '0';
	write(1, &ca, 1);
	write(1, &cb, 1);
	write(1, "\n", 1);
}*/

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
