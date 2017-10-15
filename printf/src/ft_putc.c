/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 19:23:36 by lduval            #+#    #+#             */
/*   Updated: 2017/02/05 01:40:02 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putc.h"

int		nboc(unsigned int nbr)
{
	int		i;

	i = 1;
	if (nbr > 1114111)
		return (-1);
	while ((nbr = nbr >> 1))
		i++;
	if (i > 7)
	{
		if (i > 11)
		{
			if (i > 16)
			{
				if (i > 21)
					return (-1);
				return (4);
			}
			return (3);
		}
		return (2);
	}
	return (1);
}

char	*putwr(int n, wchar_t ch)
{
	int				i;
	char			*buf;

	i = 0;
	if (n == -1)
		return (NULL);
	buf = ft_strnew(5);
	if (n > 1)
	{
		if (n > 2)
		{
			if (n > 3 && (buf[i++] = ((ch >> 18) & 7) | 240))
				buf[i++] = ((ch >> 12) & 63) | 128;
			else
				buf[i++] = ((ch >> 12) & 15) | 224;
			buf[i++] = ((ch >> 6) & 63) | 128;
		}
		else
			buf[i++] = ((ch >> 6) & 31) | 192;
		buf[i++] = (ch & 63) | 128;
	}
	buf[i] = (n == 1) ? ch : buf[i];
	return (buf);
}

void	print_unsigned(va_list *ap)
{
	unsigned long long nb;

	nb = 0;
	if (g_arg.nb_octet == sizeof(long long))
		nb = va_arg(*ap, unsigned long long);
	else if (g_arg.nb_octet == sizeof(long))
		nb = va_arg(*ap, unsigned long);
	else if (g_arg.nb_octet == sizeof(short))
		nb = (unsigned short)va_arg(*ap, unsigned int);
	else if (g_arg.nb_octet == sizeof(char))
		nb = (unsigned char)va_arg(*ap, unsigned int);
	else
		nb = va_arg(*ap, unsigned int);
	printnum(nb);
}

void	print_signed(va_list *ap)
{
	long long			n;
	unsigned long long	nb;

	nb = 0;
	n = 0;
	if (g_arg.nb_octet == sizeof(long long))
		n = va_arg(*ap, long long);
	else if (g_arg.nb_octet == sizeof(long))
		n = va_arg(*ap, unsigned long);
	else if (g_arg.nb_octet == sizeof(short))
		n = (short)va_arg(*ap, unsigned int);
	else if (g_arg.nb_octet == sizeof(char))
		n = (char)va_arg(*ap, unsigned int);
	else
		n = va_arg(*ap, int);
	if (n >= 0)
	{
		g_arg.sign_char = g_arg.plus_sign;
		nb = n;
	}
	else if ((g_arg.sign_char = '-'))
		nb = -n;
	printnum(nb);
}

int		ft_putc(char c)
{
	if (g_nb != 0 && (g_nb) % BUFF_SIZE == 0)
	{
		write(1, g_buff, BUFF_SIZE);
		ft_bzero(g_buff, BUFF_SIZE);
	}
	g_buff[g_nb % BUFF_SIZE] = c;
	(g_nb)++;
	return (1);
}
