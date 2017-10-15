/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:21:53 by lduval            #+#    #+#             */
/*   Updated: 2016/11/19 22:01:15 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *dst;
	unsigned char *sr;
	unsigned char d;

	d = (unsigned char)c;
	dst = (unsigned char*)dest;
	sr = (unsigned char*)src;
	while (n != 0)
	{
		if ((*dst++ = *sr++) == d)
			return (dst);
		n--;
	}
	return (0);
}
