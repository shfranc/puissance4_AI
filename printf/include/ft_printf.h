/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 18:21:32 by lduval            #+#    #+#             */
/*   Updated: 2017/02/03 08:47:08 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "ft_putc.h"
# include "ft_convarg.h"
# include "pars.h"
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char *str, ...);
int		ft_test(char *str, ...);
void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
void	*ft_memalloc(size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *s);
#endif
