/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:39:33 by aceauses          #+#    #+#             */
/*   Updated: 2023/04/10 11:40:53 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nnode;

	if (lst)
	{
		while (*lst)
		{
			nnode = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = nnode;
		}
	}
}
