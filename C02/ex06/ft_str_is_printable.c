/*#include <stdio.h>

int ft_str_is_printable(char *str);

int	main(void)
{
	int	ris;

	char	str1[] = "caratteri stampabili (ab12-+,;)";
	char	str2[] = "a capo, non stampabile \n";
	char	str3[] = "";

	ris = ft_str_is_printable(str1);
	printf("\n\n\n%s   :   %d", str1, ris);

	ris = ft_str_is_printable(str2);
	printf("\n\n%s   :   %d", str2, ris);

	ris = ft_str_is_printable(str3);
	printf("\n\nstringa vuota %s   :   %d\n\n", str3, ris);
	
	return (0);
}*/

int ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			return (0);
		}
		i++;
	}
	return (1);
}