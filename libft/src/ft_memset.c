/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:21:53 by lduval            #+#    #+#             */
/*   Updated: 2016/11/14 14:22:03 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *d;
	unsigned char cc;

	cc = (unsigned char)c;
	if (n)
	{
		d = (unsigned char*)s;
		++n;
		while (--n)
			*d++ = cc;
	}
	return (s);
}
