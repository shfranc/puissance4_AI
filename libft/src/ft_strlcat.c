/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:14:07 by lduval            #+#    #+#             */
/*   Updated: 2016/11/19 20:37:52 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	n;
	char	*copyd;
	char	*copys;

	n = dstsize;
	copyd = dst;
	copys = (char *)src;
	while (*copyd && n--)
		copyd++;
	dlen = copyd - dst;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(copys));
	while (*copys)
	{
		if (n != 1)
		{
			*copyd++ = *copys;
			n--;
		}
		copys++;
	}
	*copyd = '\0';
	return (dlen + (copys - src));
}
