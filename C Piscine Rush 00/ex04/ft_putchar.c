#include <unistd.h>

void ft_putchar(char a, char b, char z, int x)
{
	int	c;

	write(1, &a,1);
	c = 0;
	while(c < x - 2)
	{
		write(1, &b, 1);
		c++;
	}
	if(x > 1)
		write(1, &z, 1);
	write(1, " ", 1);
	write(1, "\n", 1);
}
