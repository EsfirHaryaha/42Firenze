#include "libft.h"
#include <stdlib.h>

char    *ft_strjoin(char const *s1, char const *s2)
{
    int len;
    char *ptr;

    if (!s1 || !s2)
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2);
    ptr = malloc(len + 1);
    if (!ptr)
        return NULL;
    ft_memmove(ptr, s1, ft_strlen(s1));
    ft_memmove(ptr + ft_strlen(s1), s2, ft_strlen(s2));
    ptr[len] = '\0';
    return (ptr);
}