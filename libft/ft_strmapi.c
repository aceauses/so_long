/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:13:51 by aceauses          #+#    #+#             */
/*   Updated: 2023/04/03 11:50:06 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mem;
	unsigned int	i;

	if (!s)
		return (NULL);
	mem = malloc(ft_strlen(s) + 1);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mem[i] = f(i, *(s + i));
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
