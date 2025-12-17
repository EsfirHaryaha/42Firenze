#include <stddef.h>
#include "libft.h"

char    *ft_strnstr(char *big, char *little, size_t len)
{
    size_t  i;
    size_t  j;
    size_t  little_len;

    i = 0;
    little_len = ft_strlen(little);
    if (little_len == 0)
        return (big);
    while (big[i] != '\0' && i < len)
    {
        j = 0;
        while (j < little_len
            && i + j < len
            && big[i + j] == little[j])
            j++;
        if (j == little_len)
            return (big + i);
        i++;
    }
    return (NULL);
}
