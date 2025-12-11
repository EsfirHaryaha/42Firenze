/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <eharyaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:36:15 by eharyaha          #+#    #+#             */
/*   Updated: 2025/12/11 15:19:04 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
size_t	ft_strlen(const char *c);

int	main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("ERROR: passare il nome della funzione che si vuole testare\n");
	}

	if(strcmp(argv[1], "ft_isalpha") == 0)
	{
		char ris = ft_isalpha(argv[2][0]) + '0';
		printf("%c\n", ris);
		return (0);
	}
	
	if(strcmp(argv[1], "ft_isdigit") == 0)
	{
		printf("input: 1 --> %d\n", ft_isdigit(1));
		printf("input: 'a' --> %d\n", ft_isdigit('a'));
		printf("input: '1' --> %d\n", ft_isdigit('1'));
		printf("input: 0 --> %d\n", ft_isdigit(0));
		return (0);
	}
	
	if(strcmp(argv[1], "ft_isalnum") == 0)
	{
		printf("input: 1 --> %d\n", ft_isalnum(1));
		printf("input: 'a' --> %d\n", ft_isalnum('a'));
		printf("input: '1' --> %d\n", ft_isalnum('1'));
		printf("input: 0 --> %d\n", ft_isalnum(0));
		return(0);
	}
	
	if(strcmp(argv[1], "ft_isascii") == 0)
	{
		printf("input: 1 --> %d\n", ft_isascii(1));
		printf("input: 127 --> %d\n", ft_isascii(127));
		printf("input: a --> %d\n", ft_isascii('a'));
		printf("input: 200 --> %d\n", ft_isascii(200));
		printf("input non ascii: -1 --> %d\n", ft_isascii(-1));
		return (0);
	}
	
	if(strcmp(argv[1], "ft_isprint") == 0)
	{
		printf("input: ' ' (spazio) --> %d\n", ft_isprint(' '));
		printf("input: 126 --> %d\n", ft_isprint(126));
		printf("input: \\n --> %d\n", ft_isprint('\n'));
		printf("input: 1 --> %d\n", ft_isprint(1));
		printf("input: 127 --> %d\n", ft_isprint(127));
		return (0);
	}
	
	if(strcmp(argv[1], "ft_strlen") == 0)
	{
		printf("input: ciao --> %ld\n", ft_strlen("ciao"));
		printf("input: \"\" --> %ld\n", ft_strlen(""));
		printf("input: \" \" --> %ld\n", ft_strlen(" "));
		printf("input: 'ciao ciao' --> %ld\n", ft_strlen("ciao ciao"));
		return (0);
	}

	if(strcmp(argv[1], "ft_memset") == 0)
	{
		char buffer[10];

		ft_memset(buffer, 'a', 5);
		/* TESTARE MEMSET*/
		return (0);
	}

	if(strcmp(argv[1], "ft_bzero") == 0)
	{
		char buffer[10];

		ft_memset(buffer, 'a', 5);
		/* TESTARE bzero*/
		return (0);
	}

	printf("Funzione '%s' non trovata\n", argv[1]);
	return (0);
}

