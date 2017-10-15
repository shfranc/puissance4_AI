/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:56:31 by lduval            #+#    #+#             */
/*   Updated: 2017/02/05 01:37:55 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initarg(void)
{
	g_arg.nb_octet = 0;
	g_arg.base = 0;
	g_arg.length = 0;
	g_arg.prec = -1;
	g_arg.left = 0;
	g_arg.padc = 0;
	g_arg.plus_sign = 0;
	g_arg.sign_char = 0;
	g_arg.conv = 0;
	g_arg.cap = 0;
	g_arg.n = 0;
}

int			ft_printf(char *str, ...)
{
	int		cnt;
	va_list ap;
	int		b;

	b = 1;
	!(g_nb = 0) ? va_start(ap, str) : NULL;
	while (*str != '\0' && b)
		if (*str == '%')
		{
			initarg();
			cnt = pars(&str);
			cnt == 0 ? print_signed(&ap) : NULL;
			cnt == 1 ? print_unsigned(&ap) : NULL;
			b = cnt == 2 && print_string(&ap) == -1 ? 0 : 1;
			b = cnt == 3 && print_char(&ap) == -1 ? 0 : b;
			cnt == 4 && (*str) != 0 ? print_string3(*str) : NULL;
			*str != 0 && cnt == 4 ? str++ : str;
		}
		else if (ft_putc(*str))
			++str;
	b ? write(1, g_buff, g_nb % BUFF_SIZE) : (ssize_t)b;
	va_end(ap);
	return (b ? g_nb : -1);
}
