/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:17:48 by lduval            #+#    #+#             */
/*   Updated: 2016/11/14 14:21:14 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char findc;
	char *copys;

	findc = (char)c;
	copys = (char *)s;
	while (*copys && (*copys != findc))
		copys++;
	return (*copys == findc ? copys : NULL);
}
