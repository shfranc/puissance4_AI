/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:13:00 by lduval            #+#    #+#             */
/*   Updated: 2016/11/14 14:13:07 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *cpy;
	char *cps;

	cpy = dest;
	cps = (char *)src;
	while (*cps && ((cpy - dest) < (long)n))
		*cpy++ = *cps++;
	while ((cpy - dest) < (long)n)
		*cpy++ = '\0';
	return (dest);
}
