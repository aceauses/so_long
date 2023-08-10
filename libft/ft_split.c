/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:42:54 by aceauses          #+#    #+#             */
/*   Updated: 2023/04/10 17:02:29 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_words(char const *s, char set)
{
	size_t	i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == set) && s[i] != set)
			words++;
		i++;
	}
	return (words);
}

static char	*fill(char *mem, char const *s, int len, int w_len)
{
	int		i;

	i = 0;
	while (w_len > 0)
	{
		mem[i] = s[len - w_len];
		i++;
		w_len--;
	}
	mem[i] = '\0';
	return (mem);
}

static void	free_mem(char **mem)
{
	int	i;

	i = 0;
	while (mem[i])
	{
		free(mem[i]);
		i++;
	}
	free(mem);
}

static char	**for_every_word(char const *s, char c, int num, int w_len)
{
	char	**mem;
	int		len;
	int		i;

	mem = (char **)malloc(sizeof(char *) * (num + 1));
	if (!mem)
		return (NULL);
	len = 0;
	i = 0;
	while (i < num)
	{
		w_len = 0;
		while (s[len] && s[len] == c)
			len++;
		while (s[len] && s[len] != c && ++w_len)
			len++;
		mem[i] = (char *)malloc(sizeof(char) * (w_len + 1));
		if (!mem[i])
			return (free_mem(mem), NULL);
		fill(mem[i], s, len, w_len);
		i++;
	}
	return (mem[i] = NULL, mem);
}

char	**ft_split(char const *s, char c)
{
	char	**mem;
	int		num;

	if (!s)
		return (NULL);
	num = num_words(s, c);
	mem = for_every_word(s, c, num, 0);
	return (mem);
}
