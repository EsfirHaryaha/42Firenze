/*#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	*src;
	char	dest[50];

	src = "stringa sorgente";
	printf("dest prima: %s\n", dest);
	ft_strcpy(dest, src);
	printf("dest dopo: %s\n", dest);
}*/

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return dest;
}
