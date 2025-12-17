// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: eharyaha <eharyaha@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/12/11 14:36:15 by eharyaha          #+#    #+#             */
// /*   Updated: 2025/12/11 15:19:04 by eharyaha         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "libft.h"
// #include <unistd.h>
// #include <string.h>
// #include <stdio.h>
// #include <limits.h>
// #include <stdlib.h>
// #include <stdint.h>

// int test(char *function);

// static long offset(void *base, void *ptr)
// {
//     if (!ptr)
//         return (-1);
//     return ((unsigned char *)ptr - (unsigned char *)base);
// }

// static const char *cmp_result(int r)
// {
//     if (r < 0)
//         return "< 0";
//     if (r > 0)
//         return "> 0";
//     return "== 0";
// }

// static int is_all_zero(unsigned char *p, size_t n)
// {
//     size_t i;

//     i = 0;
//     while (i < n)
//     {
//         if (p[i] != 0)
//             return (0);
//         i++;
//     }
//     return (1);
// }

// static void	print_atoi_test(char *s, int expected)
// {
// 	int	ft;

// 	ft = ft_atoi(s);
// 	printf("%s -- \"%s\" | expected=%d got=%d\n",
// 		(ft == expected) ? "PASS" : "FAIL",
// 		s, expected, ft);
// }

// int	main(int argc, char **argv)
// {
// 	char **funzioni;
// 	int n_funzioni;
// 	int	ris;

// 	if (argc < 2)
// 	{
// 		static char *default_funzioni[] = {
// 			"isalpha",
// 			"isdigit",
// 			"isalnum",
// 			"isascii",
// 			"isprint",
// 			"strlen",
// 			"memset",
// 			"bzero",
// 			"memcpy",
// 			"memmove", //10 funzioni
// 			"strlcpy",
// 			"strlcat",
// 			"toupper",
// 			"tolower",
// 			"strchr", //15
// 			"strrchr",
// 			"strncmp",
// 			"memchr",
// 			"memcmp",
// 			"strnstr", // 20 funzioni
// 			"atoi",
// 			"calloc",
// 			"strdup",
// 			"substr",
// 			"strjoin", //25
// 			"strtrim"
// 		};
// 		funzioni = default_funzioni;
// 		n_funzioni = 26;
// 	}
// 	else
// 	{
// 		funzioni = &argv[1];  // puntatore al primo argomento
// 		n_funzioni = 1;
// 	}

// 	while (n_funzioni > 0)
// 	{
// 		ris = test(funzioni[n_funzioni - 1]);
// 		n_funzioni --;
// 	}
	
// 	if (ris != 0)
// 	{
// 		printf("Funzione '%s' non trovata\n", argv[1]);
// 	}

// 	return (0);
// }

// int test(char *function)
// {
	
// 	if(strcmp(function, "isalpha") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);
// 		char	c = 'a';
// 		int	ris = ft_isalpha(c) + '0';
// 		if (ris != 0)
// 			printf("PASS  --  %c\n\n", c);
// 		return (0);
// 	}
	
// 	if(strcmp(function, "isdigit") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);
// 		printf("input: 1 --> %d\n", ft_isdigit(1));
// 		printf("input: 'a' --> %d\n", ft_isdigit('a'));
// 		printf("input: '1' --> %d\n", ft_isdigit('1'));
// 		printf("input: 0 --> %d\n", ft_isdigit(0));
// 		return (0);
// 	}
	
// 	if(strcmp(function, "isalnum") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);
// 		printf("input: 1 --> %d\n", ft_isalnum(1));
// 		printf("input: 'a' --> %d\n", ft_isalnum('a'));
// 		printf("input: '1' --> %d\n", ft_isalnum('1'));
// 		printf("input: 0 --> %d\n", ft_isalnum(0));
// 		return (0);
// 	}
	
// 	if(strcmp(function, "isascii") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);
// 		printf("input: 1 --> %d\n", ft_isascii(1));
// 		printf("input: 127 --> %d\n", ft_isascii(127));
// 		printf("input: a --> %d\n", ft_isascii('a'));
// 		printf("input: 200 --> %d\n", ft_isascii(200));
// 		printf("input non ascii: -1 --> %d\n", ft_isascii(-1));
// 		return (0);
// 	}
	
// 	if(strcmp(function, "isprint") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);
// 		printf("input: ' ' (spazio) --> %d\n", ft_isprint(' '));
// 		printf("input: 126 --> %d\n", ft_isprint(126));
// 		printf("input: \\n --> %d\n", ft_isprint('\n'));
// 		printf("input: 1 --> %d\n", ft_isprint(1));
// 		printf("input: 127 --> %d\n", ft_isprint(127));
// 		return (0);
// 	}
	
// 	if(strcmp(function, "strlen") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);
// 		printf("input: ciao --> %ld\n", ft_strlen("ciao"));
// 		printf("input: \"\" --> %ld\n", ft_strlen(""));
// 		printf("input: \" \" --> %ld\n", ft_strlen(" "));
// 		printf("input: 'ciao ciao' --> %ld\n", ft_strlen("ciao ciao"));
// 		return (0);
// 	}

// 	if(strcmp(function, "memset") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);
// 		char buffer[10];
// 		ft_memset(buffer, '5', 10);
// 		int i = 0;

// 		printf("Buffer:\n");
// 		while(i < 10)
// 		{
// 			printf("[%c] ", buffer[i]);
// 			i++;
// 		}
// 		printf("\n");
// 		return (0);
// 	}

// 	if(strcmp(function, "bzero") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);
// 		char buffer[10];
// 		int i = 0;
// 		ft_memset(buffer, '3', 10);

