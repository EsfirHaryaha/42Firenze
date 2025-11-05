/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:21:00 by eharyaha          #+#    #+#             */
/*   Updated: 2025/11/05 17:21:03 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char	s1[] = "abcdef";
	char	s2[] = "abcxyz";
	unsigned int	n = 3;
	int	ris;
	int	ris2;

	ris = ft_strncmp(s1, s2, n);
	printf("\nCOPIA      %s  e  %s  (n=%d) : %d\n", s1, s2, n, ris);
	ris2 = strncmp(s1, s2, n);
	printf("ORIGINALE  %s  e  %s  (n=%d) : %d\n\n", s1, s2, n, ris2);

	n = 4;
	ris = ft_strncmp(s1, s2, n);
	printf("COPIA      %s  e  %s  (n=%d) : %d\n", s1, s2, n, ris);
	ris2 = strncmp(s1, s2, n);
	printf("ORIGINALE  %s  e  %s  (n=%d) : %d\n\n", s1, s2, n, ris2);

	return (0);
}*/

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
