#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    int len;

    len = ft_strlen(s);
    if (c == '\0')
        return ((char *)s + len);
    while (--len >= 0)
    {
        if (s[len] == c)
            return ((char *)s + len);
    }
    return NULL;
}