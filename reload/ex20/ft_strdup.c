#include <stdlib.h>
#include <stdio.h>
char *ft_strdup(char *str);
int ft_strlen(char *str);

char *ft_strdup(char *str)
{
    int len;
    int i;
    char    *dup;

    len = ft_strlen(str);
    dup = malloc(sizeof(char) * (len + 1));
    if(!dup)
    {
        return (NULL);
    }
    i = 0;
    while(i < len)
    {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

int main(void)
{
    char    *str = "Ciao";
    char    *dup = ft_strdup(str);
    printf("puntatore str %p --> %s\n", (void *)str, str);
    printf("puntatore dup %p --> %s\n", (void *)dup, dup);
    free(dup);
    return (0);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}