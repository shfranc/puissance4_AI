/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:20:05 by lduval            #+#    #+#             */
/*   Updated: 2016/11/15 18:01:50 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sr;
	int				i;

	i = 0;
	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (n && dst != sr)
	{
		if (dst < sr)
			dst = ft_memcpy(dest, src, n);
		else
		{
			dst += (n - 1);
			sr += (n - 1);
			i = n;
			while (i--)
				*dst-- = *sr--;
		}
	}
	return (dest);
}