// 		ft_bzero(buffer, 5);
// 		while (i < 10)
// 		{
// 			printf("%c", buffer[i]);
// 			i++;
// 		}
// 		printf("\n");
// 		return (0);
// 	}

// 	if (strcmp(function, "memcpy") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);
// 		int i = 0;
// 		char	buffer_dest[10];
// 		char	buffer_src[5];
// 		ft_memset(buffer_dest, '0', 10);
// 		ft_memset(buffer_src, 'a', 5);

// 		ft_memcpy(buffer_dest, buffer_src, 3);
// 		printf("copio 3 'a' in un buffer di 10  zeri:\n");
// 		while (i < 10)
// 		{
// 			printf("%c", buffer_dest[i]);
// 			i++;
// 		}
// 		printf("\n");
// 		return (0);
// 	}

// 	if (strcmp(function, "memmove") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);
// 		char	array[10] = "123456789";
// 		int	i = 0;
		
// 		ft_memmove(array + 2, array, 4);
// 		printf("src = 123456789\ndest = ");
// 		while (i < 9)
// 		{
// 			printf("%c", array[i++]);
// 		}
// 		printf("\n");
// 		return (0);
// 	}

// 	if(strcmp(function, "strlcpy") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);
// 		char	src[10] = "abcdefghi";
// 		char	dst[5];
// 		int i = 0;

// 		ft_strlcpy(dst, src, 5);
// 		printf("src --> abcdefghi\ndst --> ");
// 		while(i < 4)
// 		{
// 			printf("%c", dst[i]);
// 			i++;
// 		}
// 		printf("\n");
// 		return (0);
// 	}

// 	if(strcmp(function, "strlcat") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);
// 		char	dst[10] = "abc";
// 		char	src[5] = " dfgh";
// 		int i = 0;

// 		int ris = ft_strlcat(dst, src, 10);
// 		printf("totale --> %d\nsrc --> ' defg'\ndst --> 'abc'\nris -->", ris);
// 		while(i < 10)
// 		{
// 			printf("%c", dst[i]);
// 			i++;
// 		}
// 		printf("\n");
// 		return (0);
// 	}

// 	if(strcmp(function, "toupper") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);
// 		char	c = 'a';
// 		char	c_upper = ft_toupper(c);
// 		printf("%c --> %c\n", c, c_upper);
// 		c = '9';
// 		c_upper = ft_toupper(c);
// 		printf("%c --> %c\n", c, c_upper);
// 		return (0);
// 	}

// 	if(strcmp(function, "tolower") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);
// 		char	c = 'A';
// 		char	c_upper = ft_tolower(c);
// 		printf("%c --> %c\n", c, c_upper);
// 		c = '9';
// 		c_upper = ft_tolower(c);
// 		printf("%c --> %c\n", c, c_upper);
// 		return (0);
// 	}

	
// 	if (strcmp(function, "strchr") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);

// 		char str[] = "AaBbCcAaBbCc";
// 		char c;
// 		char *ft;
// 		char *lib;

// 		// 1️⃣ carattere presente (minuscolo)
// 		c = 'a';
// 		ft = ft_strchr(str, c);
// 		lib = strchr(str, c);
// 		printf("%s -- cerco '%c' in \"%s\"\n",
// 			(ft == lib) ? "PASS" : "FAIL", c, str);

// 		// 2️⃣ carattere presente (maiuscolo)
// 		c = 'B';
// 		ft = ft_strchr(str, c);
// 		lib = strchr(str, c);
// 		printf("%s -- cerco '%c' in \"%s\"\n",
// 			(ft == lib) ? "PASS" : "FAIL", c, str);

// 		// 3️⃣ carattere NON presente
// 		c = 'Z';
// 		ft = ft_strchr(str, c);
// 		lib = strchr(str, c);
// 		printf("%s -- cerco '%c' (non presente)\n", (ft == lib) ? "PASS" : "FAIL", c);

// 		// 4️⃣ cerco '\0'
// 		c = '\0';
// 		ft = ft_strchr(str, c);
// 		lib = strchr(str, c);
// 		printf("%s -- cerco '\\0'\n",
// 			(ft == lib) ? "PASS" : "FAIL");

// 		// 5️⃣ stringa vuota
// 		char empty[] = "";
// 		c = 'a';
// 		ft = ft_strchr(empty, c);
// 		lib = strchr(empty, c);
// 		printf("%s -- stringa vuota\n",
// 			(ft == lib) ? "PASS" : "FAIL");

// 		printf("\n");
// 		return (0);
// 	}
	
// 	if (strcmp(function, "strrchr") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);

// 		char str[] = "AaBbCcAaBbCc";
// 		char empty[] = "";
// 		char c;
// 		char *ft;
// 		char *lib;

// 		/* 1️⃣ carattere presente più volte */
// 		c = 'a';
// 		ft = ft_strrchr(str, c);
// 		lib = strrchr(str, c);
// 		printf("%s -- cerco '%c' (più occorrenze)\n",
// 			(ft == lib) ? "PASS" : "FAIL", c);

// 		/* 2️⃣ ultima occorrenza */
// 		c = 'C';
// 		ft = ft_strrchr(str, c);
// 		lib = strrchr(str, c);
// 		printf("%s -- cerco '%c' (ultima occorrenza)\n",
// 			(ft == lib) ? "PASS" : "FAIL", c);

// 		/* 3️⃣ primo carattere */
// 		c = 'A';
// 		ft = ft_strrchr(str, c);
// 		lib = strrchr(str, c);
// 		printf("%s -- cerco '%c' (prima occorrenza)\n",
// 			(ft == lib) ? "PASS" : "FAIL", c);

