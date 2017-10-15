/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:51:49 by lduval            #+#    #+#             */
/*   Updated: 2017/01/30 19:51:51 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minlib.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_c;

	i = 0;
	c_c = (char)c;
	if (c_c == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)s + i);
	}
	else
	{
		while (s[i] != c_c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (NULL);
	}
	return ((char *)s + i);
}
