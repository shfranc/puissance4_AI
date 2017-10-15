/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 18:21:10 by lduval            #+#    #+#             */
/*   Updated: 2017/02/05 01:39:49 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putc.h"
#include <wchar.h>

int		print_char(va_list *ap)
{
	wchar_t	c;
	char	*s;
	char	l;

	if (g_arg.nb_octet == sizeof(long))
	{
		if (!(c = (wchar_t)va_arg(*ap, wint_t)))
			print_string3(0);
		else
		{
			if (!(s = putwr(nboc(c), c)))
				return (-1);
			print_string2(s);
			free(s);
		}
	}
	else
	{
		l = (char)va_arg(*ap, int);
		print_string3(l);
	}
	return (1);
}

int		print_string(va_list *ap)
{
	char	*p1;
	wchar_t	*p2;

	p1 = NULL;
	p2 = NULL;
	if (g_arg.nb_octet == sizeof(long))
	{
		if (!(p2 = va_arg(*ap, wchar_t*)))
			print_string2(NULL);
		else
			return (print_string4(p2, 0, NULL, NULL));
	}
	else
	{
		p1 = va_arg(*ap, char *);
		print_string2(p1);
	}
	return (1);
}

int		print_string4(wchar_t *p1, int n, char *s, char *p)
{
	wchar_t	*p2;

	g_arg.prec = (g_arg.prec == -1) ? 2147483647 : g_arg.prec;
	if (g_arg.length > 0 && !g_arg.left && !(n = 0))
	{
		p2 = p1;
		while (*p1 && !((nboc(*p1) + n) > g_arg.prec))
			n += (nboc(*p1++));
		while (n < g_arg.length && ++n)
			ft_putc(g_arg.padc);
		p1 = p2;
	}
	n = 0;
	while (n < g_arg.prec && !(!(*p1) || (nboc(*p1) + n) > g_arg.prec) && ++p1)
	{
		if (!(s = putwr(nboc(*(p1 - 1)), *(p1 - 1))))
			return (-1);
		p = s;
		while (*s && ++n)
			ft_putc(*s++);
		p ? free(p) : NULL;
	}
	while (n < g_arg.length && g_arg.left && ft_putc(' '))
		n++;
	return (1);
}

void	print_string3(char c)
{
	int		n;

	if (g_arg.prec == -1)
		g_arg.prec = 2147483647;
	if (g_arg.length > 0 && !g_arg.left)
	{
		n = 1;
		while (n < g_arg.length)
		{
			ft_putc(g_arg.padc);
			n++;
		}
	}
	n = 0;
	ft_putc(c);
	n++;
	if (n < g_arg.length && g_arg.left)
	{
		while (n < g_arg.length)
		{
			ft_putc(' ');
			n++;
		}
	}
}

void	print_string2(char *p1)
{
	char	*p2;
	int		n;

	p2 = NULL;
	if (g_arg.prec == -1)
		g_arg.prec = 2147483647;
	if (p1 == NULL)
		p1 = "(null)";
	if (g_arg.length > 0 && !g_arg.left)
	{
		n = 0;
		p2 = p1;
		while (*p1++ && n < g_arg.prec)
			n++;
		p1 = p2;
		while (n++ < g_arg.length)
			ft_putc(g_arg.padc);
	}
	n = 0;
	while ((n < g_arg.prec) && *p1)
		ft_putc(*p1++) ? n++ : n;
	if (n < g_arg.length && g_arg.left)
		while (n++ < g_arg.length)
			ft_putc(' ');
}
