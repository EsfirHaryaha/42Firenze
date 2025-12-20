#include <stdlib.h>
#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (!lst || !del)
        return;
    del(lst->content); // libero il contenuto
    free(lst);         // libero il nodo
}
