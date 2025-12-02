#include <unistd.h>
#include <stdio.h>
void	ft_ft(int *nbr);

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int	main(void)
{
	int	a;

	ft_ft(&a);
	printf("risultato: %d\n", a);
	return (0);
}



/*

- non posso stampare gli int con write write(1, &a, 1); non va se a e' un int!
- il puntatore int	* e' diverso da int normale, per asseggnare il valore al puntatore devo creare una variabile e merrere &variabile al puntatore


*/