// 		/* 4️⃣ carattere NON presente */
// 		c = 'z';
// 		ft = ft_strrchr(str, c);
// 		lib = strrchr(str, c);
// 		printf("%s -- cerco '%c' (non presente)\n",
// 			(ft == lib) ? "PASS" : "FAIL", c);

// 		/* 5️⃣ carattere '\0' */
// 		c = '\0';
// 		ft = ft_strrchr(str, c);
// 		lib = strrchr(str, c);
// 		printf("%s -- cerco '\\0'\n",
// 			(ft == lib) ? "PASS" : "FAIL");

// 		/* 6️⃣ stringa vuota */
// 		c = 'a';
// 		ft = ft_strrchr(empty, c);
// 		lib = strrchr(empty, c);
// 		printf("%s -- stringa vuota\n",
// 			(ft == lib) ? "PASS" : "FAIL");

// 		/* 7️⃣ '\0' su stringa vuota */
// 		c = '\0';
// 		ft = ft_strrchr(empty, c);
// 		lib = strrchr(empty, c);
// 		printf("%s -- '\\0' su stringa vuota\n",
// 			(ft == lib) ? "PASS" : "FAIL");

// 		printf("\n");
// 		return (0);
// 	}

// 	if (strcmp(function, "strncmp") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);

// 		const char *s1;
// 		const char *s2;
// 		size_t n;
// 		int ft;
// 		int lib;

// 		/* 1️⃣ n == 0 (deve tornare 0) */
// 		s1 = "abc";
// 		s2 = "xyz";
// 		n = 0;
// 		ft = ft_strncmp(s1, s2, n);
// 		lib = strncmp(s1, s2, n);
// 		printf("%s -- n = 0\n", (ft == lib) ? "PASS" : "FAIL");

// 		/* 2️⃣ stringhe identiche */
// 		s1 = "abcdef";
// 		s2 = "abcdef";
// 		n = 10;
// 		ft = ft_strncmp(s1, s2, n);
// 		lib = strncmp(s1, s2, n);
// 		printf("%s -- stringhe identiche\n",
// 			(ft == lib) ? "PASS" : "FAIL");

// 		/* 3️⃣ differenza prima di n */
// 		s1 = "abcXef";
// 		s2 = "abcYef";
// 		n = 6;
// 		ft = ft_strncmp(s1, s2, n);
// 		lib = strncmp(s1, s2, n);
// 		printf("%s -- differenza prima di n\n",
// 			((ft < 0 && lib < 0) || (ft > 0 && lib > 0)) ? "PASS" : "FAIL");

// 		/* 4️⃣ differenza dopo n (uguali) */
// 		s1 = "abcdef";
// 		s2 = "abcXYZ";
// 		n = 3;
// 		ft = ft_strncmp(s1, s2, n);
// 		lib = strncmp(s1, s2, n);
// 		printf("%s -- differenza dopo n\n",
// 			(ft == lib) ? "PASS" : "FAIL");

// 		/* 5️⃣ s1 più corta di s2 */
// 		s1 = "abc";
// 		s2 = "abcd";
// 		n = 10;
// 		ft = ft_strncmp(s1, s2, n);
// 		lib = strncmp(s1, s2, n);
// 		printf("%s -- s1 più corta\n",
// 			((ft < 0 && lib < 0) || (ft > 0 && lib > 0)) ? "PASS" : "FAIL");

// 		/* 6️⃣ s2 più corta di s1 */
// 		s1 = "abcd";
// 		s2 = "abc";
// 		n = 10;
// 		ft = ft_strncmp(s1, s2, n);
// 		lib = strncmp(s1, s2, n);
// 		printf("%s -- s2 più corta\n",
// 			((ft < 0 && lib < 0) || (ft > 0 && lib > 0)) ? "PASS" : "FAIL");

// 		/* 7️⃣ una stringa vuota */
// 		s1 = "";
// 		s2 = "abc";
// 		n = 5;
// 		ft = ft_strncmp(s1, s2, n);
// 		lib = strncmp(s1, s2, n);
// 		printf("%s -- s1 vuota\n",
// 			((ft < 0 && lib < 0) || (ft > 0 && lib > 0)) ? "PASS" : "FAIL");

// 		/* 8️⃣ entrambe vuote */
// 		s1 = "";
// 		s2 = "";
// 		n = 5;
// 		ft = ft_strncmp(s1, s2, n);
// 		lib = strncmp(s1, s2, n);
// 		printf("%s -- entrambe vuote\n",
// 			(ft == lib) ? "PASS" : "FAIL");

// 		/* 9️⃣ confronto con '\0' dentro n */
// 		s1 = "abc";
// 		s2 = "abc\0xyz";
// 		n = 6;
// 		ft = ft_strncmp(s1, s2, n);
// 		lib = strncmp(s1, s2, n);
// 		printf("%s -- confronto con '\\0'\n",
// 			(ft == lib) ? "PASS" : "FAIL");

// 		printf("\n");
// 		return (0);
// 	}

// 	if (strcmp(function, "memchr") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);

// 		unsigned char buf[] = { 'A', 'B', 'C', 0, 'D', 'E', 'F' };
// 		unsigned char high[] = { 200, 201, 202, 203 };

// 		int c;
// 		size_t n;
// 		void *ft;
// 		void *lib;

