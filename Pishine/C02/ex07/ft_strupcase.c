/*#include <stdio.h>

char *ft_strupcase(char *str);

int	main(void)
{
	char	str[20] = "tEstO Misto 12 -)+;";
	printf("\n\ninput: %s\n\nris: ", str);
	ft_strupcase(str);
	printf("%s\n\n\n", str);
	return (0);
}*/

char *ft_strupcase(char *str)
{
	int	i;
	int	dif;

	i = 0;
	dif = 'a' - 'A';
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - dif;
		}
		i++;
	}
	return str;
}