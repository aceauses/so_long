/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:33:12 by aceauses          #+#    #+#             */
/*   Updated: 2023/03/29 10:01:11 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*p_ptr1;
	unsigned char	*p_ptr2;
	unsigned int	i;

	p_ptr1 = (unsigned char *)ptr1;
	p_ptr2 = (unsigned char *)ptr2;
	i = 0;
	while (i < num)
	{
		if (p_ptr1[i] != p_ptr2[i])
			return (p_ptr1[i] - p_ptr2[i]);
		i++;
	}
	return (0);
}