// 		/* 1️⃣ trovato all'inizio */
// 		c = 'A'; n = 7;
// 		ft = ft_memchr(buf, c, n);
// 		lib = memchr(buf, c, n);
// 		printf("%s -- cerco '%c', n=%zu | libc=%ld ft=%ld\n",
// 			(ft == lib) ? "PASS" : "FAIL",
// 			c, n, offset(buf, lib), offset(buf, ft));

// 		/* 2️⃣ trovato in mezzo */
// 		c = 'C'; n = 7;
// 		ft = ft_memchr(buf, c, n);
// 		lib = memchr(buf, c, n);
// 		printf("%s -- cerco '%c', n=%zu | libc=%ld ft=%ld\n",
// 			(ft == lib) ? "PASS" : "FAIL",
// 			c, n, offset(buf, lib), offset(buf, ft));

// 		/* 3️⃣ cerco '\\0' */
// 		c = '\0'; n = 7;
// 		ft = ft_memchr(buf, c, n);
// 		lib = memchr(buf, c, n);
// 		printf("%s -- cerco '\\0', n=%zu | libc=%ld ft=%ld\n",
// 			(ft == lib) ? "PASS" : "FAIL",
// 			n, offset(buf, lib), offset(buf, ft));

// 		/* 4️⃣ presente ma fuori n */
// 		c = 'E'; n = 4;
// 		ft = ft_memchr(buf, c, n);
// 		lib = memchr(buf, c, n);
// 		printf("%s -- cerco '%c', n=%zu (fuori) | libc=%ld ft=%ld\n",
// 			(ft == lib) ? "PASS" : "FAIL",
// 			c, n, offset(buf, lib), offset(buf, ft));

// 		/* 5️⃣ non presente */
// 		c = 'Z'; n = 7;
// 		ft = ft_memchr(buf, c, n);
// 		lib = memchr(buf, c, n);
// 		printf("%s -- cerco '%c', n=%zu (assente) | libc=%ld ft=%ld\n",
// 			(ft == lib) ? "PASS" : "FAIL",
// 			c, n, offset(buf, lib), offset(buf, ft));

// 		/* 6️⃣ n == 0 */
// 		c = 'A'; n = 0;
// 		ft = ft_memchr(buf, c, n);
// 		lib = memchr(buf, c, n);
// 		printf("%s -- cerco '%c', n=0 | libc=%ld ft=%ld\n",
// 			(ft == lib) ? "PASS" : "FAIL",
// 			c, offset(buf, lib), offset(buf, ft));

// 		/* 7️⃣ byte > 127 */
// 		c = 202; n = 4;
// 		ft = ft_memchr(high, c, n);
// 		lib = memchr(high, c, n);
// 		printf("%s -- cerco %d (>127), n=%zu | libc=%ld ft=%ld\n",
// 			(ft == lib) ? "PASS" : "FAIL",
// 			c, n, offset(high, lib), offset(high, ft));

// 		printf("\n");
// 		return (0);
// 	}

// 	if (strcmp(function, "memcmp") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);

// 		unsigned char a1[] = { 'A', 'B', 'C', 'D' };
// 		unsigned char a2[] = { 'A', 'B', 'C', 'D' };

// 		unsigned char b1[] = { 'A', 'B', 'C', 'D' };
// 		unsigned char b2[] = { 'A', 'B', 'X', 'D' };

// 		unsigned char c1[] = { 'A', 'B', 0, 'D' };
// 		unsigned char c2[] = { 'A', 'B', 0, 'E' };

// 		unsigned char high1[] = { 200, 201, 202 };
// 		unsigned char high2[] = { 200, 201, 100 };

// 		size_t n;
// 		int ft;
// 		int lib;

// 		/* 1️⃣ blocchi identici */
// 		n = 4;
// 		ft = ft_memcmp(a1, a2, n);
// 		lib = memcmp(a1, a2, n);
// 		printf("%s -- identici, n=%zu | libc=%s ft=%s\n",
// 			(ft == lib) ? "PASS" : "FAIL",
// 			n, cmp_result(lib), cmp_result(ft));

// 		/* 2️⃣ differenza al primo byte */
// 		n = 4;
// 		ft = ft_memcmp(b1, b2, n);
// 		lib = memcmp(b1, b2, n);
// 		printf("%s -- differenza al byte 2 | libc=%s ft=%s\n",
// 			((ft < 0 && lib < 0) || (ft > 0 && lib > 0)) ? "PASS" : "FAIL",
// 			cmp_result(lib), cmp_result(ft));

// 		/* 3️⃣ differenza dopo '\0' */
// 		n = 4;
// 		ft = ft_memcmp(c1, c2, n);
// 		lib = memcmp(c1, c2, n);
// 		printf("%s -- confronto oltre '\\0' | libc=%s ft=%s\n",
// 			((ft < 0 && lib < 0) || (ft > 0 && lib > 0)) ? "PASS" : "FAIL",
// 			cmp_result(lib), cmp_result(ft));

// 		/* 4️⃣ differenza fuori n */
// 		n = 2;
// 		ft = ft_memcmp(b1, b2, n);
// 		lib = memcmp(b1, b2, n);
// 		printf("%s -- differenza fuori n | libc=%s ft=%s\n",
// 			(ft == lib) ? "PASS" : "FAIL",
// 			cmp_result(lib), cmp_result(ft));

// 		/* 5️⃣ n == 0 */
// 		n = 0;
// 		ft = ft_memcmp(b1, b2, n);
// 		lib = memcmp(b1, b2, n);
// 		printf("%s -- n == 0 | libc=%s ft=%s\n",
// 			(ft == lib) ? "PASS" : "FAIL",
// 			cmp_result(lib), cmp_result(ft));

