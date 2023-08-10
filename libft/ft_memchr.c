/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:45:20 by aceauses          #+#    #+#             */
/*   Updated: 2023/04/11 16:53:25 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr_str;

	ptr_str = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (ptr_str[i] == (unsigned char)c)
			return (ptr_str + i);
		i++;
	}
	return (NULL);
}
