/*#include <unistd.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	str[] = "Hello\nHow are you?\tFine.";
	ft_putstr_non_printable(str);
	write(1, "\n", 1);
	return (0);
}*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			ft_putchar('\\');
			ft_putchar(hex[(unsigned char)str[i] / 16]);
			ft_putchar(hex[(unsigned char)str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}