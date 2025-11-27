/*#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	str[80] = "hi, how are you? 42words forty-two; fifty+and+one";
	printf("\n\ninput: %s\n\nris: ", str);
	ft_strcapitalize(str);
	printf("%s\n\n\n", str);
	return (0);
}*/

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + ('a' - 'A');
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (new_word && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - ('a' - 'A');
			new_word = 0;
		}
		else
			new_word = 1;
		i++;
	}
	return (str);
}
