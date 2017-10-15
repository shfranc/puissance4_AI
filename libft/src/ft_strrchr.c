/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:10:44 by lduval            #+#    #+#             */
/*   Updated: 2016/11/14 14:11:38 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char findc;
	char *copys;
	char *answer;

	findc = (char)c;
	copys = (char *)s;
	answer = NULL;
	while (*copys)
	{
		if (*copys == findc)
			answer = copys;
		copys++;
	}
	if (findc == '\0')
		answer = copys;
	return (answer);
}
