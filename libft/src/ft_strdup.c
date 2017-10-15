/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:15:09 by lduval            #+#    #+#             */
/*   Updated: 2016/11/20 00:51:08 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *copy;
	char *scopy;
	char *ret;

	ret = NULL;
	scopy = (char *)s;
	if ((copy = (char *)malloc((ft_strlen(s) + 1) * (sizeof(*scopy)))))
	{
		ret = copy;
		while (*scopy)
		{
			*copy++ = *scopy++;
		}
		*copy = '\0';
	}
	return (ret);
}
