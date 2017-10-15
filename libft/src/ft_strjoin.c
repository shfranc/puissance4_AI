/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:56:02 by lduval            #+#    #+#             */
/*   Updated: 2017/03/03 06:07:54 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*answer;
	char	*canswer;
	size_t	size;

	answer = NULL;
	canswer = NULL;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup((char*)s2));
	else if (!s2)
		return (ft_strdup(((char*)s1)));
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((answer = (char*)malloc((size + 1) * sizeof(char))))
	{
		canswer = answer;
		while (*s1)
			*answer++ = *s1++;
		while (*s2)
			*answer++ = *s2++;
		*answer = '\0';
	}
	return (canswer);
}
