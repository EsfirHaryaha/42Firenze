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

int			controlli_stringa(int argc, int *indici_visibilita, char argv[1]);
void		init_griglia(int griglia[4][4]);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int n);
int			analizza_input(char *stringa, int *indici_visibilita);
int			processa_input(char *str, int *vis);

int	main(int argc, char *argv[])
{
	int	*indici_visibilita;
	int	griglia[4][4];
	int	riga;
	int	colonna;
	int	error;

	riga = 0;
	indici_visibilita = (int *)malloc(sizeof(int) * 16);
	error = controlli_stringa(argc, indici_visibilita, argv[1]);
	if (error == 1)
		return (1);
	init_griglia(griglia);
	free(indici_visibilita);
	ft_putstr("Input corretto. Soluzione: (non l'abbiamo risolto)\n");
	return (0);
}

/*                                    metodo che doveva stare dentro main
	if (!risolvi(griglia, indici_visibilita, 0, 0))
	{
		ft_putstr("Error\n");
		free(indici_visibilita);
		return (1);
	}
*/
void	init_griglia(int griglia[4][4])
{
	int	riga;
	int	colonna;

	riga = 0;
	while (riga < 4)
	{
		colonna = 0;
		while (colonna < 4)
		{
			griglia[riga][colonna] = 0;
			colonna++;
		}
		riga++;
	}
}

int	controlli_stringa(int argc, int *indici_visibilita, char argv[1])
{
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (!indici_visibilita)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (!analizza_input(argv, indici_visibilita))
	{
		free(indici_visibilita);
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}
