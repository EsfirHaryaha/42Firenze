/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:15:21 by eharyaha          #+#    #+#             */
/*   Updated: 2025/10/29 11:15:25 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;
	char	va;
	char	vb;

	a = 7;
	b = 2;
	va = a + '0';
	vb = b + '0';
	printf("a: %c, b: %c\n", va, vb);
	ft_ultimate_div_mod(&a, &b);
	va = a + '0';
	vb = b + '0';
	printf("a: %c, b: %c\n", va, vb);
	return (0);
}*/

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *a / *b;
	*b = temp % *b;
}
