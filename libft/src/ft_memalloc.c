/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:48:26 by lduval            #+#    #+#             */
/*   Updated: 2016/11/20 02:06:34 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*a;

	a = NULL;
	if (size)
	{
		if ((a = malloc(size)))
			ft_memset(a, 0, size);
		else
			a = NULL;
	}
	return (a);
}
