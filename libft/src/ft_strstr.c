/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:08:01 by lduval            #+#    #+#             */
/*   Updated: 2016/11/14 17:36:28 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char *cbig;
	char *clittle;
	char *tempb;
	char *templ;
	char *answer;

	cbig = (char *)big;
	clittle = (char*)little;
	answer = NULL;
	tempb = cbig;
	templ = clittle;
	while (*cbig && answer == NULL)
	{
		while (*cbig == *clittle && *cbig && *clittle)
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
