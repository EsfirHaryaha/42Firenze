/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:45:45 by eharyaha          #+#    #+#             */
/*   Updated: 2025/10/29 15:45:47 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	src1[] = "Stringa sorgente ex 01";
	char	dest1[50] = "";
	char	dest2[50] = "";
	char	dest3[50] = "";

	// Caso 1: n < lunghezza di src → copia solo una parte
	ft_strncpy(dest1, src1, 5);
	printf("Caso 1 (n < len):   n=5\n");
	printf("Result: \"%s\"\n\n", dest1);

	// Caso 2: n == lunghezza di src → copia tutto, nessun padding extra
	ft_strncpy(dest2, src1, 22); // "Stringa sorgente ex 01" ha 22 caratteri
	printf("Caso 2 (n == len):  n=22\n");
	printf("Result: \"%s\"\n\n", dest2);

	// Caso 3: n > lunghezza di src → copia tutto e riempie con '\\0'
	ft_strncpy(dest3, src1, 40);
	printf("Caso 3 (n > len):   n=40\n");
	printf("Result: \"%s\"\n\n", dest3);

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
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
