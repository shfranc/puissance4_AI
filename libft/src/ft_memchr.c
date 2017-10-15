/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:23:01 by lduval            #+#    #+#             */
/*   Updated: 2016/11/20 00:49:55 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *d;
	unsigned char cc;

	d = NULL;
	cc = (unsigned char)c;
	if (n)
	{
		d = (unsigned char*)s;
		while (--n && (cc != *d))
			d++;
	}
	else
		return (NULL);
	return (*d == cc ? d : NULL);
}
