
#include <stddef.h>

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char   *d = dest;
    const unsigned char     *s = src;

    if (d == s)
        return dest;
    
    if (d < s)
    {
        while (n--)
            *d++ = *s++;
    }
    else
    {
        d = d + n;
        s = s + n;

        while(n--)
        {
            *--d = *--s;
        }
    }
    return dest;
}
