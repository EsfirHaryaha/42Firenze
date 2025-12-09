#include <unistd.h>

int     main(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {

    }
    return (0);
}

int     ft_strcmp(char *s1, char * s2)
{
    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    {
        i++;
    }
    return (s1[i] - s2[i]);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}