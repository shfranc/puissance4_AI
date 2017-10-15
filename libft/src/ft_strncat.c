/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:13:49 by lduval            #+#    #+#             */
/*   Updated: 2016/11/14 14:13:59 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *copyd;
	char *copys;

	copyd = dest;
	copys = (char *)src;
	while (*copyd)
		copyd++;
	while (*copys && (copys - src) < (long)n)
		*copyd++ = *copys++;
	*copyd = '\0';
	return (dest);
}
