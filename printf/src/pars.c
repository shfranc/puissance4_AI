/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:04:50 by lduval            #+#    #+#             */
/*   Updated: 2017/02/03 09:25:54 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

int		pars(char **str)
{
	char	c;

	while (1)
	{
		(*str)++;
		c = **str;
		if (c == '#')
			g_arg.conv = 1;
		else if (c == '-')
			g_arg.left = 1;
		else if (c == '+')
			g_arg.plus_sign = '+';
		else if (c == ' ')
		{
			if (g_arg.plus_sign == 0)
				g_arg.plus_sign = ' ';
		}
		else if (c == '0')
			g_arg.padc = '0';
		else
			break ;
	}
	return (pars_second(str, c));
}

int		pars_second(char **str, char c)
{
	if (ft_isdigit(c))
	{
		while (ft_isdigit(c))
		{
			g_arg.length = 10 * g_arg.length + ((int)c - 48);
			c = *(++(*str));
		}
		g_arg.padc = (g_arg.padc == 0) ? ' ' : g_arg.padc;
	}
	if (c == '.')
	{
		g_arg.prec = 0;
		c = *(++(*str));
		if (ft_isdigit(c))
		{
			while (ft_isdigit(c))
			{
				g_arg.prec = 10 * g_arg.prec + ((int)c - 48);
				c = *(++(*str));
			}
		}
		if (g_arg.padc == '0' && g_arg.prec != 0)
			g_arg.padc = ' ';
	}
	return (pars_third(str, c));
}

int		pars_third(char **str, char c)
{
	if (c == 'l')
	{
		c = *(++(*str));
		if (c == 'l' && (g_arg.nb_octet = sizeof(long long)))
			c = *(++(*str));
		else
			g_arg.nb_octet = sizeof(long);
	}
	else if ((c == 'L' || c == 'z') && (g_arg.nb_octet = sizeof(long long)))
		c = *(++(*str));
	else if (c == 'h')
	{
		c = *(++(*str));
		if (c == 'h' && (g_arg.nb_octet = sizeof(char)))
			c = *(++(*str));
		else
			g_arg.nb_octet = sizeof(short int);
	}
	else if (c == 'j' && (g_arg.nb_octet = sizeof(long long)))
		c = *(++(*str));
	if (c != 0)
		while (ft_strchr("lLzhj", c))
			c = *(++(*str));
	return (pars_foor(str));
}

int		pars_foor(char **str)
{
	char c;

	c = *((*str)++);
	if (ft_strchr("dDioOuUxX", c) && (g_arg.padc == '0' && g_arg.prec != -1))
		g_arg.padc = ' ';
	if (c == 'c')
		return (3);
	if (c == 'C' && (g_arg.nb_octet = sizeof(long)))
		return (3);
	else if (c == 'S' && (g_arg.nb_octet = sizeof(long)))
		return (2);
	else if (c == 's')
		return (2);
	if (c == 'o' && (g_arg.base = 8))
		return (1);
	if (c == 'O' && (g_arg.nb_octet = sizeof(long)))
		return ((g_arg.base = 8) ? 1 : 0);
	if (c == 'D' && (g_arg.nb_octet = sizeof(long)))
	{
		g_arg.base = 10;
		return (0);
	}
	return (pars_five(str, c));
}

int		pars_five(char **str, char c)
{
	if ((c == 'd' || c == 'i') && (g_arg.base = 10))
		return (0);
	if (c == 'u' && (g_arg.base = 10))
		return (1);
	if (c == 'U' && (g_arg.nb_octet = sizeof(long)))
	{
		g_arg.base = 10;
		return (1);
	}
	if (c == 'X' && (g_arg.base = 16))
	{
		g_arg.cap = 1;
		return (1);
	}
	if (c == 'p' && (g_arg.nb_octet = sizeof(long)))
		if ((g_arg.conv = 2))
			c = 'x';
	if (c == 'x')
	{
		g_arg.base = 16;
		g_arg.cap = 0;
		return (1);
	}
	(*str)--;
	return (4);
}
