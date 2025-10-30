#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_comb(int *tab, int n)
{
	int	i;
	int	last;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	if (tab[0] != 10 - n) // controlla se è l'ultima combinazione
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	int	tab[10];
	int	i;

	if (n <= 0 || n >= 10)
		return ;
	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	while (tab[0] <= 10 - n)
	{
		print_comb(tab, n);
		i = n - 1;
		while (i >= 0 && tab[i] == 9 - (n - 1 - i))
			i--;
		if (i < 0)
			break ;
		tab[i]++;
		while (++i < n)
			tab[i] = tab[i - 1] + 1;
	}
}
