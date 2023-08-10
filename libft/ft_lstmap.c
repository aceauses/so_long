/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:56:09 by aceauses          #+#    #+#             */
/*   Updated: 2023/04/11 20:24:43 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_newlstnew(void *content)
{
	t_list	*nnode;

	nnode = (t_list *)malloc(sizeof(t_list));
	if (nnode == NULL)
	{
		free(content);
		return (NULL);
	}
	nnode->content = content;
	nnode->next = NULL;
	return (nnode);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nnode;
	t_list	*newp;

	nnode = NULL;
	while (lst)
	{
		newp = ft_newlstnew(f(lst->content));
		if (!newp)
		{
			ft_lstclear(&nnode, del);
			return (NULL);
		}
		ft_lstadd_back(&nnode, newp);
		lst = lst->next;
	}
	return (nnode);
}
