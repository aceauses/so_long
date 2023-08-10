/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:09:09 by aceauses          #+#    #+#             */
/*   Updated: 2023/04/11 16:52:54 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t len)
{
	char	*ptr_to;
	char	*ptr_from;

	ptr_to = (char *)to;
	ptr_from = (char *)from;
	if (to == NULL && from == NULL)
	{
		return (NULL);
	}
	if (ptr_to > ptr_from)
	{
		while (len--)
			ptr_to[len] = ptr_from[len];
	}
	else
	{
		while (len--)
			*ptr_to++ = *ptr_from++;
	}
	return (to);
}
