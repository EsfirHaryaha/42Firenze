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

int	ft_iterative_factorial(int nb);
int	iterated(int ris, int nb);

int	ft_iterative_factorial(int nb)
{
	int ris;

	ris = iterated(1, nb);
	return ris;
}

int	iterated(int ris, int nb)
{
	if(nb == 1)
	{
		return (ris);
	}
	else
	{	
	int	temp
		if(ris == 0)
			temp = nb;
		if(ris != 0)
			temp = ris;
		ris = temp * (nb - 1);
		printf(" - %d\n", ris);
		nb--;
		iterated(ris, nb);
	}
	return (0);
}

int	main(void)
{
	int nb = 5;
	int ris;
	printf("numero %d ", nb);
	ris = ft_iterative_factorial(nb);
	printf("--> ris %d\n", ris);
	return (0);
}