// 		/* 6️⃣ byte > 127 (unsigned char) */
// 		n = 3;
// 		ft = ft_memcmp(high1, high2, n);
// 		lib = memcmp(high1, high2, n);
// 		printf("%s -- byte > 127 | libc=%s ft=%s\n",
// 			((ft < 0 && lib < 0) || (ft > 0 && lib > 0)) ? "PASS" : "FAIL",
// 			cmp_result(lib), cmp_result(ft));

// 		printf("\n");
// 		return (0);
// 	}

// 	if (strcmp(function, "strnstr") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);

// 		char big[] = "Hello World";
// 		char empty[] = "";
// 		char *little;
// 		size_t len;
// 		char *ft;

// 		/* 1️⃣ little trovata all'inizio */
// 		little = "Hello"; len = 11;
// 		ft = ft_strnstr(big, little, len);
// 		printf("%s -- little=\"%s\", len=%zu | expected offset=0, got offset=%ld\n",
// 			(ft == big) ? "PASS" : "FAIL", little, len, offset(big, ft));

// 		/* 2️⃣ little trovata in mezzo */
// 		little = "World"; len = 11;
// 		ft = ft_strnstr(big, little, len);
// 		printf("%s -- little=\"%s\", len=%zu | expected offset=6, got offset=%ld\n",
// 			(ft == big + 6) ? "PASS" : "FAIL", little, len, offset(big, ft));

// 		/* 3️⃣ little trovata ma supera len */
// 		little = "World"; len = 8;
// 		ft = ft_strnstr(big, little, len);
// 		printf("%s -- little=\"%s\" (fuori len), len=%zu | expected NULL, got offset=%ld\n",
// 			(ft == NULL) ? "PASS" : "FAIL", little, len, offset(big, ft));

// 		/* 4️⃣ little NON presente */
// 		little = "42"; len = 11;
// 		ft = ft_strnstr(big, little, len);
// 		printf("%s -- little=\"%s\" (assente), len=%zu | expected NULL, got offset=%ld\n",
// 			(ft == NULL) ? "PASS" : "FAIL", little, len, offset(big, ft));

// 		/* 5️⃣ little parziale presente */
// 		little = "Wor"; len = 7;
// 		ft = ft_strnstr(big, little, len);
// 		printf("%s -- little=\"%s\" (parziale), len=%zu | expected NULL, got offset=%ld\n",
// 			(ft == NULL) ? "PASS" : "FAIL", little, len, offset(big, ft));

// 		/* 6️⃣ little vuota */
// 		little = ""; len = 0;
// 		ft = ft_strnstr(big, little, len);
// 		printf("%s -- little=\"\" (vuota), len=%zu | expected big, got offset=%ld\n",
// 			(ft == big) ? "PASS" : "FAIL", len, offset(big, ft));

// 		/* 7️⃣ len == 0 */
// 		little = "H"; len = 0;
// 		ft = ft_strnstr(big, little, len);
// 		printf("%s -- little=\"%s\", len=0 | expected NULL, got offset=%ld\n",
// 			(ft == NULL) ? "PASS" : "FAIL", little, offset(big, ft));

// 		/* 8️⃣ big vuota, little vuota */
// 		little = ""; len = 0;
// 		ft = ft_strnstr(empty, little, len);
// 		printf("%s -- big=\"\", little=\"\" | expected empty, got offset=%ld\n",
// 			(ft == empty) ? "PASS" : "FAIL", offset(empty, ft));

// 		/* 9️⃣ big vuota, little NON vuota */
// 		little = "H"; len = 1;
// 		ft = ft_strnstr(empty, little, len);
// 		printf("%s -- big=\"\", little=\"%s\" | expected NULL, got offset=%ld\n",
// 			(ft == NULL) ? "PASS" : "FAIL", little, offset(empty, ft));

// 		/* 🔟 match esatto a fine len */
// 		little = "lo"; len = 5;
// 		ft = ft_strnstr(big, little, len);
// 		printf("%s -- little=\"%s\" (fine len), len=%zu | expected offset=3, got offset=%ld\n",
// 			(ft == big + 3) ? "PASS" : "FAIL", little, len, offset(big, ft));

// 		/* 11️⃣ little lunga quanto len */
// 		little = "Hello"; len = 5;
// 		ft = ft_strnstr(big, little, len);
// 		printf("%s -- little=\"%s\", len=%zu | expected offset=0, got offset=%ld\n",
// 			(ft == big) ? "PASS" : "FAIL", little, len, offset(big, ft));

// 		/* 12️⃣ little più lunga di len */
// 		little = "World"; len = 3;
// 		ft = ft_strnstr(big, little, len);
// 		printf("%s -- little=\"%s\", len=%zu (troppo lunga) | expected NULL, got offset=%ld\n",
// 			(ft == NULL) ? "PASS" : "FAIL", little, len, offset(big, ft));

// 		/* 13️⃣ big molto corta */
// 		char short_big[] = "Hi";
// 		little = "Hi"; len = 5;
// 		ft = ft_strnstr(short_big, little, len);
// 		printf("%s -- big=\"%s\", little=\"%s\", len=%zu | expected offset=0, got offset=%ld\n",
// 			(ft == short_big) ? "PASS" : "FAIL", short_big, little, len, offset(short_big, ft));

// 		/* 14️⃣ little ripetuta */
// 		char repeat[] = "aaaabaaa";
// 		little = "baaa"; len = 8;
// 		ft = ft_strnstr(repeat, little, len);
// 		printf("%s -- little=\"%s\" (ripetuta), len=%zu | expected offset=4, got offset=%ld\n",
// 			(ft == repeat + 4) ? "PASS" : "FAIL", little, len, offset(repeat, ft));

