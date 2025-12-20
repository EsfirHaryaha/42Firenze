#include <stdlib.h>
#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *tmp;

    if (!lst || !del)
        return;

    while (*lst)
    {
        tmp = (*lst)->next;     // salva il prossimo nodo
        del((*lst)->content);   // libera il contenuto
        free(*lst);             // libera il nodo
        *lst = tmp;             // passa al nodo successivo
    }
    *lst = NULL;                // lista completamente cancellata
}
