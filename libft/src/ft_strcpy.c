/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:17:26 by lduval            #+#    #+#             */
/*   Updated: 2016/11/14 15:36:01 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char *cpy;
	char *cps;

	cpy = dest;
	cps = (char *)src;
	while (*cps)
		*cpy++ = *cps++;
	*cpy = '\0';
	return (dest);
}
