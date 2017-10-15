/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:30:43 by lduval            #+#    #+#             */
/*   Updated: 2016/11/14 17:24:50 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	char d;

	d = (char)c;
	return ((int)(d == '\f' || d == '\n' ||
				d == '\r' || d == '\t' || d == '\v' || d == ' '));
}
