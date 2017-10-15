/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:09:01 by lduval            #+#    #+#             */
/*   Updated: 2016/11/19 22:51:18 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *littl, size_t len)
{
	char *cbig;
	char *clittle;
	char *tempb;
	char *templ;
	char *answer;

	cbig = (char *)big;
	clittle = (char*)littl;
	answer = NULL;
	tempb = cbig;
	templ = clittle;
	while (*cbig && answer == NULL && ((cbig - big) < (long)len))
	{
		while (*cbig == *clittle && *cbig && *clittle && cbig - big < (long)len)
		{
			++cbig;
			++clittle;
		}
		if (*clittle == '\0')
			answer = tempb;
		++tempb;
		clittle = templ;
		cbig = tempb;
	}
	return ((ft_strlen(clittle) == 0) ? (char *)big : answer);
}
