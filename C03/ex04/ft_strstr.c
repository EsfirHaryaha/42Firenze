/*#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	str1[] = "Ciao mondo bellissimo";
	char	find1[] = "mondo";
	char	find2[] = "zzz";
	char	find3[] = "";
	char	find4[] = "Ciao";

	printf("\nCopia: \"%s\"  -> \"%s\"  =  %s\n", str1, find1, ft_strstr(str1, find1));
	printf("Orig:  \"%s\"  -> \"%s\"  =  %s\n\n", str1, find1, strstr(str1, find1));

	printf("Copia: \"%s\"  -> \"%s\"  =  %s\n", str1, find2, ft_strstr(str1, find2));
	printf("Orig:  \"%s\"  -> \"%s\"  =  %s\n\n", str1, find2, strstr(str1, find2));

	printf("Copia: \"%s\"  -> \"%s\"  =  %s\n", str1, find3, ft_strstr(str1, find3));
	printf("Orig:  \"%s\"  -> \"%s\"  =  %s\n\n", str1, find3, strstr(str1, find3));

	printf("Copia: \"%s\"  -> \"%s\"  =  %s\n", str1, find4, ft_strstr(str1, find4));
	printf("Orig:  \"%s\"  -> \"%s\"  =  %s\n\n", str1, find4, strstr(str1, find4));

	return (0);
}*/

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}