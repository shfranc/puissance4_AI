/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:23:43 by lduval            #+#    #+#             */
/*   Updated: 2016/11/14 17:27:39 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *sr;
	unsigned char *dst;

	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	while (n--)
		*dst++ = *sr++;
	return (dest);
}