// 		/* 15️⃣ len maggiore di big */
// 		little = "World"; len = 50;
// 		ft = ft_strnstr(big, little, len);
// 		printf("%s -- little=\"%s\", len=%zu (>strlen(big)) | expected offset=6, got offset=%ld\n",
// 			(ft == big + 6) ? "PASS" : "FAIL", little, len, offset(big, ft));

// 		printf("\n");
// 		return (0);
// 	}

// 	if (strcmp(function, "atoi") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);

// 		/* 1️⃣ numeri semplici */
// 		print_atoi_test("0", 0);
// 		print_atoi_test("42", 42);
// 		print_atoi_test("-42", -42);
// 		print_atoi_test("+42", 42);

// 		/* 2️⃣ spazi iniziali */
// 		print_atoi_test("   42", 42);
// 		print_atoi_test("\n\t  -42", -42);

// 		/* 3️⃣ testo dopo il numero */
// 		print_atoi_test("42abc", 42);
// 		print_atoi_test("123 456", 123);

// 		/* 4️⃣ segni strani */
// 		print_atoi_test("--42", 0);
// 		print_atoi_test("+-42", 0);
// 		print_atoi_test("-+42", 0);
// 		print_atoi_test("++42", 0);

// 		/* 5️⃣ solo segno */
// 		print_atoi_test("+", 0);
// 		print_atoi_test("-", 0);

// 		/* 6️⃣ niente numeri */
// 		print_atoi_test("abc", 0);
// 		print_atoi_test("   abc", 0);
// 		print_atoi_test("", 0);

// 		/* 7️⃣ zero e casi limite */
// 		print_atoi_test("000", 0);
// 		print_atoi_test("-000", 0);
// 		print_atoi_test("+000", 0);

// 		/* 8️⃣ numero lungo (NO overflow check richiesto) */
// 		print_atoi_test("2147483647", 2147483647);
// 		print_atoi_test("-2147483648", -2147483648);

// 		printf("\n");
// 		return (0);
// 	}

// 	if (strcmp(function, "calloc") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);

// 		void *ft;
// 		void *lib;

// 		/* 1️⃣ allocazione normale */
// 		ft = ft_calloc(5, sizeof(int));
// 		lib = calloc(5, sizeof(int));
// 		printf("%s -- allocazione normale\n",
// 			(ft && is_all_zero(ft, 5 * sizeof(int))) ? "PASS" : "FAIL");
// 		free(ft);
// 		free(lib);

// 		/* 2️⃣ memoria inizializzata a zero (byte) */
// 		ft = ft_calloc(10, 1);
// 		printf("%s -- inizializzata a zero\n",
// 			(ft && is_all_zero(ft, 10)) ? "PASS" : "FAIL");
// 		free(ft);

// 		/* 3️⃣ nmemb = 0 */
// 		ft = ft_calloc(0, 10);
// 		printf("%s -- nmemb = 0 (free valido)\n",
// 			(ft != NULL) ? "PASS" : "FAIL");
// 		free(ft);

// 		/* 4️⃣ size = 0 */
// 		ft = ft_calloc(10, 0);
// 		printf("%s -- size = 0 (free valido)\n",
// 			(ft != NULL) ? "PASS" : "FAIL");
// 		free(ft);

// 		/* 5️⃣ nmemb = 0, size = 0 */
// 		ft = ft_calloc(0, 0);
// 		printf("%s -- nmemb = 0, size = 0\n",
// 			(ft != NULL) ? "PASS" : "FAIL");
// 		free(ft);

// 		/* 6️⃣ confronto con libc (caso normale) */
// 		ft = ft_calloc(7, sizeof(char));
// 		lib = calloc(7, sizeof(char));
// 		printf("%s -- confronto con libc (contenuto)\n",
// 			(ft && lib && memcmp(ft, lib, 7) == 0) ? "PASS" : "FAIL");
// 		free(ft);
// 		free(lib);

// 		/* 7️⃣ overflow nmemb * size */
// 		ft = ft_calloc(SIZE_MAX, SIZE_MAX);
// 		printf("%s -- overflow (deve tornare NULL)\n",
// 			(ft == NULL) ? "PASS" : "FAIL");

// 		/* 8️⃣ overflow realistico */
// 		ft = ft_calloc(SIZE_MAX / 2 + 1, 2);
// 		printf("%s -- overflow realistico\n",
// 			(ft == NULL) ? "PASS" : "FAIL");

// 		/* 9️⃣ grande allocazione (se possibile) */
// 		ft = ft_calloc(1000, 1000);
// 		if (ft)
// 		{
// 			printf("PASS -- grande allocazione\n");
// 			free(ft);
// 		}
// 		else
// 			printf("PASS -- grande allocazione (fallita ma accettabile)\n");

// 		/* 🔟 scrittura dopo calloc */
// 		ft = ft_calloc(5, sizeof(int));
// 		if (ft)
// 		{
// 			((int *)ft)[0] = 42;
// 			((int *)ft)[4] = -42;
// 			printf("PASS -- scrittura dopo calloc\n");
// 			free(ft);
// 		}
// 		else
// 			printf("FAIL -- scrittura dopo calloc\n");

// 		printf("\n");
// 		return (0);
// 	}

// 	if (strcmp(function, "strdup") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);

// 		char *str;
// 		char *dup;
// 		int i;

