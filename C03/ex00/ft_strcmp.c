/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:20:40 by eharyaha          #+#    #+#             */
/*   Updated: 2025/11/05 17:20:44 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	s1[] = "abcd";
	char	s2[] = "abcd";

	int ris = ft_strcmp(s1, s2);
	printf("\nCOPIA   %s  e  %s  :  %d\n\n", s1, s2, ris);

	int ris2 = strcmp(s1, s2);
	printf("ORIGINALE   %s  e  %s  :  %d\n\n", s1, s2, ris2);
//-------------------------

	char	s3[] = "abc";
	char	s4[] = "abcd";

	ris = ft_strcmp(s3, s4);
	printf("\nCOPIA   %s  e  %s  :  %d\n\n", s3, s4, ris);

	ris2 = strcmp(s3, s4);
	printf("ORIGINALE   %s  e  %s  :  %d\n\n", s3, s4, ris2);

//-------------------------

	char	s5[] = "abcd";
	char	s6[] = "abc";

	ris = ft_strcmp(s5, s6);
	printf("\nCOPIA   %s  e  %s  :  %d\n\n", s5, s6, ris);

	ris2 = strcmp(s5, s6);
	printf("ORIGINALE   %s  e  %s  :  %d\n\n", s5, s6, ris2);
//------------------------

	char	s7[] = "abcd";
	char	s8[] = "abcz";

	ris = ft_strcmp(s7, s8);
	printf("\nCOPIA   %s  e  %s  :  %d\n\n", s7, s8, ris);

	ris2 = strcmp(s7, s8);
	printf("ORIGINALE   %s  e  %s  :  %d\n\n", s7, s8, ris2);

}  */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
