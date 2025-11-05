/*#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	dest1[30] = "Ciao ";
	char	src1[] = "mondo!";
	char	dest2[30] = "Ciao ";
	char	src2[] = "mondo!";

	unsigned int	r1 = ft_strlcat(dest1, src1, 10);
	unsigned int	r2 = strlcat(dest2, src2, 10);

	printf("\nCopia: \"%s\"  (ritorno: %u)\n", dest1, r1);
	printf("Orig:  \"%s\"  (ritorno: %u)\n\n", dest2, r2);

	char	dest3[10] = "12345";
	char	src3[] = "ABCDE";
	printf("Copia: \"%s\"  -> %u\n", dest3, ft_strlcat(dest3, src3, 9));

	return (0);
}*/

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = dest_len;
	j = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[j] != '\0' && (i + 1) < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}