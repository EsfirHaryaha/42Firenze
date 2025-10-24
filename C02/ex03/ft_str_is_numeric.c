/*#include <stdio.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	char	*str;
	int	r;

	str = "123 456";
	r = 1;
	r = ft_str_is_numeric(str);
	printf("stringa numeri: %s risultato: %d\n", str, r);	
}*/

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] - '0' >= 0 && str[i] - '0' <= 9))
		{
			return (0);
		}
		i++;
	}
	return (1);
}