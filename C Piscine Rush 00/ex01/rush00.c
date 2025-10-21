void ft_putchar(char a, char b, char c, int z);

void	rush00(int x, int y)
{
	int	r;

	if (x <= 0 || y <= 0)
		return;

	r = 0;

	while (r < y)
	{
		if (r == 0)
			ft_putchar('/', '*', '\\', x);
		else if ( r == y  - 1)
			ft_putchar('\\', '*', '/', x);
		else 
			ft_putchar('*', ' ', '*', x);
		r++;
	}
}
