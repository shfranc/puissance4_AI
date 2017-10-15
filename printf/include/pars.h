/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:03:27 by lduval            #+#    #+#             */
/*   Updated: 2017/02/03 09:18:13 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARS_H
# define FT_PARS_H
# include "ft_convarg.h"
# include "ft_putc.h"

int		pars(char **str);
int		pars_second(char **str, char c);
int		pars_third(char **str, char c);
int		pars_foor(char **str);
int		pars_five(char **str, char c);
#endif
