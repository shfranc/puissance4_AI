/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:01:51 by lduval            #+#    #+#             */
/*   Updated: 2017/02/05 01:08:31 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTC_H
# define FT_PUTC_H
# include "ft_convarg.h"
# include <stdarg.h>
# include <wchar.h>

int		nboc(unsigned int nbr);
char	*putwr(int n, wchar_t ch);
int		g_nb;
char	g_buff[BUFF_SIZE];
int		print_char(va_list *ap);
int		print_string(va_list *ap);
void	print_unsigned(va_list *ap);
void	print_signed(va_list *ap);
void	printnum(unsigned long long nb);
int		ft_putc(char c);
int		print_string4(wchar_t *p1, int n, char *s, char *p);
void	print_string2(char *s);
void	print_string3(char s);
#endif
