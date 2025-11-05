/*#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	src[] = "Stringa di test per ft_strlcpy";
	char	dest[50];
	unsigned int	len;

	len = ft_strlcpy(dest, src, 10);
	printf("\n\nsrc : %s\n", src);
	printf("dest: %s\n", dest);
	printf("lunghezza src: %u\n\n\n", len);
	return (0);
}*/

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
