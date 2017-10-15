/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:19:31 by lduval            #+#    #+#             */
/*   Updated: 2016/11/20 00:54:23 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	if ((a = (char *)malloc((size + 1) * sizeof(char))))
	{
		while (i < size + 1)
		{
			a[i] = '\0';
			++i;
		}
	}
	else
		a = NULL;
	return (a);
}
