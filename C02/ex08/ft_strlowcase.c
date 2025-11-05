/*#include <stdio.h>

char	*ft_strlowcase(char *str);

int	main(void)
{
	char	str[30] = "TeStO MISTO 123 -)+;";
	printf("\n\ninput: %s\n\nris: ", str);
	ft_strlowcase(str);
	printf("%s\n\n\n", str);
	return (0);
}*/

char	*ft_strlowcase(char *str)
{
	int	i;
	int	dif;

	i = 0;
	dif = 'a' - 'A';
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + dif;
		}
		i++;
	}
	return (str);
}
