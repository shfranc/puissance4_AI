/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convarg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:56:57 by lduval            #+#    #+#             */
/*   Updated: 2017/02/03 08:46:04 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVARG_H
# define FT_CONVARG_H
# include <stdlib.h>
# include "minlib.h"
# include <unistd.h>
# define BUFF_SIZE 1000

typedef struct			s_arg
{
	int					nb_octet;
	int					base;
	int					length;
	int					prec;
	int					left;
	char				padc;
	int					plus_sign;
	int					sign_char;
	int					conv;
	int					cap;
	unsigned long long	n;
}						t_arg;

t_arg	g_arg;
#endif
