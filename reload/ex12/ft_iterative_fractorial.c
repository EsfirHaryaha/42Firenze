/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_fractorial.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:33:08 by eharyaha          #+#    #+#             */
/*   Updated: 2025/12/03 14:33:11 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <limits.h>

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	ris;

	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0)
	{
		return (1);
	}
	ris = 1;
	while (nb > 1)
	{
		ris = ris * nb;
		nb--;
	}
	return (ris);
}
/*
int	main(void)
{
	int nb = 5;
	int	ris;
	printf("numero %d ", nb);
	ris = ft_iterative_factorial(nb);
	printf("--> ris %d\n", ris);
	return (0);
}
*/