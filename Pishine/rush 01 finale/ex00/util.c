/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spopa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:37:03 by spopa             #+#    #+#             */
/*   Updated: 2025/10/26 14:37:06 by spopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	processa_input(char *str, int *vis);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	analizza_input(char *stringa, int *indici_visibilita)
{
	if (!stringa || !indici_visibilita)
		return (0);
	return (processa_input(stringa, indici_visibilita));
}

int	processa_input(char *str, int *vis)
{
	int	i;
	int	idx;

	i = 0;
	idx = 0;
	while (str[i])
	{
		if (str[i] < '1' || str[i] > '4')
			return (0);
		vis[idx++] = str[i] - '0';
		i++;
		if (idx < 16)
		{
			if (str[i] != ' ')
				return (0);
			i++;
		}
	}
	return (idx == 16);
}

/*int	analizza_input(char *stringa, int *indici_visibilita)
{
	int	idx;
	int	i;

	i = 0;
	idx = 0;
	while (stringa[i] != '\0')
	{
		if (stringa[i] >= '1' && stringa[i] <= '4')
		{
			if (idx >= 16)
			{
				ft_putstr("Errore: più di 16 numeri inseriti\n");
				return (0);
			}
			indici_visibilita[idx++] = stringa[i] - '0';
			i++;
			if (idx < 16)
			{
				if (stringa[i] != ' ')
				{
					ft_putstr("Errore: manca spazio dopo numero\n");
					return (0);
				}
				i++;
			}
		}
		else
		{
			ft_putstr("Errore: carattere non valido nell'input\n");
			return (0);
		}
	}
	if (idx != 16)
	{
		ft_putstr("Errore: numero di valori diversi da 16\n");
		return (0);
	}
	return (1);
}*/
