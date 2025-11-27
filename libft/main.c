#include "libft.h"
#include <unistd.h>

int	ft_isalpha(int c);

int	main()
{
	int n = ft_isalpha('Z');
	write(1, &n, 1);
	return (0);
}