// 		// 1️⃣ stringa normale
// 		str = "Hello World";
// 		dup = ft_strdup(str);
// 		printf("%s -- input=\"%s\", dup=\"%s\"\n",
// 			(strcmp(str, dup) == 0 && dup != str) ? "PASS" : "FAIL", str, dup);
// 		free(dup);

// 		// 2️⃣ stringa vuota
// 		str = "";
// 		dup = ft_strdup(str);
// 		printf("%s -- input=\"%s\", dup=\"%s\"\n",
// 			(strcmp(str, dup) == 0 && dup != str) ? "PASS" : "FAIL", str, dup);
// 		free(dup);

// 		// 3️⃣ stringa di un solo carattere
// 		str = "A";
// 		dup = ft_strdup(str);
// 		printf("%s -- input=\"%s\", dup=\"%s\"\n",
// 			(strcmp(str, dup) == 0 && dup != str) ? "PASS" : "FAIL", str, dup);
// 		free(dup);

// 		// 4️⃣ stringa con caratteri speciali
// 		str = "Hello\n\t\0World";
// 		dup = ft_strdup(str);
// 		// strcmp si ferma al primo \0, quindi controlliamo solo la parte visibile
// 		printf("%s -- input=\"Hello\\n\\t\", dup=\"%s\"\n",
// 			(strcmp(str, dup) == 0 && dup != str) ? "PASS" : "FAIL", dup);
// 		free(dup);

// 		// 5️⃣ stringa lunga
// 		char long_str[1024];
// 		i = 0;
// 		while (i < 1023)
// 		{
// 			long_str[i] = 'A' + (i % 26);
// 			i++;
// 		}
// 		long_str[1023] = '\0';
// 		dup = ft_strdup(long_str);
// 		printf("%s -- stringa lunga, primo e ultimo char: %c/%c, %c/%c\n",
// 			(strcmp(long_str, dup) == 0 && dup != long_str) ? "PASS" : "FAIL",
// 			long_str[0], dup[0], long_str[1022], dup[1022]);
// 		free(dup);

// 		return (0);
// 	}

// 	if (strcmp(function, "substr") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);

// 		char *ft;
// 		char s[] = "Hello";
// 		char empty[] = "";

// 		/* 1️⃣ Sottostringa all'inizio */
// 		ft = ft_substr(s, 0, 2);
// 		printf("%s -- s=\"%s\", start=0, len=2 | expected=\"He\", got=\"%s\"\n",
// 			(ft && strcmp(ft, "He") == 0) ? "PASS" : "FAIL", s, ft);
// 		free(ft);

// 		/* 2️⃣ Sottostringa in mezzo */
// 		ft = ft_substr(s, 1, 3);
// 		printf("%s -- s=\"%s\", start=1, len=3 | expected=\"ell\", got=\"%s\"\n",
// 			(ft && strcmp(ft, "ell") == 0) ? "PASS" : "FAIL", s, ft);
// 		free(ft);

// 		/* 3️⃣ Len maggiore di rimanente */
// 		ft = ft_substr(s, 1, 10);
// 		printf("%s -- s=\"%s\", start=1, len=10 | expected=\"ello\", got=\"%s\"\n",
// 			(ft && strcmp(ft, "ello") == 0) ? "PASS" : "FAIL", s, ft);
// 		free(ft);

// 		/* 4️⃣ Start oltre la fine */
// 		ft = ft_substr(s, 10, 3);
// 		printf("%s -- s=\"%s\", start=10, len=3 | expected=\"\", got=\"%s\"\n",
// 			(ft && strcmp(ft, "") == 0) ? "PASS" : "FAIL", s, ft);
// 		free(ft);

// 		/* 5️⃣ Len = 0 */
// 		ft = ft_substr(s, 2, 0);
// 		printf("%s -- s=\"%s\", start=2, len=0 | expected=\"\", got=\"%s\"\n",
// 			(ft && strcmp(ft, "") == 0) ? "PASS" : "FAIL", s, ft);
// 		free(ft);

// 		/* 6️⃣ Stringa vuota */
// 		ft = ft_substr(empty, 0, 5);
// 		printf("%s -- s=\"\", start=0, len=5 | expected=\"\", got=\"%s\"\n",
// 			(ft && strcmp(ft, "") == 0) ? "PASS" : "FAIL", ft);
// 		free(ft);

// 		/* 7️⃣ Sottostringa fino alla fine */
// 		ft = ft_substr(s, 2, 3);
// 		printf("%s -- s=\"%s\", start=2, len=3 | expected=\"llo\", got=\"%s\"\n",
// 			(ft && strcmp(ft, "llo") == 0) ? "PASS" : "FAIL", s, ft);
// 		free(ft);

// 		printf("\n");
// 		return (0);
// 	}

// 	if (strcmp(function, "strjoin") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);

// 		char *s1;
// 		char *s2;
// 		char *ft;

// 		/* 1️⃣ concatenazione normale */
// 		s1 = "Hello";
// 		s2 = "World";
// 		ft = ft_strjoin(s1, s2);
// 		printf("%s -- \"%s\" + \"%s\" | expected=\"HelloWorld\", got=\"%s\"\n",
// 			(ft && strcmp(ft, "HelloWorld") == 0) ? "PASS" : "FAIL",
// 			s1, s2, ft);

// 		/* 2️⃣ s1 vuota */
// 		s1 = "";
// 		s2 = "42";
// 		ft = ft_strjoin(s1, s2);
// 		printf("%s -- \"\" + \"%s\" | expected=\"42\", got=\"%s\"\n",
// 			(ft && strcmp(ft, "42") == 0) ? "PASS" : "FAIL",
// 			s2, ft);

