/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:13:49 by eharyaha          #+#    #+#             */
/*   Updated: 2025/10/30 11:13:53 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

void ft_sort_int_tab(int *tab, int size);
void	print_array(int *num, int size);

int	main(void)
{
	int arr[6] = {1, -23, 10, 5, 6754, 7};
	int *num = arr; 
	ft_sort_int_tab(num, 6);
	
	print_array(num, 6);
	
	return (0);
}

void	print_array(int *num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("\n\n%d  ", num[i]);
		i++;
	}
	printf("\n\n\n");
}*/

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;

	while (size > 1)
	{
		if (tab[size - 1] < tab[size - 2])
		{
			temp = tab[size - 1];
			tab[size - 1] = tab[size - 2];
			tab[size - 2] = temp;
		}
		size--;
		ft_sort_int_tab(tab, size);
	}
}
