/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:54:14 by eharyaha          #+#    #+#             */
/*   Updated: 2025/10/27 15:54:17 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);
void	print_array(int *arr, size_t len);

int	main(void)
{
	int	*array;

	array = (int []){1, 4, 3, 4, 1, 6};
	ft_rev_int_tab(array, 6);
	print_array(array, 6);
	return (0);
}

void	print_array(int *arr, size_t len)
{
	int	i;

	putchar('{');
	i = 0;
	while (i < len - 1)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	printf("%d}\n", arr[i]);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size)
	{
		temp = tab[i];
		tab[i] = tab[size-1];
		tab[(size-1)] = temp;
		i++;
		size--;
	}
}
