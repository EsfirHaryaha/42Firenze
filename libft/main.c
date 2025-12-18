/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <eharyaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:36:15 by eharyaha          #+#    #+#             */
/*   Updated: 2025/12/17 20:27:27 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

int test(char *function);

static long offset(void *base, void *ptr)
{
    if (!ptr)
        return (-1);
    return ((unsigned char *)ptr - (unsigned char *)base);
}

static const char *cmp_result(int r)
{
    if (r < 0)
        return "< 0";
    if (r > 0)
        return "> 0";
    return "== 0";
}

static int is_all_zero(unsigned char *p, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        if (p[i] != 0)
            return (0);
        i++;
    }
    return (1);
}

static void	print_atoi_test(char *s, int expected)
{
	int	ft;

	ft = ft_atoi(s);
	printf("%s -- \"%s\" | expected=%d got=%d\n",
		(ft == expected) ? "PASS" : "FAIL",
		s, expected, ft);
}

int	main(int argc, char **argv)
{
	char **funzioni;
	int n_funzioni;
	int	ris;

	if (argc < 2)
	{
		static char *default_funzioni[] = {
			"isalpha",
			"isdigit",
			"isalnum",
			"isascii",
			"isprint",
			"strlen",
			"memset",
			"bzero",
			"memcpy",
			"memmove", //10 funzioni
			"strlcpy",
			"strlcat",
			"toupper",
			"tolower",
			"strchr", //15
			"strrchr",
			"strncmp",
			"memchr",
			"memcmp",
			"strnstr", // 20 funzioni
			"atoi",
			"calloc",
			"strdup",
			"substr",
			"strjoin", //25
			"strtrim",
			"split"
		};
		funzioni = default_funzioni;
		n_funzioni = 27;
	}
	else
	{
		funzioni = &argv[1];  // puntatore al primo argomento
		n_funzioni = 1;
	}

	while (n_funzioni > 0)
	{
		ris = test(funzioni[n_funzioni - 1]);
		n_funzioni --;
	}
	
	if (ris != 0)
	{
		printf("Funzione '%s' non trovata\n", argv[1]);
	}

	return (0);
}

int test(char *function)
{
	
	if (strcmp(function, "isalpha") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		char c;
		int ft, std;

		/* Test 1: lettera minuscola 'a' */
		c = 'a';
		ft = ft_isalpha(c);
		std = isalpha(c);
		printf("%s -- Test: lettera minuscola | Input: '%c' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 2: lettera maiuscola 'Z' */
		c = 'Z';
		ft = ft_isalpha(c);
		std = isalpha(c);
		printf("%s -- Test: lettera maiuscola | Input: '%c' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 3: lettera minuscola 'z' */
		c = 'z';
		ft = ft_isalpha(c);
		std = isalpha(c);
		printf("%s -- Test: lettera minuscola 'z' | Input: '%c' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 4: lettera maiuscola 'A' */
		c = 'A';
		ft = ft_isalpha(c);
		std = isalpha(c);
		printf("%s -- Test: lettera maiuscola 'A' | Input: '%c' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 5: numero '0' */
		c = '0';
		ft = ft_isalpha(c);
		std = isalpha(c);
		printf("%s -- Test: numero '0' | Input: '%c' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 6: numero '9' */
		c = '9';
		ft = ft_isalpha(c);
		std = isalpha(c);
		printf("%s -- Test: numero '9' | Input: '%c' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 7: simbolo '@' */
		c = '@';
		ft = ft_isalpha(c);
		std = isalpha(c);
		printf("%s -- Test: simbolo '@' | Input: '%c' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 8: spazio ' ' */
		c = ' ';
		ft = ft_isalpha(c);
		std = isalpha(c);
		printf("%s -- Test: spazio | Input: ' ' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", std, ft);

		/* Test 9: newline '\n' */
		c = '\n';
		ft = ft_isalpha(c);
		std = isalpha(c);
		printf("%s -- Test: newline | Input: '\\n' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", std, ft);

		/* Test 10: tab '\t' */
		c = '\t';
		ft = ft_isalpha(c);
		std = isalpha(c);
		printf("%s -- Test: tab | Input: '\\t' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", std, ft);

		printf("\n");
		return (0);
	}

	
	if (strcmp(function, "isdigit") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		char c;
		int ft, std;

		/* Test 1: cifra '0' */
		c = '0';
		ft = ft_isdigit(c);
		std = isdigit(c);
		printf("%s -- Test: cifra '0' | Input: '%c' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 2: cifra '5' */
		c = '5';
		ft = ft_isdigit(c);
		std = isdigit(c);
		printf("%s -- Test: cifra '5' | Input: '%c' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 3: cifra '9' */
		c = '9';
		ft = ft_isdigit(c);
		std = isdigit(c);
		printf("%s -- Test: cifra '9' | Input: '%c' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 4: lettera minuscola 'a' */
		c = 'a';
		ft = ft_isdigit(c);
		std = isdigit(c);
		printf("%s -- Test: lettera minuscola | Input: '%c' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 5: lettera maiuscola 'A' */
		c = 'A';
		ft = ft_isdigit(c);
		std = isdigit(c);
		printf("%s -- Test: lettera maiuscola | Input: '%c' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 6: simbolo '+' */
		c = '+';
		ft = ft_isdigit(c);
		std = isdigit(c);
		printf("%s -- Test: simbolo '+' | Input: '%c' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 7: simbolo '-' */
		c = '-';
		ft = ft_isdigit(c);
		std = isdigit(c);
		printf("%s -- Test: simbolo '-' | Input: '%c' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 8: spazio ' ' */
		c = ' ';
		ft = ft_isdigit(c);
		std = isdigit(c);
		printf("%s -- Test: spazio | Input: ' ' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", std, ft);

		/* Test 9: carattere fuori range '/' */
		c = '/';
		ft = ft_isdigit(c);
		std = isdigit(c);
		printf("%s -- Test: carattere '/' (prima di '0') | Input: '%c' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 10: carattere fuori range ':' */
		c = ':';
		ft = ft_isdigit(c);
		std = isdigit(c);
		printf("%s -- Test: carattere ':' (dopo '9') | Input: '%c' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", c, std, ft);

		printf("\n");
		return (0);
	}
	
	if (strcmp(function, "isalnum") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		char c;
		int ft, std;

		/* Test 1: lettera maiuscola 'A' */
		c = 'A';
		ft = ft_isalnum(c);
		std = isalnum(c);
		printf("%s -- Test: lettera maiuscola | Input: '%c' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 2: lettera minuscola 'z' */
		c = 'z';
		ft = ft_isalnum(c);
		std = isalnum(c);
		printf("%s -- Test: lettera minuscola | Input: '%c' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 3: cifra '0' */
		c = '0';
		ft = ft_isalnum(c);
		std = isalnum(c);
		printf("%s -- Test: cifra '0' | Input: '%c' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 4: cifra '9' */
		c = '9';
		ft = ft_isalnum(c);
		std = isalnum(c);
		printf("%s -- Test: cifra '9' | Input: '%c' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 5: simbolo '#' */
		c = '#';
		ft = ft_isalnum(c);
		std = isalnum(c);
		printf("%s -- Test: simbolo '#' | Input: '%c' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 6: spazio ' ' */
		c = ' ';
		ft = ft_isalnum(c);
		std = isalnum(c);
		printf("%s -- Test: spazio | Input: ' ' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", std, ft);

		/* Test 7: newline '\n' */
		c = '\n';
		ft = ft_isalnum(c);
		std = isalnum(c);
		printf("%s -- Test: newline | Input: '\\n' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", std, ft);

		/* Test 8: simbolo '@' */
		c = '@';
		ft = ft_isalnum(c);
		std = isalnum(c);
		printf("%s -- Test: simbolo '@' | Input: '%c' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", c, std, ft);

		printf("\n");
		return (0);
	}

	if (strcmp(function, "isascii") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		int c;
		int ft, std;

		/* Test 1: minimo valido 0 (NUL) */
		c = 0;
		ft = ft_isascii(c);
		std = isascii(c);
		printf("%s -- Test: minimo valido (0) | Input: %d | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 2: carattere valido 65 ('A') */
		c = 65;
		ft = ft_isascii(c);
		std = isascii(c);
		printf("%s -- Test: carattere valido (65='A') | Input: %d | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 3: massimo valido 127 (DEL) */
		c = 127;
		ft = ft_isascii(c);
		std = isascii(c);
		printf("%s -- Test: massimo valido (127) | Input: %d | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 4: fuori range 128 */
		c = 128;
		ft = ft_isascii(c);
		std = isascii(c);
		printf("%s -- Test: fuori range (128) | Input: %d | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 5: fuori range 255 */
		c = 255;
		ft = ft_isascii(c);
		std = isascii(c);
		printf("%s -- Test: fuori range (255) | Input: %d | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 6: negativo -1 */
		c = -1;
		ft = ft_isascii(c);
		std = isascii(c);
		printf("%s -- Test: negativo (-1) | Input: %d | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 7: valore intermedio 64 */
		c = 64;
		ft = ft_isascii(c);
		std = isascii(c);
		printf("%s -- Test: valore intermedio (64) | Input: %d | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		printf("\n");
		return (0);
	}

	if (strcmp(function, "isprint") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		char c;
		int ft, std;

		/* Test 1: spazio ' ' (minimo stampabile) */
		c = ' ';
		ft = ft_isprint(c);
		std = isprint(c);
		printf("%s -- Test: spazio (minimo stampabile) | Input: ' ' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", std, ft);

		/* Test 2: carattere visibile 'A' */
		c = 'A';
		ft = ft_isprint(c);
		std = isprint(c);
		printf("%s -- Test: carattere visibile 'A' | Input: '%c' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 3: carattere visibile '~' (massimo stampabile) */
		c = '~';
		ft = ft_isprint(c);
		std = isprint(c);
		printf("%s -- Test: carattere '~' (massimo stampabile) | Input: '%c' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		/* Test 4: newline '\n' (non stampabile) */
		c = '\n';
		ft = ft_isprint(c);
		std = isprint(c);
		printf("%s -- Test: newline (non stampabile) | Input: '\\n' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", std, ft);

		/* Test 5: tab '\t' (non stampabile) */
		c = '\t';
		ft = ft_isprint(c);
		std = isprint(c);
		printf("%s -- Test: tab (non stampabile) | Input: '\\t' | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", std, ft);

		/* Test 6: DEL 127 (non stampabile) */
		c = 127;
		ft = ft_isprint(c);
		std = isprint(c);
		printf("%s -- Test: DEL (127, non stampabile) | Input: 127 | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", std, ft);

		/* Test 7: carattere 31 (non stampabile, prima di spazio) */
		c = 31;
		ft = ft_isprint(c);
		std = isprint(c);
		printf("%s -- Test: carattere 31 (non stampabile) | Input: 31 | Atteso: 0 (std=%d) | Ottenuto: %d\n",
			(ft == 0 && std == 0) ? "PASS" : "FAIL", std, ft);

		/* Test 8: numero '0' (stampabile) */
		c = '0';
		ft = ft_isprint(c);
		std = isprint(c);
		printf("%s -- Test: numero '0' (stampabile) | Input: '%c' | Atteso: !=0 (std=%d) | Ottenuto: %d\n",
			(ft != 0 && std != 0) ? "PASS" : "FAIL", c, std, ft);

		printf("\n");
		return (0);
	}
	
	if (strcmp(function, "strlen") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		const char *s;
		size_t ft, std;

		/* Test 1: stringa normale */
		s = "ciao";
		ft = ft_strlen(s);
		std = strlen(s);
		printf("%s -- Test: stringa normale | Input: \"%s\" | Atteso: %zu (std=%zu) | Ottenuto: %zu\n",
			(ft == std) ? "PASS" : "FAIL", s, std, std, ft);

		/* Test 2: stringa vuota */
		s = "";
		ft = ft_strlen(s);
		std = strlen(s);
		printf("%s -- Test: stringa vuota | Input: \"\" | Atteso: %zu (std=%zu) | Ottenuto: %zu\n",
			(ft == std) ? "PASS" : "FAIL", std, std, ft);

		/* Test 3: stringa con uno spazio */
		s = " ";
		ft = ft_strlen(s);
		std = strlen(s);
		printf("%s -- Test: stringa con uno spazio | Input: \" \" | Atteso: %zu (std=%zu) | Ottenuto: %zu\n",
			(ft == std) ? "PASS" : "FAIL", std, std, ft);

		/* Test 4: stringa con spazi multipli */
		s = "ciao ciao";
		ft = ft_strlen(s);
		std = strlen(s);
		printf("%s -- Test: stringa con spazi | Input: \"%s\" | Atteso: %zu (std=%zu) | Ottenuto: %zu\n",
			(ft == std) ? "PASS" : "FAIL", s, std, std, ft);

		/* Test 5: stringa lunga con caratteri speciali */
		s = "!@#$%^&*()";
		ft = ft_strlen(s);
		std = strlen(s);
		printf("%s -- Test: caratteri speciali | Input: \"%s\" | Atteso: %zu (std=%zu) | Ottenuto: %zu\n",
			(ft == std) ? "PASS" : "FAIL", s, std, std, ft);

		/* Test 6: stringa con newline */
		s = "hello\nworld";
		ft = ft_strlen(s);
		std = strlen(s);
		printf("%s -- Test: stringa con newline | Input: \"hello\\nworld\" | Atteso: %zu (std=%zu) | Ottenuto: %zu\n",
			(ft == std) ? "PASS" : "FAIL", std, std, ft);

		/* Test 7: stringa con tab */
		s = "hello\tworld";
		ft = ft_strlen(s);
		std = strlen(s);
		printf("%s -- Test: stringa con tab | Input: \"hello\\tworld\" | Atteso: %zu (std=%zu) | Ottenuto: %zu\n",
			(ft == std) ? "PASS" : "FAIL", std, std, ft);

		/* Test 8: stringa molto lunga */
		s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		ft = ft_strlen(s);
		std = strlen(s);
		printf("%s -- Test: stringa lunga | Input: \"%s...\" | Atteso: %zu (std=%zu) | Ottenuto: %zu\n",
			(ft == std) ? "PASS" : "FAIL", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", std, std, ft);

		printf("\n");
		return 0;
	}

	if (strcmp(function, "memset") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		char buf1[10], buf2[10];
		int i, pass, c;
		size_t n;
		int first_diff = -1;

		/* Test 1: riempi tutto il buffer con 'A' */
		for (i = 0; i < 10; i++) buf1[i] = buf2[i] = 0;
		c = 'A';
		n = 10;
		ft_memset(buf1, c, n);
		memset(buf2, c, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (buf1[i] != buf2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: riempi tutto buffer | Input: buf inizializzato a 0, c='%c', n=%zu | ", 
			pass ? "PASS" : "FAIL", c, n);
		if (pass)
			printf("Atteso: tutti 'A' | Ottenuto: tutti 'A'\n");
		else
			printf("Atteso: tutti 'A' | Ottenuto: differenza a byte[%d] (ft='%c' std='%c')\n", 
				first_diff, buf1[first_diff], buf2[first_diff]);

		/* Test 2: primi 5 byte a zero, resto invariato */
		for (i = 0; i < 10; i++) buf1[i] = buf2[i] = 'x';
		c = 0;
		n = 5;
		ft_memset(buf1, c, n);
		memset(buf2, c, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (buf1[i] != buf2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: primi 5 byte a zero | Input: buf='xxxxxxxxxx', c=0, n=%zu | ", 
			pass ? "PASS" : "FAIL", n);
		if (pass)
			printf("Atteso: [0,0,0,0,0,'x','x','x','x','x'] | Ottenuto: corretto\n");
		else
			printf("Atteso: primi 5=0 resto='x' | Ottenuto: differenza a byte[%d] (ft=%d std=%d)\n", 
				first_diff, (unsigned char)buf1[first_diff], (unsigned char)buf2[first_diff]);

		/* Test 3: zero lunghezza */
		for (i = 0; i < 10; i++) buf1[i] = buf2[i] = 'y';
		c = 'Z';
		n = 0;
		ft_memset(buf1, c, n);
		memset(buf2, c, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (buf1[i] != buf2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: lunghezza 0 | Input: buf='yyyyyyyyyy', c='%c', n=%zu | ", 
			pass ? "PASS" : "FAIL", c, n);
		if (pass)
			printf("Atteso: buffer invariato ('yyyyyyyyyy') | Ottenuto: invariato\n");
		else
			printf("Atteso: invariato | Ottenuto: differenza a byte[%d] (ft='%c' std='%c')\n", 
				first_diff, buf1[first_diff], buf2[first_diff]);

		/* Test 4: valore intermedio */
		for (i = 0; i < 10; i++) buf1[i] = buf2[i] = 0;
		c = 42;
		n = 7;
		ft_memset(buf1, c, n);
		memset(buf2, c, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (buf1[i] != buf2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: valore intermedio | Input: buf inizializzato a 0, c=%d, n=%zu | ", 
			pass ? "PASS" : "FAIL", c, n);
		if (pass)
			printf("Atteso: primi 7=%d resto=0 | Ottenuto: corretto\n", c);
		else
			printf("Atteso: primi 7=%d | Ottenuto: differenza a byte[%d] (ft=%d std=%d)\n", 
				c, first_diff, (unsigned char)buf1[first_diff], (unsigned char)buf2[first_diff]);

		printf("\n");
		return 0;
	}

	if (strcmp(function, "bzero") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		char buf1[10], buf2[10];
		int i, pass;
		size_t n;
		int first_diff = -1;

		/* Test 1: primi 5 byte a zero */
		ft_memset(buf1, 'X', 10);
		memset(buf2, 'X', 10);
		n = 5;
		ft_bzero(buf1, n);
		bzero(buf2, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (buf1[i] != buf2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: primi 5 byte a zero | Input: buf='XXXXXXXXXX', n=%zu | ", 
			pass ? "PASS" : "FAIL", n);
		if (pass)
		{
			pass = 1;
			for (i = 0; i < 5; i++)
				if (buf1[i] != 0) pass = 0;
			for (i = 5; i < 10; i++)
				if (buf1[i] != 'X') pass = 0;
			printf("Atteso: [0,0,0,0,0,'X','X','X','X','X'] | Ottenuto: %s\n", 
				pass ? "corretto" : "ERRORE nel contenuto");
		}
		else
			printf("Atteso: primi 5=0 resto='X' | Ottenuto: differenza a byte[%d] (ft=%d std=%d)\n", 
				first_diff, (unsigned char)buf1[first_diff], (unsigned char)buf2[first_diff]);

		/* Test 2: tutto il buffer a zero */
		ft_memset(buf1, 'X', 10);
		memset(buf2, 'X', 10);
		n = 10;
		ft_bzero(buf1, n);
		bzero(buf2, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (buf1[i] != buf2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: tutto buffer a zero | Input: buf='XXXXXXXXXX', n=%zu | ", 
			pass ? "PASS" : "FAIL", n);
		if (pass)
		{
			pass = 1;
			for (i = 0; i < 10; i++)
				if (buf1[i] != 0) pass = 0;
			printf("Atteso: tutti 0 | Ottenuto: %s\n", pass ? "corretto" : "ERRORE");
		}
		else
			printf("Atteso: tutti 0 | Ottenuto: differenza a byte[%d] (ft=%d std=%d)\n", 
				first_diff, (unsigned char)buf1[first_diff], (unsigned char)buf2[first_diff]);

		/* Test 3: lunghezza zero */
		ft_memset(buf1, 'X', 10);
		memset(buf2, 'X', 10);
		n = 0;
		ft_bzero(buf1, n);
		bzero(buf2, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (buf1[i] != buf2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: lunghezza 0 | Input: buf='XXXXXXXXXX', n=%zu | ", 
			pass ? "PASS" : "FAIL", n);
		if (pass)
		{
			pass = 1;
			for (i = 0; i < 10; i++)
				if (buf1[i] != 'X') pass = 0;
			printf("Atteso: buffer invariato ('XXXXXXXXXX') | Ottenuto: %s\n", 
				pass ? "invariato" : "ERRORE");
		}
		else
			printf("Atteso: invariato | Ottenuto: differenza a byte[%d] (ft=%d std=%d)\n", 
				first_diff, (unsigned char)buf1[first_diff], (unsigned char)buf2[first_diff]);

		/* Test 4: parziale (3 byte) */
		ft_memset(buf1, 'A', 10);
		memset(buf2, 'A', 10);
		n = 3;
		ft_bzero(buf1, n);
		bzero(buf2, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (buf1[i] != buf2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: primi 3 byte a zero | Input: buf='AAAAAAAAAA', n=%zu | ", 
			pass ? "PASS" : "FAIL", n);
		if (pass)
		{
			pass = 1;
			for (i = 0; i < 3; i++)
				if (buf1[i] != 0) pass = 0;
			for (i = 3; i < 10; i++)
				if (buf1[i] != 'A') pass = 0;
			printf("Atteso: [0,0,0,'A','A','A','A','A','A','A'] | Ottenuto: %s\n", 
				pass ? "corretto" : "ERRORE");
		}
		else
			printf("Atteso: primi 3=0 resto='A' | Ottenuto: differenza a byte[%d] (ft=%d std=%d)\n", 
				first_diff, (unsigned char)buf1[first_diff], (unsigned char)buf2[first_diff]);

		printf("\n");
		return 0;
	}

	if (strcmp(function, "memcpy") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		char dst1[10], dst2[10];
		char src[6] = "abcde";
		int i, pass;
		size_t n;
		int first_diff = -1;

		/* Test 1: copia completa dei 5 byte */
		ft_memset(dst1, '0', 10);
		memset(dst2, '0', 10);
		n = 5;
		ft_memcpy(dst1, src, n);
		memcpy(dst2, src, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: copia completa | Input: src=\"%s\", dst inizializzato a '0', n=%zu | ", 
			pass ? "PASS" : "FAIL", src, n);
		if (pass)
		{
			pass = 1;
			for (i = 0; i < 5; i++)
				if (dst1[i] != src[i]) pass = 0;
			for (i = 5; i < 10; i++)
				if (dst1[i] != '0') pass = 0;
			printf("Atteso: dst=\"abcde00000\" | Ottenuto: %s\n", 
				pass ? "corretto" : "ERRORE nel contenuto");
		}
		else
			printf("Atteso: primi 5='abcde' resto='0' | Ottenuto: differenza a byte[%d] (ft='%c' std='%c')\n", 
				first_diff, dst1[first_diff], dst2[first_diff]);

		/* Test 2: copia parziale dei 3 byte */
		ft_memset(dst1, '0', 10);
		memset(dst2, '0', 10);
		n = 3;
		ft_memcpy(dst1, src, n);
		memcpy(dst2, src, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: copia parziale | Input: src=\"%s\", dst inizializzato a '0', n=%zu | ", 
			pass ? "PASS" : "FAIL", src, n);
		if (pass)
		{
			pass = 1;
			for (i = 0; i < 3; i++)
				if (dst1[i] != src[i]) pass = 0;
			for (i = 3; i < 10; i++)
				if (dst1[i] != '0') pass = 0;
			printf("Atteso: dst=\"abc0000000\" | Ottenuto: %s\n", 
				pass ? "corretto" : "ERRORE nel contenuto");
		}
		else
			printf("Atteso: primi 3='abc' resto='0' | Ottenuto: differenza a byte[%d] (ft='%c' std='%c')\n", 
				first_diff, dst1[first_diff], dst2[first_diff]);

		/* Test 3: copia zero byte */
		ft_memset(dst1, 'x', 10);
		memset(dst2, 'x', 10);
		n = 0;
		ft_memcpy(dst1, src, n);
		memcpy(dst2, src, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: copia 0 byte | Input: src=\"%s\", dst='xxxxxxxxxx', n=%zu | ", 
			pass ? "PASS" : "FAIL", src, n);
		if (pass)
		{
			pass = 1;
			for (i = 0; i < 10; i++)
				if (dst1[i] != 'x') pass = 0;
			printf("Atteso: dst invariato ('xxxxxxxxxx') | Ottenuto: %s\n", 
				pass ? "invariato" : "ERRORE");
		}
		else
			printf("Atteso: invariato | Ottenuto: differenza a byte[%d] (ft='%c' std='%c')\n", 
				first_diff, dst1[first_diff], dst2[first_diff]);

		/* Test 4: copia con src vuoto (lunghezza 0) */
		char empty[1] = "";
		ft_memset(dst1, 'y', 10);
		memset(dst2, 'y', 10);
		n = 0;
		ft_memcpy(dst1, empty, n);
		memcpy(dst2, empty, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: src vuoto, n=0 | Input: src=\"\", dst='yyyyyyyyyy', n=%zu | ", 
			pass ? "PASS" : "FAIL", n);
		if (pass)
		{
			pass = 1;
			for (i = 0; i < 10; i++)
				if (dst1[i] != 'y') pass = 0;
			printf("Atteso: dst invariato | Ottenuto: %s\n", 
				pass ? "invariato" : "ERRORE");
		}
		else
			printf("Atteso: invariato | Ottenuto: differenza a byte[%d] (ft='%c' std='%c')\n", 
				first_diff, dst1[first_diff], dst2[first_diff]);

		/* Test 5: copia 1 byte */
		ft_memset(dst1, 'Z', 10);
		memset(dst2, 'Z', 10);
		n = 1;
		ft_memcpy(dst1, src, n);
		memcpy(dst2, src, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: copia 1 byte | Input: src=\"%s\", dst='ZZZZZZZZZZ', n=%zu | ", 
			pass ? "PASS" : "FAIL", src, n);
		if (pass)
		{
			pass = (dst1[0] == 'a' && dst2[0] == 'a');
			for (i = 1; i < 10; i++)
				if (dst1[i] != 'Z') pass = 0;
			printf("Atteso: dst=\"aZZZZZZZZZ\" | Ottenuto: %s\n", 
				pass ? "corretto" : "ERRORE");
		}
		else
			printf("Atteso: primo='a' resto='Z' | Ottenuto: differenza a byte[%d] (ft='%c' std='%c')\n", 
				first_diff, dst1[first_diff], dst2[first_diff]);

		printf("\n");
		return 0;
	}

	if (strcmp(function, "memmove") == 0)
	{
		printf("-------- TEST %s --------\n", function);
	
		char buf1[20], buf2[20];
		int i, pass;
		size_t n;
		int first_diff = -1;
	
		/* Test 1: copia normale senza overlap (stesso buffer) */
		ft_memset(buf1, 0, 20);
		memset(buf2, 0, 20);
		strcpy(buf1, "123456789");
		strcpy(buf2, "123456789");
		n = 9;
		ft_memmove(buf1, buf1, n);
		memmove(buf2, buf2, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 20; i++)
		{
			if (buf1[i] != buf2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: copia senza overlap | Input: buf=\"123456789\", dst=buf, src=buf, n=%zu | ", 
			pass ? "PASS" : "FAIL", n);
		if (pass)
			printf("Atteso: buf=\"123456789\" | Ottenuto: corretto\n");
		else
			printf("Atteso: invariato | Ottenuto: differenza a byte[%d] (ft=%d std=%d)\n", 
				first_diff, (unsigned char)buf1[first_diff], (unsigned char)buf2[first_diff]);
	
		/* Test 2: overlap in avanti (dst > src) */
		ft_memset(buf1, 0, 20);
		memset(buf2, 0, 20);
		strcpy(buf1, "123456789");
		strcpy(buf2, "123456789");
		n = 5;
		ft_memmove(buf1 + 2, buf1, n);
		memmove(buf2 + 2, buf2, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 20; i++)
		{
			if (buf1[i] != buf2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: overlap in avanti | Input: buf=\"123456789\", dst=buf+2, src=buf, n=%zu | ", 
			pass ? "PASS" : "FAIL", n);
		if (pass)
		{
			pass = (buf1[0] == '1' && buf1[1] == '2' && buf1[2] == '1' && 
			        buf1[3] == '2' && buf1[4] == '3' && buf1[5] == '4' && buf1[6] == '5');
			printf("Atteso: buf=\"1212345...\" | Ottenuto: %s\n", 
				pass ? "corretto" : "ERRORE nel contenuto");
		}
		else
			printf("Atteso: overlap gestito correttamente | Ottenuto: differenza a byte[%d] (ft=%d std=%d)\n", 
				first_diff, (unsigned char)buf1[first_diff], (unsigned char)buf2[first_diff]);
	
		/* Test 3: overlap all'indietro (dst < src) */
		ft_memset(buf1, 0, 20);
		memset(buf2, 0, 20);
		strcpy(buf1, "123456789");
		strcpy(buf2, "123456789");
		n = 5;
		ft_memmove(buf1, buf1 + 2, n);
		memmove(buf2, buf2 + 2, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 20; i++)
		{
			if (buf1[i] != buf2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: overlap all'indietro | Input: buf=\"123456789\", dst=buf, src=buf+2, n=%zu | ", 
			pass ? "PASS" : "FAIL", n);
		if (pass)
		{
			pass = (buf1[0] == '3' && buf1[1] == '4' && buf1[2] == '5' && 
			        buf1[3] == '6' && buf1[4] == '7');
			printf("Atteso: buf=\"34567...\" | Ottenuto: %s\n", 
				pass ? "corretto" : "ERRORE nel contenuto");
		}
		else
			printf("Atteso: overlap gestito correttamente | Ottenuto: differenza a byte[%d] (ft=%d std=%d)\n", 
				first_diff, (unsigned char)buf1[first_diff], (unsigned char)buf2[first_diff]);
	
		/* Test 4: copia zero byte */
		ft_memset(buf1, 0, 20);
		memset(buf2, 0, 20);
		strcpy(buf1, "123456789");
		strcpy(buf2, "123456789");
		n = 0;
		ft_memmove(buf1, buf1 + 2, n);
		memmove(buf2, buf2 + 2, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 20; i++)
		{
			if (buf1[i] != buf2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: copia 0 byte | Input: buf=\"123456789\", n=%zu | ", 
			pass ? "PASS" : "FAIL", n);
		if (pass)
		{
			pass = (strcmp(buf1, "123456789") == 0);
			printf("Atteso: buf invariato | Ottenuto: %s\n", 
				pass ? "invariato" : "ERRORE");
		}
		else
			printf("Atteso: invariato | Ottenuto: differenza a byte[%d] (ft=%d std=%d)\n", 
				first_diff, (unsigned char)buf1[first_diff], (unsigned char)buf2[first_diff]);
	
		/* Test 5: copia parziale con overlap */
		ft_memset(buf1, 0, 20);
		memset(buf2, 0, 20);
		strcpy(buf1, "abcdefghij");
		strcpy(buf2, "abcdefghij");
		n = 5;
		ft_memmove(buf1 + 5, buf1, n);
		memmove(buf2 + 5, buf2, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 20; i++)
		{
			if (buf1[i] != buf2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: overlap parziale | Input: buf=\"abcdefghij\", dst=buf+5, src=buf, n=%zu | ", 
			pass ? "PASS" : "FAIL", n);
		if (pass)
		{
			pass = (buf1[0] == 'a' && buf1[1] == 'b' && buf1[2] == 'c' && 
			        buf1[3] == 'd' && buf1[4] == 'e' && buf1[5] == 'a' && 
			        buf1[6] == 'b' && buf1[7] == 'c' && buf1[8] == 'd' && buf1[9] == 'e');
			printf("Atteso: buf=\"abcdeabcde...\" | Ottenuto: %s\n", 
				pass ? "corretto" : "ERRORE nel contenuto");
		}
		else
			printf("Atteso: overlap gestito correttamente | Ottenuto: differenza a byte[%d] (ft=%d std=%d)\n", 
				first_diff, (unsigned char)buf1[first_diff], (unsigned char)buf2[first_diff]);
	
		/* Test 6: copia da buffer separato (no overlap) */
		char src_buf[10] = "ABCDEFGHI";
		ft_memset(buf1, 'X', 20);
		memset(buf2, 'X', 20);
		n = 9;
		ft_memmove(buf1, src_buf, n);
		memmove(buf2, src_buf, n);
		pass = 1;
		first_diff = -1;
		for (i = 0; i < 20; i++)
		{
			if (buf1[i] != buf2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: copia da buffer separato | Input: src=\"ABCDEFGHI\", dst inizializzato a 'X', n=%zu | ", 
			pass ? "PASS" : "FAIL", n);
		if (pass)
		{
			pass = 1;
			for (i = 0; i < 9; i++)
				if (buf1[i] != src_buf[i]) pass = 0;
			for (i = 9; i < 20; i++)
				if (buf1[i] != 'X') pass = 0;
			printf("Atteso: dst=\"ABCDEFGHIXXXXXXXXXXX\" | Ottenuto: %s\n", 
				pass ? "corretto" : "ERRORE");
		}
		else
			printf("Atteso: primi 9='ABCDEFGHI' resto='X' | Ottenuto: differenza a byte[%d] (ft=%d std=%d)\n", 
				first_diff, (unsigned char)buf1[first_diff], (unsigned char)buf2[first_diff]);
	
		printf("\n");
		return 0;
	}
	
	if (strcmp(function, "strlcpy") == 0)
	{
		printf("-------- TEST %s --------\n", function);
	
		char src[20] = "abcdefghi";
		char dst1[10], dst2[10];
		size_t ret_ft, ret_std, size;
		int pass, i;
		int first_diff = -1;
	
		/* Test 1: buffer più piccolo di src (troncamento) */
		ft_memset(dst1, 'X', sizeof(dst1));
		memset(dst2, 'X', sizeof(dst2));
		size = 5;
		ret_ft  = ft_strlcpy(dst1, src, size);
		ret_std = strlcpy(dst2, src, size);
		pass = (ret_ft == ret_std);
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: buffer piccolo (troncamento) | Input: src=\"%s\", dst inizializzato a 'X', size=%zu | ", 
			pass ? "PASS" : "FAIL", src, size);
		if (pass && ret_ft == strlen(src))
		{
			pass = (dst1[0] == 'a' && dst1[1] == 'b' && dst1[2] == 'c' && 
			        dst1[3] == 'd' && dst1[4] == '\0');
			printf("Atteso: ret=%zu, dst=\"abcd\\0\" | Ottenuto: ret=%zu, dst=%s\n", 
				strlen(src), ret_ft, pass ? "corretto" : "ERRORE");
		}
		else
			printf("Atteso: ret=%zu (std=%zu) | Ottenuto: ret=%zu, differenza a byte[%d]\n", 
				strlen(src), ret_std, ret_ft, first_diff);
	
		/* Test 2: buffer grande abbastanza */
		ft_memset(dst1, 'X', sizeof(dst1));
		memset(dst2, 'X', sizeof(dst2));
		size = sizeof(dst1);
		ret_ft  = ft_strlcpy(dst1, src, size);
		ret_std = strlcpy(dst2, src, size);
		pass = (ret_ft == ret_std);
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: buffer grande | Input: src=\"%s\", dst inizializzato a 'X', size=%zu | ", 
			pass ? "PASS" : "FAIL", src, size);
		if (pass && ret_ft == strlen(src))
		{
			pass = (strcmp(dst1, src) == 0);
			printf("Atteso: ret=%zu, dst=\"%s\" | Ottenuto: ret=%zu, dst=\"%s\"\n", 
				strlen(src), src, ret_ft, pass ? dst1 : "ERRORE");
		}
		else
			printf("Atteso: ret=%zu (std=%zu), dst=\"%s\" | Ottenuto: ret=%zu, differenza a byte[%d]\n", 
				strlen(src), ret_std, src, ret_ft, first_diff);
	
		/* Test 3: size = 0 */
		ft_memset(dst1, 'X', sizeof(dst1));
		memset(dst2, 'X', sizeof(dst2));
		size = 0;
		ret_ft  = ft_strlcpy(dst1, src, size);
		ret_std = strlcpy(dst2, src, size);
		pass = (ret_ft == ret_std);
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: size = 0 | Input: src=\"%s\", dst inizializzato a 'X', size=%zu | ", 
			pass ? "PASS" : "FAIL", src, size);
		if (pass && ret_ft == strlen(src))
		{
			pass = 1;
			for (i = 0; i < 10; i++)
				if (dst1[i] != 'X') pass = 0;
			printf("Atteso: ret=%zu, dst invariato | Ottenuto: ret=%zu, dst=%s\n", 
				strlen(src), ret_ft, pass ? "invariato" : "ERRORE");
		}
		else
			printf("Atteso: ret=%zu (std=%zu), dst invariato | Ottenuto: ret=%zu, differenza a byte[%d]\n", 
				strlen(src), ret_std, ret_ft, first_diff);
	
		/* Test 4: stringa vuota */
		ft_memset(dst1, 'X', sizeof(dst1));
		memset(dst2, 'X', sizeof(dst2));
		src[0] = '\0';
		size = sizeof(dst1);
		ret_ft  = ft_strlcpy(dst1, src, size);
		ret_std = strlcpy(dst2, src, size);
		pass = (ret_ft == ret_std);
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: src vuota | Input: src=\"\", dst inizializzato a 'X', size=%zu | ", 
			pass ? "PASS" : "FAIL", size);
		if (pass && ret_ft == 0)
		{
			pass = (dst1[0] == '\0');
			printf("Atteso: ret=0, dst=\"\\0\" | Ottenuto: ret=%zu, dst=%s\n", 
				ret_ft, pass ? "\"\\0\"" : "ERRORE");
		}
		else
			printf("Atteso: ret=0 (std=%zu), dst=\"\\0\" | Ottenuto: ret=%zu, differenza a byte[%d]\n", 
				ret_std, ret_ft, first_diff);
	
		/* Test 5: size = 1 (solo null terminator) */
		ft_memset(dst1, 'X', sizeof(dst1));
		memset(dst2, 'X', sizeof(dst2));
		strcpy(src, "abcdefghi");
		size = 1;
		ret_ft  = ft_strlcpy(dst1, src, size);
		ret_std = strlcpy(dst2, src, size);
		pass = (ret_ft == ret_std);
		first_diff = -1;
		for (i = 0; i < 10; i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: size = 1 | Input: src=\"%s\", dst inizializzato a 'X', size=%zu | ", 
			pass ? "PASS" : "FAIL", src, size);
		if (pass && ret_ft == strlen(src))
		{
			pass = (dst1[0] == '\0');
			printf("Atteso: ret=%zu, dst=\"\\0\" | Ottenuto: ret=%zu, dst=%s\n", 
				strlen(src), ret_ft, pass ? "\"\\0\"" : "ERRORE");
		}
		else
			printf("Atteso: ret=%zu (std=%zu), dst=\"\\0\" | Ottenuto: ret=%zu, differenza a byte[%d]\n", 
				strlen(src), ret_std, ret_ft, first_diff);
	
		printf("\n");
		return 0;
	}
	
	if (strcmp(function, "strlcat") == 0)
	{
		printf("-------- TEST %s --------\n", function);
	
		char dst1[15], dst2[15];
		char src[10] = " dfgh";
		size_t ret_ft, ret_std, size;
		int pass, i;
		int first_diff = -1;
		size_t dst_len, src_len, expected_ret;
	
		/* Test 1: buffer abbastanza grande */
		ft_memset(dst1, 0, sizeof(dst1));
		memset(dst2, 0, sizeof(dst2));
		strcpy(dst1, "abc");
		strcpy(dst2, "abc");
		dst_len = strlen(dst1);
		src_len = strlen(src);
		size = sizeof(dst1);
		expected_ret = dst_len + src_len;
		ret_ft  = ft_strlcat(dst1, src, size);
		ret_std = strlcat(dst2, src, size);
		pass = (ret_ft == ret_std);
		first_diff = -1;
		for (i = 0; i < sizeof(dst1); i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: buffer grande | Input: dst=\"abc\", src=\"%s\", size=%zu | ", 
			pass ? "PASS" : "FAIL", src, size);
		if (pass && ret_ft == expected_ret)
		{
			pass = (strcmp(dst1, "abc dfgh") == 0);
			printf("Atteso: ret=%zu, dst=\"abc%s\" | Ottenuto: ret=%zu, dst=\"%s\"\n", 
				expected_ret, src, ret_ft, pass ? dst1 : "ERRORE");
		}
		else
			printf("Atteso: ret=%zu (std=%zu), dst=\"abc%s\" | Ottenuto: ret=%zu, differenza a byte[%d]\n", 
				expected_ret, ret_std, src, ret_ft, first_diff);
	
		/* Test 2: buffer piccolo (troncamento) */
		ft_memset(dst1, 0, sizeof(dst1));
		memset(dst2, 0, sizeof(dst2));
		strcpy(dst1, "abc");
		strcpy(dst2, "abc");
		dst_len = strlen(dst1);
		src_len = strlen(src);
		size = 5;
		expected_ret = dst_len + src_len;
		ret_ft  = ft_strlcat(dst1, src, size);
		ret_std = strlcat(dst2, src, size);
		pass = (ret_ft == ret_std);
		first_diff = -1;
		for (i = 0; i < 15; i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: buffer piccolo (troncamento) | Input: dst=\"abc\", src=\"%s\", size=%zu | ", 
			pass ? "PASS" : "FAIL", src, size);
		if (pass && ret_ft == expected_ret)
		{
			pass = (dst1[0] == 'a' && dst1[1] == 'b' && dst1[2] == 'c' && 
			        dst1[3] == ' ' && dst1[4] == '\0');
			printf("Atteso: ret=%zu, dst=\"abc \\0\" (troncato) | Ottenuto: ret=%zu, dst=%s\n", 
				expected_ret, ret_ft, pass ? "corretto" : "ERRORE");
		}
		else
			printf("Atteso: ret=%zu (std=%zu), dst troncato | Ottenuto: ret=%zu, differenza a byte[%d]\n", 
				expected_ret, ret_std, ret_ft, first_diff);
	
		/* Test 3: size = 0 */
		ft_memset(dst1, 0, sizeof(dst1));
		memset(dst2, 0, sizeof(dst2));
		strcpy(dst1, "abc");
		strcpy(dst2, "abc");
		dst_len = strlen(dst1);
		src_len = strlen(src);
		size = 0;
		expected_ret = dst_len + src_len;
		ret_ft  = ft_strlcat(dst1, src, size);
		ret_std = strlcat(dst2, src, size);
		pass = (ret_ft == ret_std);
		first_diff = -1;
		for (i = 0; i < 15; i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: size = 0 | Input: dst=\"abc\", src=\"%s\", size=%zu | ", 
			pass ? "PASS" : "FAIL", src, size);
		if (pass && ret_ft == expected_ret)
		{
			pass = (strcmp(dst1, "abc") == 0);
			printf("Atteso: ret=%zu, dst invariato=\"abc\" | Ottenuto: ret=%zu, dst=\"%s\"\n", 
				expected_ret, ret_ft, pass ? dst1 : "ERRORE");
		}
		else
			printf("Atteso: ret=%zu (std=%zu), dst invariato | Ottenuto: ret=%zu, differenza a byte[%d]\n", 
				expected_ret, ret_std, ret_ft, first_diff);
	
		/* Test 4: src vuota */
		ft_memset(dst1, 0, sizeof(dst1));
		memset(dst2, 0, sizeof(dst2));
		strcpy(dst1, "abc");
		strcpy(dst2, "abc");
		src[0] = '\0';
		dst_len = strlen(dst1);
		src_len = 0;
		size = sizeof(dst1);
		expected_ret = dst_len + src_len;
		ret_ft  = ft_strlcat(dst1, src, size);
		ret_std = strlcat(dst2, src, size);
		pass = (ret_ft == ret_std);
		first_diff = -1;
		for (i = 0; i < sizeof(dst1); i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: src vuota | Input: dst=\"abc\", src=\"\", size=%zu | ", 
			pass ? "PASS" : "FAIL", size);
		if (pass && ret_ft == expected_ret)
		{
			pass = (strcmp(dst1, "abc") == 0);
			printf("Atteso: ret=%zu, dst=\"abc\" | Ottenuto: ret=%zu, dst=\"%s\"\n", 
				expected_ret, ret_ft, pass ? dst1 : "ERRORE");
		}
		else
			printf("Atteso: ret=%zu (std=%zu), dst=\"abc\" | Ottenuto: ret=%zu, differenza a byte[%d]\n", 
				expected_ret, ret_std, ret_ft, first_diff);
	
		/* Test 5: dst vuota */
		ft_memset(dst1, 0, sizeof(dst1));
		memset(dst2, 0, sizeof(dst2));
		dst1[0] = '\0';
		dst2[0] = '\0';
		strcpy(src, "hello");
		dst_len = 0;
		src_len = strlen(src);
		size = sizeof(dst1);
		expected_ret = dst_len + src_len;
		ret_ft  = ft_strlcat(dst1, src, size);
		ret_std = strlcat(dst2, src, size);
		pass = (ret_ft == ret_std);
		first_diff = -1;
		for (i = 0; i < sizeof(dst1); i++)
		{
			if (dst1[i] != dst2[i])
			{
				pass = 0;
				if (first_diff == -1) first_diff = i;
			}
		}
		printf("%s -- Test: dst vuota | Input: dst=\"\", src=\"%s\", size=%zu | ", 
			pass ? "PASS" : "FAIL", src, size);
		if (pass && ret_ft == expected_ret)
		{
			pass = (strcmp(dst1, src) == 0);
			printf("Atteso: ret=%zu, dst=\"%s\" | Ottenuto: ret=%zu, dst=\"%s\"\n", 
				expected_ret, src, ret_ft, pass ? dst1 : "ERRORE");
		}
		else
			printf("Atteso: ret=%zu (std=%zu), dst=\"%s\" | Ottenuto: ret=%zu, differenza a byte[%d]\n", 
				expected_ret, ret_std, src, ret_ft, first_diff);
	
		printf("\n");
		return 0;
	}	

	if (strcmp(function, "toupper") == 0)
	{
		printf("-------- TEST %s --------\n", function);
	
		char c;
		char ft_res, std_res;
	
		/* 1️⃣ lettera minuscola */
		c = 'a';
		ft_res  = ft_toupper(c);
		std_res = toupper(c);
		printf("%s -- '%c' -> '%c'\n", (ft_res == std_res) ? "PASS" : "FAIL", c, ft_res);
	
		/* 2️⃣ lettera maiuscola */
		c = 'Z';
		ft_res  = ft_toupper(c);
		std_res = toupper(c);
		printf("%s -- '%c' -> '%c'\n", (ft_res == std_res) ? "PASS" : "FAIL", c, ft_res);
	
		/* 3️⃣ numero */
		c = '9';
		ft_res  = ft_toupper(c);
		std_res = toupper(c);
		printf("%s -- '%c' -> '%c'\n", (ft_res == std_res) ? "PASS" : "FAIL", c, ft_res);
	
		/* 4️⃣ simbolo */
		c = '@';
		ft_res  = ft_toupper(c);
		std_res = toupper(c);
		printf("%s -- '%c' -> '%c'\n", (ft_res == std_res) ? "PASS" : "FAIL", c, ft_res);
	
		/* 5️⃣ spazio */
		c = ' ';
		ft_res  = ft_toupper(c);
		std_res = toupper(c);
		printf("%s -- 'space' -> '%c'\n", (ft_res == std_res) ? "PASS" : "FAIL", ft_res);
	
		printf("\n");
		return 0;
	}	

	if (strcmp(function, "tolower") == 0)
	{
		printf("-------- TEST %s --------\n", function);
	
		char c;
		char ft_res, std_res;
	
		/* 1️⃣ lettera maiuscola */
		c = 'A';
		ft_res  = ft_tolower(c);
		std_res = tolower(c);
		printf("%s -- '%c' -> '%c'\n", (ft_res == std_res) ? "PASS" : "FAIL", c, ft_res);
	
		/* 2️⃣ lettera minuscola */
		c = 'z';
		ft_res  = ft_tolower(c);
		std_res = tolower(c);
		printf("%s -- '%c' -> '%c'\n", (ft_res == std_res) ? "PASS" : "FAIL", c, ft_res);
	
		/* 3️⃣ numero */
		c = '9';
		ft_res  = ft_tolower(c);
		std_res = tolower(c);
		printf("%s -- '%c' -> '%c'\n", (ft_res == std_res) ? "PASS" : "FAIL", c, ft_res);
	
		/* 4️⃣ simbolo */
		c = '@';
		ft_res  = ft_tolower(c);
		std_res = tolower(c);
		printf("%s -- '%c' -> '%c'\n", (ft_res == std_res) ? "PASS" : "FAIL", c, ft_res);
	
		/* 5️⃣ spazio */
		c = ' ';
		ft_res  = ft_tolower(c);
		std_res = tolower(c);
		printf("%s -- 'space' -> '%c'\n", (ft_res == std_res) ? "PASS" : "FAIL", ft_res);
	
		printf("\n");
		return 0;
	}	
	
	if (strcmp(function, "strchr") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		char str[] = "AaBbCcAaBbCc";
		char c;
		char *ft;
		char *lib;

		// 1️⃣ carattere presente (minuscolo)
		c = 'a';
		ft = ft_strchr(str, c);
		lib = strchr(str, c);
		printf("%s -- cerco '%c' in \"%s\"\n",
			(ft == lib) ? "PASS" : "FAIL", c, str);

		// 2️⃣ carattere presente (maiuscolo)
		c = 'B';
		ft = ft_strchr(str, c);
		lib = strchr(str, c);
		printf("%s -- cerco '%c' in \"%s\"\n",
			(ft == lib) ? "PASS" : "FAIL", c, str);

		// 3️⃣ carattere NON presente
		c = 'Z';
		ft = ft_strchr(str, c);
		lib = strchr(str, c);
		printf("%s -- cerco '%c' (non presente)\n", (ft == lib) ? "PASS" : "FAIL", c);

		// 4️⃣ cerco '\0'
		c = '\0';
		ft = ft_strchr(str, c);
		lib = strchr(str, c);
		printf("%s -- cerco '\\0'\n",
			(ft == lib) ? "PASS" : "FAIL");

		// 5️⃣ stringa vuota
		char empty[] = "";
		c = 'a';
		ft = ft_strchr(empty, c);
		lib = strchr(empty, c);
		printf("%s -- stringa vuota\n",
			(ft == lib) ? "PASS" : "FAIL");

		printf("\n");
		return (0);
	}
	
	if (strcmp(function, "strrchr") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		char str[] = "AaBbCcAaBbCc";
		char empty[] = "";
		char c;
		char *ft;
		char *lib;

		/* 1️⃣ carattere presente più volte */
		c = 'a';
		ft = ft_strrchr(str, c);
		lib = strrchr(str, c);
		printf("%s -- cerco '%c' (più occorrenze)\n",
			(ft == lib) ? "PASS" : "FAIL", c);

		/* 2️⃣ ultima occorrenza */
		c = 'C';
		ft = ft_strrchr(str, c);
		lib = strrchr(str, c);
		printf("%s -- cerco '%c' (ultima occorrenza)\n",
			(ft == lib) ? "PASS" : "FAIL", c);

		/* 3️⃣ primo carattere */
		c = 'A';
		ft = ft_strrchr(str, c);
		lib = strrchr(str, c);
		printf("%s -- cerco '%c' (prima occorrenza)\n",
			(ft == lib) ? "PASS" : "FAIL", c);

		/* 4️⃣ carattere NON presente */
		c = 'z';
		ft = ft_strrchr(str, c);
		lib = strrchr(str, c);
		printf("%s -- cerco '%c' (non presente)\n",
			(ft == lib) ? "PASS" : "FAIL", c);

		/* 5️⃣ carattere '\0' */
		c = '\0';
		ft = ft_strrchr(str, c);
		lib = strrchr(str, c);
		printf("%s -- cerco '\\0'\n",
			(ft == lib) ? "PASS" : "FAIL");

		/* 6️⃣ stringa vuota */
		c = 'a';
		ft = ft_strrchr(empty, c);
		lib = strrchr(empty, c);
		printf("%s -- stringa vuota\n",
			(ft == lib) ? "PASS" : "FAIL");

		/* 7️⃣ '\0' su stringa vuota */
		c = '\0';
		ft = ft_strrchr(empty, c);
		lib = strrchr(empty, c);
		printf("%s -- '\\0' su stringa vuota\n",
			(ft == lib) ? "PASS" : "FAIL");

		printf("\n");
		return (0);
	}

	if (strcmp(function, "strncmp") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		const char *s1;
		const char *s2;
		size_t n;
		int ft;
		int lib;

		/* 1️⃣ n == 0 (deve tornare 0) */
		s1 = "abc";
		s2 = "xyz";
		n = 0;
		ft = ft_strncmp(s1, s2, n);
		lib = strncmp(s1, s2, n);
		printf("%s -- n = 0\n", (ft == lib) ? "PASS" : "FAIL");

		/* 2️⃣ stringhe identiche */
		s1 = "abcdef";
		s2 = "abcdef";
		n = 10;
		ft = ft_strncmp(s1, s2, n);
		lib = strncmp(s1, s2, n);
		printf("%s -- stringhe identiche\n",
			(ft == lib) ? "PASS" : "FAIL");

		/* 3️⃣ differenza prima di n */
		s1 = "abcXef";
		s2 = "abcYef";
		n = 6;
		ft = ft_strncmp(s1, s2, n);
		lib = strncmp(s1, s2, n);
		printf("%s -- differenza prima di n\n",
			((ft < 0 && lib < 0) || (ft > 0 && lib > 0)) ? "PASS" : "FAIL");

		/* 4️⃣ differenza dopo n (uguali) */
		s1 = "abcdef";
		s2 = "abcXYZ";
		n = 3;
		ft = ft_strncmp(s1, s2, n);
		lib = strncmp(s1, s2, n);
		printf("%s -- differenza dopo n\n",
			(ft == lib) ? "PASS" : "FAIL");

		/* 5️⃣ s1 più corta di s2 */
		s1 = "abc";
		s2 = "abcd";
		n = 10;
		ft = ft_strncmp(s1, s2, n);
		lib = strncmp(s1, s2, n);
		printf("%s -- s1 più corta\n",
			((ft < 0 && lib < 0) || (ft > 0 && lib > 0)) ? "PASS" : "FAIL");

		/* 6️⃣ s2 più corta di s1 */
		s1 = "abcd";
		s2 = "abc";
		n = 10;
		ft = ft_strncmp(s1, s2, n);
		lib = strncmp(s1, s2, n);
		printf("%s -- s2 più corta\n",
			((ft < 0 && lib < 0) || (ft > 0 && lib > 0)) ? "PASS" : "FAIL");

		/* 7️⃣ una stringa vuota */
		s1 = "";
		s2 = "abc";
		n = 5;
		ft = ft_strncmp(s1, s2, n);
		lib = strncmp(s1, s2, n);
		printf("%s -- s1 vuota\n",
			((ft < 0 && lib < 0) || (ft > 0 && lib > 0)) ? "PASS" : "FAIL");

		/* 8️⃣ entrambe vuote */
		s1 = "";
		s2 = "";
		n = 5;
		ft = ft_strncmp(s1, s2, n);
		lib = strncmp(s1, s2, n);
		printf("%s -- entrambe vuote\n",
			(ft == lib) ? "PASS" : "FAIL");

		/* 9️⃣ confronto con '\0' dentro n */
		s1 = "abc";
		s2 = "abc\0xyz";
		n = 6;
		ft = ft_strncmp(s1, s2, n);
		lib = strncmp(s1, s2, n);
		printf("%s -- confronto con '\\0'\n",
			(ft == lib) ? "PASS" : "FAIL");

		printf("\n");
		return (0);
	}

	if (strcmp(function, "memchr") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		unsigned char buf[] = { 'A', 'B', 'C', 0, 'D', 'E', 'F' };
		unsigned char high[] = { 200, 201, 202, 203 };

		int c;
		size_t n;
		void *ft;
		void *lib;

		/* 1️⃣ trovato all'inizio */
		c = 'A'; n = 7;
		ft = ft_memchr(buf, c, n);
		lib = memchr(buf, c, n);
		printf("%s -- cerco '%c', n=%zu | libc=%ld ft=%ld\n",
			(ft == lib) ? "PASS" : "FAIL",
			c, n, offset(buf, lib), offset(buf, ft));

		/* 2️⃣ trovato in mezzo */
		c = 'C'; n = 7;
		ft = ft_memchr(buf, c, n);
		lib = memchr(buf, c, n);
		printf("%s -- cerco '%c', n=%zu | libc=%ld ft=%ld\n",
			(ft == lib) ? "PASS" : "FAIL",
			c, n, offset(buf, lib), offset(buf, ft));

		/* 3️⃣ cerco '\\0' */
		c = '\0'; n = 7;
		ft = ft_memchr(buf, c, n);
		lib = memchr(buf, c, n);
		printf("%s -- cerco '\\0', n=%zu | libc=%ld ft=%ld\n",
			(ft == lib) ? "PASS" : "FAIL",
			n, offset(buf, lib), offset(buf, ft));

		/* 4️⃣ presente ma fuori n */
		c = 'E'; n = 4;
		ft = ft_memchr(buf, c, n);
		lib = memchr(buf, c, n);
		printf("%s -- cerco '%c', n=%zu (fuori) | libc=%ld ft=%ld\n",
			(ft == lib) ? "PASS" : "FAIL",
			c, n, offset(buf, lib), offset(buf, ft));

		/* 5️⃣ non presente */
		c = 'Z'; n = 7;
		ft = ft_memchr(buf, c, n);
		lib = memchr(buf, c, n);
		printf("%s -- cerco '%c', n=%zu (assente) | libc=%ld ft=%ld\n",
			(ft == lib) ? "PASS" : "FAIL",
			c, n, offset(buf, lib), offset(buf, ft));

		/* 6️⃣ n == 0 */
		c = 'A'; n = 0;
		ft = ft_memchr(buf, c, n);
		lib = memchr(buf, c, n);
		printf("%s -- cerco '%c', n=0 | libc=%ld ft=%ld\n",
			(ft == lib) ? "PASS" : "FAIL",
			c, offset(buf, lib), offset(buf, ft));

		/* 7️⃣ byte > 127 */
		c = 202; n = 4;
		ft = ft_memchr(high, c, n);
		lib = memchr(high, c, n);
		printf("%s -- cerco %d (>127), n=%zu | libc=%ld ft=%ld\n",
			(ft == lib) ? "PASS" : "FAIL",
			c, n, offset(high, lib), offset(high, ft));

		printf("\n");
		return (0);
	}

	if (strcmp(function, "memcmp") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		unsigned char a1[] = { 'A', 'B', 'C', 'D' };
		unsigned char a2[] = { 'A', 'B', 'C', 'D' };

		unsigned char b1[] = { 'A', 'B', 'C', 'D' };
		unsigned char b2[] = { 'A', 'B', 'X', 'D' };

		unsigned char c1[] = { 'A', 'B', 0, 'D' };
		unsigned char c2[] = { 'A', 'B', 0, 'E' };

		unsigned char high1[] = { 200, 201, 202 };
		unsigned char high2[] = { 200, 201, 100 };

		size_t n;
		int ft;
		int lib;

		/* 1️⃣ blocchi identici */
		n = 4;
		ft = ft_memcmp(a1, a2, n);
		lib = memcmp(a1, a2, n);
		printf("%s -- identici, n=%zu | libc=%s ft=%s\n",
			(ft == lib) ? "PASS" : "FAIL",
			n, cmp_result(lib), cmp_result(ft));

		/* 2️⃣ differenza al primo byte */
		n = 4;
		ft = ft_memcmp(b1, b2, n);
		lib = memcmp(b1, b2, n);
		printf("%s -- differenza al byte 2 | libc=%s ft=%s\n",
			((ft < 0 && lib < 0) || (ft > 0 && lib > 0)) ? "PASS" : "FAIL",
			cmp_result(lib), cmp_result(ft));

		/* 3️⃣ differenza dopo '\0' */
		n = 4;
		ft = ft_memcmp(c1, c2, n);
		lib = memcmp(c1, c2, n);
		printf("%s -- confronto oltre '\\0' | libc=%s ft=%s\n",
			((ft < 0 && lib < 0) || (ft > 0 && lib > 0)) ? "PASS" : "FAIL",
			cmp_result(lib), cmp_result(ft));

		/* 4️⃣ differenza fuori n */
		n = 2;
		ft = ft_memcmp(b1, b2, n);
		lib = memcmp(b1, b2, n);
		printf("%s -- differenza fuori n | libc=%s ft=%s\n",
			(ft == lib) ? "PASS" : "FAIL",
			cmp_result(lib), cmp_result(ft));

		/* 5️⃣ n == 0 */
		n = 0;
		ft = ft_memcmp(b1, b2, n);
		lib = memcmp(b1, b2, n);
		printf("%s -- n == 0 | libc=%s ft=%s\n",
			(ft == lib) ? "PASS" : "FAIL",
			cmp_result(lib), cmp_result(ft));

		/* 6️⃣ byte > 127 (unsigned char) */
		n = 3;
		ft = ft_memcmp(high1, high2, n);
		lib = memcmp(high1, high2, n);
		printf("%s -- byte > 127 | libc=%s ft=%s\n",
			((ft < 0 && lib < 0) || (ft > 0 && lib > 0)) ? "PASS" : "FAIL",
			cmp_result(lib), cmp_result(ft));

		printf("\n");
		return (0);
	}

	if (strcmp(function, "strnstr") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		char big[] = "Hello World";
		char empty[] = "";
		char *little;
		size_t len;
		char *ft;

		/* 1️⃣ little trovata all'inizio */
		little = "Hello"; len = 11;
		ft = ft_strnstr(big, little, len);
		printf("%s -- little=\"%s\", len=%zu | expected offset=0, got offset=%ld\n",
			(ft == big) ? "PASS" : "FAIL", little, len, offset(big, ft));

		/* 2️⃣ little trovata in mezzo */
		little = "World"; len = 11;
		ft = ft_strnstr(big, little, len);
		printf("%s -- little=\"%s\", len=%zu | expected offset=6, got offset=%ld\n",
			(ft == big + 6) ? "PASS" : "FAIL", little, len, offset(big, ft));

		/* 3️⃣ little trovata ma supera len */
		little = "World"; len = 8;
		ft = ft_strnstr(big, little, len);
		printf("%s -- little=\"%s\" (fuori len), len=%zu | expected NULL, got offset=%ld\n",
			(ft == NULL) ? "PASS" : "FAIL", little, len, offset(big, ft));

		/* 4️⃣ little NON presente */
		little = "42"; len = 11;
		ft = ft_strnstr(big, little, len);
		printf("%s -- little=\"%s\" (assente), len=%zu | expected NULL, got offset=%ld\n",
			(ft == NULL) ? "PASS" : "FAIL", little, len, offset(big, ft));

		/* 5️⃣ little parziale presente */
		little = "Wor"; len = 7;
		ft = ft_strnstr(big, little, len);
		printf("%s -- little=\"%s\" (parziale), len=%zu | expected NULL, got offset=%ld\n",
			(ft == NULL) ? "PASS" : "FAIL", little, len, offset(big, ft));

		/* 6️⃣ little vuota */
		little = ""; len = 0;
		ft = ft_strnstr(big, little, len);
		printf("%s -- little=\"\" (vuota), len=%zu | expected big, got offset=%ld\n",
			(ft == big) ? "PASS" : "FAIL", len, offset(big, ft));

		/* 7️⃣ len == 0 */
		little = "H"; len = 0;
		ft = ft_strnstr(big, little, len);
		printf("%s -- little=\"%s\", len=0 | expected NULL, got offset=%ld\n",
			(ft == NULL) ? "PASS" : "FAIL", little, offset(big, ft));

		/* 8️⃣ big vuota, little vuota */
		little = ""; len = 0;
		ft = ft_strnstr(empty, little, len);
		printf("%s -- big=\"\", little=\"\" | expected empty, got offset=%ld\n",
			(ft == empty) ? "PASS" : "FAIL", offset(empty, ft));

		/* 9️⃣ big vuota, little NON vuota */
		little = "H"; len = 1;
		ft = ft_strnstr(empty, little, len);
		printf("%s -- big=\"\", little=\"%s\" | expected NULL, got offset=%ld\n",
			(ft == NULL) ? "PASS" : "FAIL", little, offset(empty, ft));

		/* 🔟 match esatto a fine len */
		little = "lo"; len = 5;
		ft = ft_strnstr(big, little, len);
		printf("%s -- little=\"%s\" (fine len), len=%zu | expected offset=3, got offset=%ld\n",
			(ft == big + 3) ? "PASS" : "FAIL", little, len, offset(big, ft));

		/* 11️⃣ little lunga quanto len */
		little = "Hello"; len = 5;
		ft = ft_strnstr(big, little, len);
		printf("%s -- little=\"%s\", len=%zu | expected offset=0, got offset=%ld\n",
			(ft == big) ? "PASS" : "FAIL", little, len, offset(big, ft));

		/* 12️⃣ little più lunga di len */
		little = "World"; len = 3;
		ft = ft_strnstr(big, little, len);
		printf("%s -- little=\"%s\", len=%zu (troppo lunga) | expected NULL, got offset=%ld\n",
			(ft == NULL) ? "PASS" : "FAIL", little, len, offset(big, ft));

		/* 13️⃣ big molto corta */
		char short_big[] = "Hi";
		little = "Hi"; len = 5;
		ft = ft_strnstr(short_big, little, len);
		printf("%s -- big=\"%s\", little=\"%s\", len=%zu | expected offset=0, got offset=%ld\n",
			(ft == short_big) ? "PASS" : "FAIL", short_big, little, len, offset(short_big, ft));

		/* 14️⃣ little ripetuta */
		char repeat[] = "aaaabaaa";
		little = "baaa"; len = 8;
		ft = ft_strnstr(repeat, little, len);
		printf("%s -- little=\"%s\" (ripetuta), len=%zu | expected offset=4, got offset=%ld\n",
			(ft == repeat + 4) ? "PASS" : "FAIL", little, len, offset(repeat, ft));

		/* 15️⃣ len maggiore di big */
		little = "World"; len = 50;
		ft = ft_strnstr(big, little, len);
		printf("%s -- little=\"%s\", len=%zu (>strlen(big)) | expected offset=6, got offset=%ld\n",
			(ft == big + 6) ? "PASS" : "FAIL", little, len, offset(big, ft));

		printf("\n");
		return (0);
	}

	if (strcmp(function, "atoi") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		/* 1️⃣ numeri semplici */
		print_atoi_test("0", 0);
		print_atoi_test("42", 42);
		print_atoi_test("-42", -42);
		print_atoi_test("+42", 42);

		/* 2️⃣ spazi iniziali */
		print_atoi_test("   42", 42);
		print_atoi_test("\n\t  -42", -42);

		/* 3️⃣ testo dopo il numero */
		print_atoi_test("42abc", 42);
		print_atoi_test("123 456", 123);

		/* 4️⃣ segni strani */
		print_atoi_test("--42", 0);
		print_atoi_test("+-42", 0);
		print_atoi_test("-+42", 0);
		print_atoi_test("++42", 0);

		/* 5️⃣ solo segno */
		print_atoi_test("+", 0);
		print_atoi_test("-", 0);

		/* 6️⃣ niente numeri */
		print_atoi_test("abc", 0);
		print_atoi_test("   abc", 0);
		print_atoi_test("", 0);

		/* 7️⃣ zero e casi limite */
		print_atoi_test("000", 0);
		print_atoi_test("-000", 0);
		print_atoi_test("+000", 0);

		/* 8️⃣ numero lungo (NO overflow check richiesto) */
		print_atoi_test("2147483647", 2147483647);
		print_atoi_test("-2147483648", -2147483648);

		printf("\n");
		return (0);
	}

	if (strcmp(function, "calloc") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		void *ft;
		void *lib;
		size_t nmemb, size;
		int pass;

		/* Test 1: allocazione normale */
		nmemb = 5;
		size = sizeof(int);
		ft = ft_calloc(nmemb, size);
		lib = calloc(nmemb, size);
		pass = (ft != NULL && is_all_zero(ft, nmemb * size));
		printf("%s -- Test: allocazione normale | Input: nmemb=%zu, size=%zu | Atteso: puntatore non-NULL, memoria inizializzata a 0 | Ottenuto: %s\n",
			pass ? "PASS" : "FAIL", nmemb, size, pass ? "corretto" : "ERRORE");
		if (ft) free(ft);
		if (lib) free(lib);

		/* Test 2: memoria inizializzata a zero (byte) */
		nmemb = 10;
		size = 1;
		ft = ft_calloc(nmemb, size);
		pass = (ft != NULL && is_all_zero(ft, nmemb * size));
		printf("%s -- Test: inizializzazione a zero | Input: nmemb=%zu, size=%zu | Atteso: tutti byte = 0 | Ottenuto: %s\n",
			pass ? "PASS" : "FAIL", nmemb, size, pass ? "corretto" : "ERRORE");
		if (ft) free(ft);

		/* Test 3: nmemb = 0 (SPECIFICA: deve restituire puntatore unico passabile a free()) */
		nmemb = 0;
		size = 10;
		ft = ft_calloc(nmemb, size);
		lib = calloc(nmemb, size);
		pass = (ft != NULL && lib != NULL);
		printf("%s -- Test: nmemb = 0 | Input: nmemb=%zu, size=%zu | Atteso: puntatore unico passabile a free() (std=%p) | Ottenuto: %p\n",
			pass ? "PASS" : "FAIL", nmemb, size, lib, ft);
		if (ft) free(ft);
		if (lib) free(lib);

		/* Test 4: size = 0 (SPECIFICA: deve restituire puntatore unico passabile a free()) */
		nmemb = 10;
		size = 0;
		ft = ft_calloc(nmemb, size);
		lib = calloc(nmemb, size);
		pass = (ft != NULL && lib != NULL);
		printf("%s -- Test: size = 0 | Input: nmemb=%zu, size=%zu | Atteso: puntatore unico passabile a free() (std=%p) | Ottenuto: %p\n",
			pass ? "PASS" : "FAIL", nmemb, size, lib, ft);
		if (ft) free(ft);
		if (lib) free(lib);

		/* Test 5: nmemb = 0, size = 0 (SPECIFICA: deve restituire puntatore unico passabile a free()) */
		nmemb = 0;
		size = 0;
		ft = ft_calloc(nmemb, size);
		lib = calloc(nmemb, size);
		pass = (ft != NULL && lib != NULL);
		printf("%s -- Test: nmemb = 0, size = 0 | Input: nmemb=%zu, size=%zu | Atteso: puntatore unico passabile a free() (std=%p) | Ottenuto: %p\n",
			pass ? "PASS" : "FAIL", nmemb, size, lib, ft);
		if (ft) free(ft);
		if (lib) free(lib);

		/* Test 6: confronto contenuto con libc */
		nmemb = 7;
		size = sizeof(char);
		ft = ft_calloc(nmemb, size);
		lib = calloc(nmemb, size);
		pass = (ft && lib && memcmp(ft, lib, nmemb * size) == 0);
		printf("%s -- Test: confronto contenuto con libc | Input: nmemb=%zu, size=%zu | Atteso: contenuto identico a libc | Ottenuto: %s\n",
			pass ? "PASS" : "FAIL", nmemb, size, pass ? "identico" : "diverso");
		if (ft) free(ft);
		if (lib) free(lib);

		/* Test 7: overflow nmemb * size */
		ft = ft_calloc(SIZE_MAX, SIZE_MAX);
		pass = (ft == NULL);
		printf("%s -- Test: overflow (SIZE_MAX * SIZE_MAX) | Input: nmemb=SIZE_MAX, size=SIZE_MAX | Atteso: NULL | Ottenuto: %s\n",
			pass ? "PASS" : "FAIL", ft ? "non-NULL" : "NULL");

		/* Test 8: overflow realistico */
		ft = ft_calloc(SIZE_MAX / 2 + 1, 2);
		pass = (ft == NULL);
		printf("%s -- Test: overflow realistico | Input: nmemb=SIZE_MAX/2+1, size=2 | Atteso: NULL | Ottenuto: %s\n",
			pass ? "PASS" : "FAIL", ft ? "non-NULL" : "NULL");

		/* Test 9: grande allocazione */
		nmemb = 1000;
		size = 1000;
		ft = ft_calloc(nmemb, size);
		pass = (ft != NULL);
		if (pass)
		{
			pass = is_all_zero(ft, nmemb * size);
			printf("%s -- Test: grande allocazione | Input: nmemb=%zu, size=%zu | Atteso: puntatore non-NULL, memoria inizializzata | Ottenuto: %s\n",
				pass ? "PASS" : "FAIL", nmemb, size, pass ? "corretto" : "ERRORE");
			free(ft);
		}
		else
			printf("PASS -- Test: grande allocazione | Input: nmemb=%zu, size=%zu | Atteso: allocazione (fallita ma accettabile) | Ottenuto: NULL\n",
				nmemb, size);

		/* Test 10: scrittura dopo calloc */
		nmemb = 5;
		size = sizeof(int);
		ft = ft_calloc(nmemb, size);
		pass = (ft != NULL);
		if (pass)
		{
			((int *)ft)[0] = 42;
			((int *)ft)[4] = -42;
			pass = (((int *)ft)[0] == 42 && ((int *)ft)[4] == -42);
			printf("%s -- Test: scrittura dopo calloc | Input: nmemb=%zu, size=%zu | Atteso: memoria scrivibile | Ottenuto: %s\n",
				pass ? "PASS" : "FAIL", nmemb, size, pass ? "scrivibile" : "ERRORE");
			free(ft);
		}
		else
			printf("FAIL -- Test: scrittura dopo calloc | Input: nmemb=%zu, size=%zu | Atteso: allocazione riuscita | Ottenuto: NULL\n",
				nmemb, size);

		printf("\n");
		return (0);
	}

	if (strcmp(function, "strdup") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		char *str;
		char *dup;
		int i;

		// 1️⃣ stringa normale
		str = "Hello World";
		dup = ft_strdup(str);
		printf("%s -- input=\"%s\", dup=\"%s\"\n",
			(strcmp(str, dup) == 0 && dup != str) ? "PASS" : "FAIL", str, dup);
		free(dup);

		// 2️⃣ stringa vuota
		str = "";
		dup = ft_strdup(str);
		printf("%s -- input=\"%s\", dup=\"%s\"\n",
			(strcmp(str, dup) == 0 && dup != str) ? "PASS" : "FAIL", str, dup);
		free(dup);

		// 3️⃣ stringa di un solo carattere
		str = "A";
		dup = ft_strdup(str);
		printf("%s -- input=\"%s\", dup=\"%s\"\n",
			(strcmp(str, dup) == 0 && dup != str) ? "PASS" : "FAIL", str, dup);
		free(dup);

		// 4️⃣ stringa con caratteri speciali
		str = "Hello\n\t\0World";
		dup = ft_strdup(str);
		// strcmp si ferma al primo \0, quindi controlliamo solo la parte visibile
		printf("%s -- input=\"Hello\\n\\t\", dup=\"%s\"\n",
			(strcmp(str, dup) == 0 && dup != str) ? "PASS" : "FAIL", dup);
		free(dup);

		// 5️⃣ stringa lunga
		char long_str[1024];
		i = 0;
		while (i < 1023)
		{
			long_str[i] = 'A' + (i % 26);
			i++;
		}
		long_str[1023] = '\0';
		dup = ft_strdup(long_str);
		printf("%s -- stringa lunga, primo e ultimo char: %c/%c, %c/%c\n",
			(strcmp(long_str, dup) == 0 && dup != long_str) ? "PASS" : "FAIL",
			long_str[0], dup[0], long_str[1022], dup[1022]);
		free(dup);

		return (0);
	}

	if (strcmp(function, "substr") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		char *ft;
		char s[] = "Hello";
		char empty[] = "";
		unsigned int start;
		size_t len;

		/* Test 1: Sottostringa all'inizio */
		start = 0;
		len = 2;
		ft = ft_substr(s, start, len);
		printf("%s -- Test: sottostringa all'inizio | Input: s=\"%s\", start=%u, len=%zu | Atteso: \"He\" | Ottenuto: \"%s\"\n",
			(ft && strcmp(ft, "He") == 0) ? "PASS" : "FAIL", s, start, len, ft ? ft : "NULL");
		free(ft);

		/* Test 2: Sottostringa in mezzo */
		start = 1;
		len = 3;
		ft = ft_substr(s, start, len);
		printf("%s -- Test: sottostringa in mezzo | Input: s=\"%s\", start=%u, len=%zu | Atteso: \"ell\" | Ottenuto: \"%s\"\n",
			(ft && strcmp(ft, "ell") == 0) ? "PASS" : "FAIL", s, start, len, ft ? ft : "NULL");
		free(ft);

		/* Test 3: Len maggiore di rimanente (deve restituire solo i caratteri disponibili) */
		start = 1;
		len = 10;
		ft = ft_substr(s, start, len);
		printf("%s -- Test: len maggiore di rimanente | Input: s=\"%s\", start=%u, len=%zu | Atteso: \"ello\" | Ottenuto: \"%s\"\n",
			(ft && strcmp(ft, "ello") == 0) ? "PASS" : "FAIL", s, start, len, ft ? ft : "NULL");
		free(ft);

		/* Test 4: Start oltre la fine (deve restituire stringa vuota) */
		start = 10;
		len = 3;
		ft = ft_substr(s, start, len);
		printf("%s -- Test: start oltre la fine | Input: s=\"%s\", start=%u, len=%zu | Atteso: \"\" | Ottenuto: \"%s\"\n",
			(ft && strcmp(ft, "") == 0) ? "PASS" : "FAIL", s, start, len, ft ? ft : "NULL");
		free(ft);

		/* Test 5: Len = 0 (deve restituire stringa vuota) */
		start = 2;
		len = 0;
		ft = ft_substr(s, start, len);
		printf("%s -- Test: len = 0 | Input: s=\"%s\", start=%u, len=%zu | Atteso: \"\" | Ottenuto: \"%s\"\n",
			(ft && strcmp(ft, "") == 0) ? "PASS" : "FAIL", s, start, len, ft ? ft : "NULL");
		free(ft);

		/* Test 6: Stringa vuota */
		start = 0;
		len = 5;
		ft = ft_substr(empty, start, len);
		printf("%s -- Test: stringa vuota | Input: s=\"\", start=%u, len=%zu | Atteso: \"\" | Ottenuto: \"%s\"\n",
			(ft && strcmp(ft, "") == 0) ? "PASS" : "FAIL", start, len, ft ? ft : "NULL");
		free(ft);

		/* Test 7: Sottostringa fino alla fine */
		start = 2;
		len = 3;
		ft = ft_substr(s, start, len);
		printf("%s -- Test: sottostringa fino alla fine | Input: s=\"%s\", start=%u, len=%zu | Atteso: \"llo\" | Ottenuto: \"%s\"\n",
			(ft && strcmp(ft, "llo") == 0) ? "PASS" : "FAIL", s, start, len, ft ? ft : "NULL");
		free(ft);

		/* Test 8: s = NULL (deve restituire NULL) */
		ft = ft_substr(NULL, 0, 5);
		printf("%s -- Test: s=NULL | Input: s=NULL, start=0, len=5 | Atteso: NULL | Ottenuto: %s\n",
			(ft == NULL) ? "PASS" : "FAIL", ft ? "non-NULL" : "NULL");

		/* Test 9: Intera stringa (start=0, len=strlen(s)) */
		start = 0;
		len = strlen(s);
		ft = ft_substr(s, start, len);
		printf("%s -- Test: intera stringa | Input: s=\"%s\", start=%u, len=%zu | Atteso: \"%s\" | Ottenuto: \"%s\"\n",
			(ft && strcmp(ft, s) == 0) ? "PASS" : "FAIL", s, start, len, s, ft ? ft : "NULL");
		free(ft);

		printf("\n");
		return (0);
	}

	if (strcmp(function, "strjoin") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		char *s1;
		char *s2;
		char *ft;

		/* 1️⃣ concatenazione normale */
		s1 = "Hello";
		s2 = "World";
		ft = ft_strjoin(s1, s2);
		printf("%s -- \"%s\" + \"%s\" | expected=\"HelloWorld\", got=\"%s\"\n",
			(ft && strcmp(ft, "HelloWorld") == 0) ? "PASS" : "FAIL",
			s1, s2, ft);

		/* 2️⃣ s1 vuota */
		s1 = "";
		s2 = "42";
		ft = ft_strjoin(s1, s2);
		printf("%s -- \"\" + \"%s\" | expected=\"42\", got=\"%s\"\n",
			(ft && strcmp(ft, "42") == 0) ? "PASS" : "FAIL",
			s2, ft);

		/* 3️⃣ s2 vuota */
		s1 = "42";
		s2 = "";
		ft = ft_strjoin(s1, s2);
		printf("%s -- \"%s\" + \"\" | expected=\"42\", got=\"%s\"\n",
			(ft && strcmp(ft, "42") == 0) ? "PASS" : "FAIL",
			s1, ft);

		/* 4️⃣ entrambe vuote */
		s1 = "";
		s2 = "";
		ft = ft_strjoin(s1, s2);
		printf("%s -- \"\" + \"\" | expected=\"\", got=\"%s\"\n",
			(ft && strcmp(ft, "") == 0) ? "PASS" : "FAIL",
			ft);

		/* 5️⃣ s1 NULL */
		s1 = NULL;
		s2 = "abc";
		ft = ft_strjoin(s1, s2);
		printf("%s -- s1=NULL | expected NULL, got=%p\n",
			(ft == NULL) ? "PASS" : "FAIL", ft);

		/* 6️⃣ s2 NULL */
		s1 = "abc";
		s2 = NULL;
		ft = ft_strjoin(s1, s2);
		printf("%s -- s2=NULL | expected NULL, got=%p\n",
			(ft == NULL) ? "PASS" : "FAIL", ft);

		/* 7️⃣ stringhe lunghe */
		s1 = "abcdefghijklmnopqrstuvwxyz";
		s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		ft = ft_strjoin(s1, s2);
		printf("%s -- stringhe lunghe | expected len=%zu, got len=%zu\n",
			(ft && ft_strlen(ft) == ft_strlen(s1) + ft_strlen(s2)) ? "PASS" : "FAIL",
			ft_strlen(s1) + ft_strlen(s2),
			ft ? ft_strlen(ft) : 0);

		printf("\n");
		return (0);
	}

	if (strcmp(function, "strtrim") == 0)
	{
		printf("-------- TEST %s --------\n", function);

		char *s1;
		char *set;
		char *ft;

		/* 1️⃣ trim spazi davanti e dietro */
		s1 = "   hello world   ";
		set = " ";
		ft = ft_strtrim(s1, set);
		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
			(strcmp(ft, "hello world") == 0) ? "PASS" : "FAIL",
			s1, set, ft);
		free(ft);

		/* 2️⃣ nessun carattere da rimuovere */
		s1 = "hello";
		set = " ";
		ft = ft_strtrim(s1, set);
		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
			(strcmp(ft, "hello") == 0) ? "PASS" : "FAIL",
			s1, set, ft);
		free(ft);

		/* 3️⃣ trim solo davanti */
		s1 = "xxxhello";
		set = "x";
		ft = ft_strtrim(s1, set);
		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
			(strcmp(ft, "hello") == 0) ? "PASS" : "FAIL",
			s1, set, ft);
		free(ft);

		/* 4️⃣ trim solo dietro */
		s1 = "helloxxx";
		set = "x";
		ft = ft_strtrim(s1, set);
		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
			(strcmp(ft, "hello") == 0) ? "PASS" : "FAIL",
			s1, set, ft);
		free(ft);

		/* 5️⃣ trim davanti e dietro */
		s1 = "xxhelloxx";
		set = "x";
		ft = ft_strtrim(s1, set);
		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
			(strcmp(ft, "hello") == 0) ? "PASS" : "FAIL",
			s1, set, ft);
		free(ft);

		/* 6️⃣ set con più caratteri */
		s1 = " \n\t42 Firenze\t\n ";
		set = " \n\t";
		ft = ft_strtrim(s1, set);
		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
			(strcmp(ft, "42 Firenze") == 0) ? "PASS" : "FAIL",
			s1, set, ft);
		free(ft);

		/* 7️⃣ stringa tutta da trimmare */
		s1 = "aaaaaa";
		set = "a";
		ft = ft_strtrim(s1, set);
		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
			(strcmp(ft, "") == 0) ? "PASS" : "FAIL",
			s1, set, ft);
		free(ft);

		/* 8️⃣ stringa vuota */
		s1 = "";
		set = "abc";
		ft = ft_strtrim(s1, set);
		printf("%s -- stringa vuota -> \"%s\"\n",
			(strcmp(ft, "") == 0) ? "PASS" : "FAIL",
			ft);
		free(ft);

		/* 9️⃣ set vuoto */
		s1 = "hello";
		set = "";
		ft = ft_strtrim(s1, set);
		printf("%s -- set vuoto -> \"%s\"\n",
			(strcmp(ft, "hello") == 0) ? "PASS" : "FAIL",
			ft);
		free(ft);

		/* 🔟 caratteri interni NON rimossi */
		s1 = "abXcdXef";
		set = "abef";
		ft = ft_strtrim(s1, set);
		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
			(strcmp(ft, "XcdX") == 0) ? "PASS" : "FAIL",
			s1, set, ft);
		free(ft);

		/* 11️⃣ s1 = NULL (deve restituire NULL) */
		ft = ft_strtrim(NULL, "abc");
		printf("%s -- Test: s1=NULL | Input: s1=NULL, set=\"abc\" | Atteso: NULL | Ottenuto: %s\n",
			(ft == NULL) ? "PASS" : "FAIL", ft ? "non-NULL" : "NULL");

		/* 12️⃣ set = NULL (deve restituire NULL secondo l'implementazione) */
		s1 = "hello";
		ft = ft_strtrim(s1, NULL);
		printf("%s -- Test: set=NULL | Input: s1=\"%s\", set=NULL | Atteso: NULL | Ottenuto: %s\n",
			(ft == NULL) ? "PASS" : "FAIL", s1, ft ? "non-NULL" : "NULL");

		printf("\n");
		return (0);
	}

	if (strcmp(function, "split") == 0)
	{
		printf("-------- TEST %s --------\n", function);
	
		char **ft;
		int i, pass;
		const char *input;
		char sep;
	
		#define PRINT_SPLIT(arr) \
			do { \
				i = 0; \
				if (!arr) { printf("  Output: (null)\n"); break; } \
				printf("  Output: "); \
				while (arr[i]) { printf("[%s] ", arr[i]); i++; } \
				printf("\n"); \
			} while (0)
	
		/* Test 1: split normale (SPECIFICA: array deve terminare con NULL pointer) */
		input = "hello world 42";
		sep = ' ';
		ft = ft_split(input, sep);
		pass = (ft && strcmp(ft[0], "hello") == 0 &&
		        strcmp(ft[1], "world") == 0 &&
		        strcmp(ft[2], "42") == 0 &&
		        ft[3] == NULL);  /* SPECIFICA: array termina con NULL pointer */
		printf("%s -- Test: split normale | Input: \"%s\", sep='%c' | Atteso: [hello] [world] [42] NULL | Ottenuto: ", 
			pass ? "PASS" : "FAIL", input, sep);
		PRINT_SPLIT(ft);
		if (pass && ft)
			printf("  Verifica NULL pointer: %s\n", ft[3] == NULL ? "PASS (array termina con NULL)" : "FAIL");
		if (ft) { i = 0; while (ft[i]) free(ft[i++]); free(ft); }
	
		/* Test 2: separatori multipli consecutivi */
		input = "hello   world   42";
		sep = ' ';
		ft = ft_split(input, sep);
		pass = (ft && strcmp(ft[0], "hello") == 0 &&
		        strcmp(ft[1], "world") == 0 &&
		        strcmp(ft[2], "42") == 0 &&
		        ft[3] == NULL);
		printf("%s -- Test: separatori multipli consecutivi | Input: \"%s\", sep='%c' | Atteso: [hello] [world] [42] | ",
			pass ? "PASS" : "FAIL", input, sep);
		PRINT_SPLIT(ft);
		if (ft) { i = 0; while (ft[i]) free(ft[i++]); free(ft); }
	
		/* Test 3: separatore all'inizio */
		input = "   hello world";
		sep = ' ';
		ft = ft_split(input, sep);
		pass = (ft && strcmp(ft[0], "hello") == 0 &&
		        strcmp(ft[1], "world") == 0 &&
		        ft[2] == NULL);
		printf("%s -- Test: separatore all'inizio | Input: \"%s\", sep='%c' | Atteso: [hello] [world] | ",
			pass ? "PASS" : "FAIL", input, sep);
		PRINT_SPLIT(ft);
		if (ft) { i = 0; while (ft[i]) free(ft[i++]); free(ft); }
	
		/* Test 4: separatore alla fine */
		input = "hello world   ";
		sep = ' ';
		ft = ft_split(input, sep);
		pass = (ft && strcmp(ft[0], "hello") == 0 &&
		        strcmp(ft[1], "world") == 0 &&
		        ft[2] == NULL);
		printf("%s -- Test: separatore alla fine | Input: \"%s\", sep='%c' | Atteso: [hello] [world] | ",
			pass ? "PASS" : "FAIL", input, sep);
		PRINT_SPLIT(ft);
		if (ft) { i = 0; while (ft[i]) free(ft[i++]); free(ft); }
	
		/* Test 5: separatori all'inizio e alla fine */
		input = "   hello world   ";
		sep = ' ';
		ft = ft_split(input, sep);
		pass = (ft && strcmp(ft[0], "hello") == 0 &&
		        strcmp(ft[1], "world") == 0 &&
		        ft[2] == NULL);
		printf("%s -- Test: separatori all'inizio e fine | Input: \"%s\", sep='%c' | Atteso: [hello] [world] | ",
			pass ? "PASS" : "FAIL", input, sep);
		PRINT_SPLIT(ft);
		if (ft) { i = 0; while (ft[i]) free(ft[i++]); free(ft); }
	
		/* Test 6: solo separatori */
		input = "     ";
		sep = ' ';
		ft = ft_split(input, sep);
		pass = (ft && ft[0] == NULL);
		printf("%s -- Test: solo separatori | Input: \"%s\", sep='%c' | Atteso: [] (array vuoto) | ",
			pass ? "PASS" : "FAIL", input, sep);
		PRINT_SPLIT(ft);
		if (ft) { i = 0; while (ft[i]) free(ft[i++]); free(ft); }
	
		/* Test 7: nessun separatore */
		input = "hello";
		sep = ' ';
		ft = ft_split(input, sep);
		pass = (ft && strcmp(ft[0], "hello") == 0 &&
		        ft[1] == NULL);
		printf("%s -- Test: nessun separatore | Input: \"%s\", sep='%c' | Atteso: [hello] | ",
			pass ? "PASS" : "FAIL", input, sep);
		PRINT_SPLIT(ft);
		if (ft) { i = 0; while (ft[i]) free(ft[i++]); free(ft); }
	
		/* Test 8: stringa vuota */
		input = "";
		sep = ' ';
		ft = ft_split(input, sep);
		pass = (ft && ft[0] == NULL);
		printf("%s -- Test: stringa vuota | Input: \"\", sep='%c' | Atteso: [] (array vuoto) | ",
			pass ? "PASS" : "FAIL", sep);
		PRINT_SPLIT(ft);
		if (ft) { i = 0; while (ft[i]) free(ft[i++]); free(ft); }
	
		/* Test 9: separatore diverso (virgola) */
		input = "a,b,c,d";
		sep = ',';
		ft = ft_split(input, sep);
		pass = (ft && strcmp(ft[0], "a") == 0 &&
		        strcmp(ft[1], "b") == 0 &&
		        strcmp(ft[2], "c") == 0 &&
		        strcmp(ft[3], "d") == 0 &&
		        ft[4] == NULL);
		printf("%s -- Test: separatore virgola | Input: \"%s\", sep='%c' | Atteso: [a] [b] [c] [d] | ",
			pass ? "PASS" : "FAIL", input, sep);
		PRINT_SPLIT(ft);
		if (ft) { i = 0; while (ft[i]) free(ft[i++]); free(ft); }
	
		/* Test 10: separatore non presente */
		input = "abcdef";
		sep = ',';
		ft = ft_split(input, sep);
		pass = (ft && strcmp(ft[0], "abcdef") == 0 &&
		        ft[1] == NULL);
		printf("%s -- Test: separatore assente | Input: \"%s\", sep='%c' | Atteso: [abcdef] | ",
			pass ? "PASS" : "FAIL", input, sep);
		PRINT_SPLIT(ft);
		if (ft) { i = 0; while (ft[i]) free(ft[i++]); free(ft); }
	
		/* Test 11: separatore = '\0' */
		input = "hello";
		sep = '\0';
		ft = ft_split(input, sep);
		pass = (ft && strcmp(ft[0], "hello") == 0 &&
		        ft[1] == NULL);
		printf("%s -- Test: separatore '\\0' | Input: \"%s\", sep='\\0' | Atteso: [hello] | ",
			pass ? "PASS" : "FAIL", input);
		PRINT_SPLIT(ft);
		if (ft) { i = 0; while (ft[i]) free(ft[i++]); free(ft); }
	
		/* Test 12: token singolo */
		input = "42";
		sep = ' ';
		ft = ft_split(input, sep);
		pass = (ft && strcmp(ft[0], "42") == 0 &&
		        ft[1] == NULL);
		printf("%s -- Test: token singolo | Input: \"%s\", sep='%c' | Atteso: [42] | ",
			pass ? "PASS" : "FAIL", input, sep);
		PRINT_SPLIT(ft);
		if (ft) { i = 0; while (ft[i]) free(ft[i++]); free(ft); }
	
		/* Test 13: caratteri speciali (newline e tab) */
		input = "\n\t42\tFirenze\n";
		sep = '\t';
		ft = ft_split(input, sep);
		pass = (ft && strcmp(ft[0], "\n") == 0 &&
		        strcmp(ft[1], "42") == 0 &&
		        strcmp(ft[2], "Firenze\n") == 0 &&
		        ft[3] == NULL);
		printf("%s -- Test: caratteri speciali | Input: \"\\n\\t42\\tFirenze\\n\", sep='\\t' | Atteso: [\\n] [42] [Firenze\\n] | ",
			pass ? "PASS" : "FAIL");
		PRINT_SPLIT(ft);
		if (ft) { i = 0; while (ft[i]) free(ft[i++]); free(ft); }
	
		/* Test 14: stringa NULL */
		ft = ft_split(NULL, ' ');
		pass = (ft == NULL);
		printf("%s -- Test: input NULL | Input: NULL, sep=' ' | Atteso: NULL | Ottenuto: %s\n",
			pass ? "PASS" : "FAIL", ft ? "non-NULL" : "NULL");
	
		printf("\n");
		return 0;
	}	




	return (1);
}