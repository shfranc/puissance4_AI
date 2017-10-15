/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:52:51 by lduval            #+#    #+#             */
/*   Updated: 2017/01/30 19:52:53 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minlib.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*ptr;
	int		*i_ptr;

	i = 0;
	ptr = malloc(size);
	i_ptr = (int *)ptr;
	if (ptr == NULL)
		return (NULL);
	else
	{
		while (i < size)
		{
			i_ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}
