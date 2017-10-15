/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 21:52:09 by lduval            #+#    #+#             */
/*   Updated: 2016/11/20 00:54:03 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			size;
	char			*c;
	char			*scopy;
	unsigned int	i;

	scopy = (char *)s;
	c = NULL;
	size = 0;
	i = 0;
	if (s && f)
	{
		size = ft_strlen(s);
		if ((c = (char*)malloc((size + 1) * sizeof(char))))
		{
			ft_strclr(c);
			while (scopy[i])
			{
				c[i] = (*f)(i, scopy[i]);
				i++;
			}
			c[i] = '\0';
		}
	}
	return (c);
}
