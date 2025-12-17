#include <stddef.h>
#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dsize)
{
    size_t ds = ft_strlen(dst);
    size_t i = 0;
    if (ds < dsize)
    {
        while (ds + i < dsize - 1 && src[i] != '\0')
        {
            dst[ds + i] = src[i];
            i++;
        }
        dst[ds+i] = '\0'; 
    }
    return (ds  + ft_strlen(src));
}