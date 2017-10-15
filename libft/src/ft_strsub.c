/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 22:41:44 by lduval            #+#    #+#             */
/*   Updated: 2016/11/20 00:54:58 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*copys;
	size_t	i;

	i = 0;
	copys = NULL;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if ((size_t)start + len <= size)
	{
		if ((copys = (char *)malloc((len + 1) * sizeof(char))))
		{
			while (i < len)
			{
				copys[i] = s[start + i];
				i++;
			}
			copys[i] = '\0';
		}
	}
	return (copys);
}
