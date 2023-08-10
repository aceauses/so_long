/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:53:48 by aceauses          #+#    #+#             */
/*   Updated: 2023/04/12 16:37:46 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	set_char(char s, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*mem;
	size_t	end;
	size_t	start;
	size_t	j;

	start = 0;
	while (s1[start] && set_char(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (set_char(s1[end - 1], set) && end > start)
		end--;
	mem = malloc(end - start + 1);
	if (!mem)
		return (NULL);
	if (!s1)
		return (NULL);
	j = 0;
	while (start < end)
		mem[j++] = s1[start++];
	mem[j] = 0;
	return (mem);
}
