/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:06:25 by aceauses          #+#    #+#             */
/*   Updated: 2023/03/21 18:56:39 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	cr;

	cr = (char)c;
	while (*str != '\0')
	{
		if (*str == cr)
			return ((char *)str);
		str++;
	}
	while (cr == '\0')
		return ((char *)str);
	return (NULL);
}
