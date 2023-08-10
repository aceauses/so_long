/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:25:55 by aceauses          #+#    #+#             */
/*   Updated: 2023/03/23 14:55:51 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	unsigned int	i;

	i = 0;
	if (to == NULL && from == NULL)
		return (NULL);
	while (i < n)
	{
		((char *)to)[i] = ((const char *)from)[i];
		i++;
	}
	return (to);
}
