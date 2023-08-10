/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:49:49 by aceauses          #+#    #+#             */
/*   Updated: 2023/04/08 12:40:47 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*memory;
	size_t	i;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		memory = malloc(1);
		if (!memory)
			return (NULL);
		memory[0] = '\0';
		return (memory);
	}
	memory = malloc(len + 1);
	if (!memory)
		return (NULL);
	i = 0;
	while (i++ < start)
		s++;
	ft_strlcpy(memory, s, len + 1);
	return (memory);
}
