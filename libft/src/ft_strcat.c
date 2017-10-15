/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:21:32 by lduval            #+#    #+#             */
/*   Updated: 2016/11/14 14:21:40 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *copyd;
	char *copys;

	copyd = dest;
	copys = (char *)src;
	while (*copyd)
		copyd++;
	while (*copys)
		*copyd++ = *copys++;
	*copyd = '\0';
	return (dest);
}
