/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 18:34:39 by lduval            #+#    #+#             */
/*   Updated: 2017/02/04 18:34:57 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putc.h"
#include <wchar.h>

static char	*doprefix(unsigned long long nb)
{
	char		*prefix;

	prefix = ft_strnew(3);
	if ((g_arg.conv && (!(nb == 0 && g_arg.base == 16))) || g_arg.conv == 2)
	{
		prefix[0] = '0';
		if (g_arg.base == 8)
			prefix[1] = '\0';
		else if (g_arg.base == 16)
		{
			prefix[1] = g_arg.cap ? 'X' : 'x';
			prefix[2] = '\0';
		}
	}
	return (prefix);
}

static void	printnum2(int l, char *p, char *prefix)
{
	char *pref;

	pref = prefix;
	if (g_arg.padc == ' ' && !g_arg.left)
		while (--(g_arg.length) >= 0)
			ft_putc(' ');
	if (*prefix)
		while (*prefix)
			ft_putc(*prefix++);
	if (g_arg.sign_char)
		ft_putc(g_arg.sign_char);
	if (g_arg.padc == '0' && !g_arg.left)
		while (--(g_arg.length) >= 0)
			ft_putc(g_arg.padc);
	while (g_arg.prec-- > l)
		ft_putc('0') ? --(g_arg.length) : g_arg.length;
	while (*(++p) && (*p -= g_arg.cap && ft_isalpha(*p) ? 32 : 0))
		ft_putc(*p);
	if (g_arg.left)
		while (--(g_arg.length) >= 0)
			ft_putc(' ');
	free(pref);
}

static void	itoa_inchar(char **p1, unsigned long long nb)
{
	char		*p;
	static char digits[] = "0123456789abcdef";

	p = *p1;
	while (nb != 0)
	{
		*p = digits[(nb % (g_arg.base))];
		nb /= g_arg.base;
		p--;
	}
	*p1 = p;
}

void		printnum(unsigned long long nb)
{
	char	*prefix;
	char	buf[25];
	char	*p;
	int		l;

	p = &(buf[23]);
	buf[24] = '\0';
	prefix = doprefix(nb);
	g_arg.prec -= g_arg.base == 8 ? ft_strlen(prefix) : 0;
	if (nb == 0 && !(g_arg.base == 8 && g_arg.conv == 1))
		if ((g_arg.length) > 0 || g_arg.prec == -1)
		{
			*p = g_arg.prec == 0 ? ' ' : '0';
			p--;
		}
	itoa_inchar(&p, nb);
	if ((l = &buf[23] - p) > g_arg.prec || g_arg.left)
		g_arg.length -= ((&buf[23] - p));
	else
		g_arg.length -= g_arg.prec;
	if (g_arg.sign_char)
		g_arg.length--;
	if (*prefix)
		g_arg.length -= ft_strlen(prefix);
	printnum2(l, p, prefix);
}
