/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharyaha <eharyaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:30:10 by eharyaha          #+#    #+#             */
/*   Updated: 2025/12/20 19:11:54 by eharyaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_list	*create_and_link_node(t_list **new_list,
					t_list **last,
					void *content, void *(*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*last;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	last = NULL;
	while (lst)
	{
		if (!create_and_link_node(&new_list, &last, lst->content, f))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new_list);
}

static t_list	*create_and_link_node(t_list **new_list, t_list **last,
			void *content, void *(*f)(void *))
{
	t_list	*new_node;
	void	*new_content;

	new_content = f(content);
	new_node = ft_lstnew(new_content);
	if (!new_node)
	{
		free(new_content);
		return (NULL);
	}
	if (!*new_list)
		*new_list = new_node;
	else
		(*last)->next = new_node;
	*last = new_node;
	return (new_node);
}
