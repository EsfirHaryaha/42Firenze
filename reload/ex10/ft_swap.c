#include <stdio.h>
void    ft_swap(int *a, int *b);

void    ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(void)
{
	int	a;
	int	b;

	a = 1;
	b = 2;
	printf("valori iniziali a e b : %d, %d\n", a, b);
	ft_swap(&a, &b);
	printf("valori scambiati a e b : %d, %d\n", a, b);
	return (0);
}