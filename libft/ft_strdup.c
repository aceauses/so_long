/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:26:43 by aceauses          #+#    #+#             */
/*   Updated: 2023/04/12 13:51:12 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*memory;
	size_t	l;
	size_t	i;

	l = ft_strlen(str);
	memory = (char *)malloc(l + 1);
	if (str == NULL)
	{
		return (memory);
	}
	if (memory == NULL)
		return (0);
	i = 0;
	while (i < l)
	{
		memory[i] = str[i];
		i++;
	}
	memory[i] = '\0';
	return (memory);
}
