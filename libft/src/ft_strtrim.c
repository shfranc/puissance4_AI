/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 03:16:47 by lduval            #+#    #+#             */
/*   Updated: 2016/11/20 00:55:45 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*scopy2;
	char	*answer;
	size_t	size;

	answer = NULL;
	scopy2 = (char *)s;
	if (!s)
		return (NULL);
	size = (int)ft_strlen(s);
	while ((ft_isblank(*s) || *s == '\n') && *s)
		s++;
	scopy2 = (scopy2 + (size - 1));
	while ((ft_isblank(*scopy2) || *scopy2 == '\n') && (s != scopy2))
		scopy2--;
	if (ft_strlen(s) == 0)
	{
		if ((answer = (char *)malloc(1 * sizeof(char))))
			answer[0] = '\0';
		return (answer);
	}
	size = ++scopy2 - s;
	answer = ft_strsub(s, 0, size);
	return (answer);
}
