/*#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char	dest1[50] = "Ciao ";
	char	src1[] = "mondo bellissimo!";
	char	dest2[50] = "Ciao ";
	char	src2[] = "mondo bellissimo!";

	printf("\nCOPIA prima: %s\n", dest1);
	ft_strncat(dest1, src1, 5);
	printf("COPIA dopo (nb = 5): %s\n\n", dest1);

	printf("ORIGINALE prima: %s\n", dest2);
	strncat(dest2, src2, 5);
	printf("ORIGINALE dopo (nb = 5): %s\n\n", dest2);

	return (0);
}*/

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}