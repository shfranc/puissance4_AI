/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:16:22 by lduval            #+#    #+#             */
/*   Updated: 2016/11/14 16:58:18 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	char *cops1;
	char *cops2;

	cops1 = (char *)s1;
	cops2 = (char *)s2;
	while (*cops1 && *cops2 && (*cops1 == *cops2))
	{
		++cops1;
		++cops2;
	}
	return ((int)((unsigned char)*cops1 - (unsigned char)*cops2));
}
