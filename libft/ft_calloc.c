#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void    *ft_calloc(size_t n, size_t size)
{
    if (size != 0 && n > SIZE_MAX / size)
        return (NULL);
    if (n == 0 || size == 0)
        return (malloc(1));
    void *ptr = malloc(n * size);
    if (!ptr)
        return (NULL);
    ft_memset(ptr, 0, n * size);
    return (ptr);
}