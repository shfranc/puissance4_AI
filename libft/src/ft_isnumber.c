/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <lduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 05:30:08 by lduval            #+#    #+#             */
/*   Updated: 2017/03/02 14:17:50 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(char *str)
{
	if ((*str == '-') || (*str == '+'))
		str++;
	while (*str)
		if (!(ft_isdigit(*str++)))
			return (0);
	return (1);
}
