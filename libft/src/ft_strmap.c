/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 21:17:16 by lduval            #+#    #+#             */
/*   Updated: 2016/11/20 00:53:29 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	char	*c;
	char	*scopy;
	char	*ccopy;

	scopy = (char *)s;
	c = NULL;
	ccopy = NULL;
	size = 0;
	if (s && f)
	{
		size = ft_strlen(s);
		if ((c = (char*)malloc((size + 1) * sizeof(char))))
		{
			ccopy = c;
			ft_strclr(c);
			while (*scopy)
				*c++ = (*f)(*scopy++);
			*c = '\0';
		}
	}
	return (ccopy);
}
