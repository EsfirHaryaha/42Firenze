#include <stddef.h>

void    *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char   *str = s;
    size_t i;

    i = 0;
    while (i < n)
    {
        if (str[i] == c)
            return ((void *)s + i);
        i++;
    }
    return NULL;
}