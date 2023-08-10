/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:54:05 by aceauses          #+#    #+#             */
/*   Updated: 2023/04/03 11:46:13 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr_big;
	char	*ptr_l;

	ptr_big = (char *)big;
	ptr_l = (char *)little;
	i = 0;
	if (*little == '\0')
		return (ptr_big);
	while (i < len && ptr_big[i])
	{
		if (ptr_big[i] == ptr_l[0])
		{
			j = 0;
			while (ptr_l[j] && (i + j) < len && ptr_big[i + j] == ptr_l[j])
				j++;
			if (ptr_l[j] == '\0')
				return ((char *)(ptr_big + i));
		}
		i++;
	}
	return (NULL);
}