// 		/* 3️⃣ s2 vuota */
// 		s1 = "42";
// 		s2 = "";
// 		ft = ft_strjoin(s1, s2);
// 		printf("%s -- \"%s\" + \"\" | expected=\"42\", got=\"%s\"\n",
// 			(ft && strcmp(ft, "42") == 0) ? "PASS" : "FAIL",
// 			s1, ft);

// 		/* 4️⃣ entrambe vuote */
// 		s1 = "";
// 		s2 = "";
// 		ft = ft_strjoin(s1, s2);
// 		printf("%s -- \"\" + \"\" | expected=\"\", got=\"%s\"\n",
// 			(ft && strcmp(ft, "") == 0) ? "PASS" : "FAIL",
// 			ft);

// 		/* 5️⃣ s1 NULL */
// 		s1 = NULL;
// 		s2 = "abc";
// 		ft = ft_strjoin(s1, s2);
// 		printf("%s -- s1=NULL | expected NULL, got=%p\n",
// 			(ft == NULL) ? "PASS" : "FAIL", ft);

// 		/* 6️⃣ s2 NULL */
// 		s1 = "abc";
// 		s2 = NULL;
// 		ft = ft_strjoin(s1, s2);
// 		printf("%s -- s2=NULL | expected NULL, got=%p\n",
// 			(ft == NULL) ? "PASS" : "FAIL", ft);

// 		/* 7️⃣ stringhe lunghe */
// 		s1 = "abcdefghijklmnopqrstuvwxyz";
// 		s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// 		ft = ft_strjoin(s1, s2);
// 		printf("%s -- stringhe lunghe | expected len=%zu, got len=%zu\n",
// 			(ft && ft_strlen(ft) == ft_strlen(s1) + ft_strlen(s2)) ? "PASS" : "FAIL",
// 			ft_strlen(s1) + ft_strlen(s2),
// 			ft ? ft_strlen(ft) : 0);

// 		printf("\n");
// 		return (0);
// 	}

// 	if (strcmp(function, "strtrim") == 0)
// 	{
// 		printf("-------- TEST %s --------\n", function);

// 		char *s1;
// 		char *set;
// 		char *ft;

// 		/* 1️⃣ trim spazi davanti e dietro */
// 		s1 = "   hello world   ";
// 		set = " ";
// 		ft = ft_strtrim(s1, set);
// 		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
// 			(strcmp(ft, "hello world") == 0) ? "PASS" : "FAIL",
// 			s1, set, ft);
// 		free(ft);

// 		/* 2️⃣ nessun carattere da rimuovere */
// 		s1 = "hello";
// 		set = " ";
// 		ft = ft_strtrim(s1, set);
// 		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
// 			(strcmp(ft, "hello") == 0) ? "PASS" : "FAIL",
// 			s1, set, ft);
// 		free(ft);

// 		/* 3️⃣ trim solo davanti */
// 		s1 = "xxxhello";
// 		set = "x";
// 		ft = ft_strtrim(s1, set);
// 		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
// 			(strcmp(ft, "hello") == 0) ? "PASS" : "FAIL",
// 			s1, set, ft);
// 		free(ft);

// 		/* 4️⃣ trim solo dietro */
// 		s1 = "helloxxx";
// 		set = "x";
// 		ft = ft_strtrim(s1, set);
// 		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
// 			(strcmp(ft, "hello") == 0) ? "PASS" : "FAIL",
// 			s1, set, ft);
// 		free(ft);

// 		/* 5️⃣ trim davanti e dietro */
// 		s1 = "xxhelloxx";
// 		set = "x";
// 		ft = ft_strtrim(s1, set);
// 		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
// 			(strcmp(ft, "hello") == 0) ? "PASS" : "FAIL",
// 			s1, set, ft);
// 		free(ft);

// 		/* 6️⃣ set con più caratteri */
// 		s1 = " \n\t42 Firenze\t\n ";
// 		set = " \n\t";
// 		ft = ft_strtrim(s1, set);
// 		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
// 			(strcmp(ft, "42 Firenze") == 0) ? "PASS" : "FAIL",
// 			s1, set, ft);
// 		free(ft);

// 		/* 7️⃣ stringa tutta da trimmare */
// 		s1 = "aaaaaa";
// 		set = "a";
// 		ft = ft_strtrim(s1, set);
// 		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
// 			(strcmp(ft, "") == 0) ? "PASS" : "FAIL",
// 			s1, set, ft);
// 		free(ft);

// 		/* 8️⃣ stringa vuota */
// 		s1 = "";
// 		set = "abc";
// 		ft = ft_strtrim(s1, set);
// 		printf("%s -- stringa vuota -> \"%s\"\n",
// 			(strcmp(ft, "") == 0) ? "PASS" : "FAIL",
// 			ft);
// 		free(ft);

// 		/* 9️⃣ set vuoto */
// 		s1 = "hello";
// 		set = "";
// 		ft = ft_strtrim(s1, set);
// 		printf("%s -- set vuoto -> \"%s\"\n",
// 			(strcmp(ft, "hello") == 0) ? "PASS" : "FAIL",
// 			ft);
// 		free(ft);

// 		/* 🔟 caratteri interni NON rimossi */
// 		s1 = "abXcdXef";
// 		set = "abef";
// 		ft = ft_strtrim(s1, set);
// 		printf("%s -- \"%s\" | set=\"%s\" -> \"%s\"\n",
// 			(strcmp(ft, "XcdX") == 0) ? "PASS" : "FAIL",
// 			s1, set, ft);
// 		free(ft);

// 		printf("\n");
// 		return (0);
// 	}




// 	return (1);
// }