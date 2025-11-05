/*#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char	dest1[50] = "Ciao ";
	char	src1[] = "mondo!";
	char	dest2[50] = "Ciao ";
	char	src2[] = "mondo!";

	printf("\nCOPIA prima: %s\n", dest1);
	ft_strcat(dest1, src1);
	printf("COPIA dopo:  %s\n\n", dest1);

	printf("ORIGINALE prima: %s\n", dest2);
	strcat(dest2, src2);
	printf("ORIGINALE dopo:  %s\n\n", dest2);

	return (0);
}*/

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
