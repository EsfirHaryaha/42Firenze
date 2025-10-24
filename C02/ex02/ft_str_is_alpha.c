/*#include <stdio.h>

int	ft_str_is_alpha(char *str);

int	main(void)
{
	char	*str1;
	char	*str2;
	int	ris1;
	int	ris2;

	str1 = "stringa con spazi";
	str2 = "stringaConSoloCaratteri";
	ris1 = ft_str_is_alpha(str1);
	ris2 = ft_str_is_alpha(str2);
	printf("%s : %d\n", str1, ris1);
	printf("%s : %d\n", str2, ris2);
}*/

int	ft_str_is_alpha(char *str)
{
	int	n;
	int	i;

	n = 1;
	i = 0;
	while (n == 1 && str[i] != '\0')
	{
		if(!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
		{
			n = 0;
		}
		i++;
	}
	return n;
}