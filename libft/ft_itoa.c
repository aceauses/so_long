/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceauses <aceauses@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:27:17 by aceauses          #+#    #+#             */
/*   Updated: 2023/04/11 15:04:25 by aceauses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	int	digits;

	digits = 0;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static int	get_lngth(int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i = 1;
	}
	if (n == -2147483648)
	{
		return (10);
	}
	while (n != 0)
	{
		n /= 10;
		i += 1;
	}
	return (i);
}

static int	fill(char *s, int n, int d_count, int extra)
{
	while (d_count--)
	{
		s[d_count + extra] = n % 10 + '0';
		n /= 10;
	}
	return (*s);
}

static int	fill_min(char *s)
{
	s[1] = '2';
	s[2] = '1';
	s[3] = '4';
	s[4] = '7';
	s[5] = '4';
	s[6] = '8';
	s[7] = '3';
	s[8] = '6';
	s[9] = '4';
	s[10] = '8';
	return (*s);
}

char	*ft_itoa(int n)
{
	char	*mem;
	int		d_count;
	int		sign;

	d_count = digit_count(n);
	sign = (n < 0);
	mem = ft_calloc(((get_lngth(n) + sign) + 1), sizeof(*mem));
	if (!mem)
		return (NULL);
	else if (n < 0)
	{
		n = (n * -1);
		mem[0] = '-';
		if (n == -2147483648)
		{
			*mem = fill_min(mem);
			return (mem);
		}
		fill(mem, n, d_count, 1);
	}
	else if (n == 0)
		mem[d_count] = '0';
	else if (n > 0)
		fill(mem, n, d_count, 0);
	return (mem);
}
