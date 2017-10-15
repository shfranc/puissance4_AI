/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:45:31 by lduval            #+#    #+#             */
/*   Updated: 2017/02/03 08:50:43 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINLIB_H
# define MINLIB_H
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
