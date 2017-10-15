/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:22:14 by lduval            #+#    #+#             */
/*   Updated: 2016/11/14 14:22:36 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *copys1;
	unsigned char *copys2;

	copys1 = (unsigned char*)s1;
	copys2 = (unsigned char*)s2;
	if (n)
	{
		while (--n && (*copys1 == *copys2))
		{
			++copys1;
			++copys2;
		}
	}
	else
		return (0);
	return (int)(*copys1 - *copys2);
}
