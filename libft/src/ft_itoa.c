/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 04:37:54 by lduval            #+#    #+#             */
/*   Updated: 2016/11/20 00:56:42 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		fill_a(char *p, int n, size_t size)
{
	p = p + size;
	*p = '\0';
	if (n == 0)
		*(p - 1) = '0';
	else if (n > 0)
	{
		while (n != 0)
		{
			*--p = '0' + (n % 10);
			n /= 10;
		}
	}
	else
	{
		while (n != 0)
		{
			*--p = '0' - (n % 10);
			n /= 10;
		}
		*--p = '-';
	}
}

static size_t	count_int(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		++i;
		n = -n;
	}
	while ((n /= 10) > 0)
		i++;
	return (i + 1);
}

char			*ft_itoa(int n)
{
	char	*p;
	size_t	size;

	if (n == -2147483648)
	{
		size = 11;
	}
	else
		size = count_int(n);
	if ((p = (char *)malloc((size + 1) * sizeof(char))))
		fill_a(p, n, size);
	return (p);
}
