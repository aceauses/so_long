/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:49:16 by aceauses          #+#    #+#             */
/*   Updated: 2023/04/11 15:13:45 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nnode;

	if (lst)
	{
		if (*lst)
		{
			nnode = ft_lstlast(*lst);
			nnode->next = new;
		}
		else
			*lst = new;
	}
}
