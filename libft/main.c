#include "libft.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);

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
	
	
	printf("Funzione '%s' non trovata\n", argv[1]);
	return (0);
}

