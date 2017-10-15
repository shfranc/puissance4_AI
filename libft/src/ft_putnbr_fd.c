/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 08:41:51 by lduval            #+#    #+#             */
/*   Updated: 2016/11/18 08:47:52 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int nbr[3];

	nbr[1] = n;
	nbr[0] = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd(50, fd);
			nbr[1] = 147483648;
		}
		else
			nbr[1] = -n;
	}
	nbr[2] = nbr[1];
	while ((nbr[2] /= 10) > 0)
		nbr[0] = nbr[0] * 10;
	nbr[2] = nbr[1];
	while (nbr[0] > 0)
	{
		ft_putchar_fd((nbr[2] / nbr[0]) + 48, fd);
		nbr[2] %= nbr[0];
		nbr[0] /= 10;
	}
}
