/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:13:21 by lduval            #+#    #+#             */
/*   Updated: 2016/11/15 18:01:27 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*cops1;
	char	*cops2;
	size_t	i;

	i = 0;
	cops1 = (char *)s1;
	cops2 = (char *)s2;
	while (*cops1 && *cops2 && (*cops1 == *cops2) && (++i < n))
	{
		++cops1;
		++cops2;
	}
	return (n != 0 ? ((unsigned char)*cops1 - (unsigned char)*cops2) : 0);
}
