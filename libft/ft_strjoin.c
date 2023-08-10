/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:01:17 by aceauses          #+#    #+#             */
/*   Updated: 2023/04/11 14:42:48 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	int		x;
	int		i;

	mem = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!mem)
		return (NULL);
	i = 0;
	x = 0;
	while (s1[i])
	{
		mem[i] = s1[i];
		i++;
	}
	while (s2[x])
	{
		mem[i + x] = s2[x];
		x++;
	}
	mem[i + x] = '\0';
	return (mem);
}
