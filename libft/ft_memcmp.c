#include <stddef.h>

int ft_memcmp(void *s1, void *s2, size_t n)
{
    unsigned char *str1 = s1;
    unsigned char *str2 = s2;
    size_t i;

    i = 0;

    while (i < n)
    {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    return 0;
}