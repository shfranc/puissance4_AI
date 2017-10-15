/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 02:14:08 by lduval            #+#    #+#             */
/*   Updated: 2016/11/20 02:25:51 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*copy;
	char	*scopy;
	char	*ret;
	size_t	p;

	ret = NULL;
	p = (n > ft_strlen(s)) ? ft_strlen(s) : n;
	scopy = (char *)s;
	if ((copy = (char *)malloc((p + 1) * (sizeof(*scopy)))))
	{
		ret = copy;
		while (*scopy && n--)
		{
			*copy++ = *scopy++;
		}
		*copy = '\0';
	}
	return (ret);
}
