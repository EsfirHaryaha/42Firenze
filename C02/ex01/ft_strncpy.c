/*#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	*src;
	char	dest[50];

	src = "Stringa sorgente ex 01";
	printf("dest prima: %s\n", dest);
	ft_strncpy(dest, src, 5);
	printf("dest dopo: %s\n", dest);
	return (0);
}*/

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}