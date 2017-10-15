/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 08:53:49 by lduval            #+#    #+#             */
/*   Updated: 2017/02/03 08:53:51 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minlib.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	else
	{
		while (i <= size)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}
