/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 00:02:14 by lduval            #+#    #+#             */
/*   Updated: 2017/02/06 20:28:41 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1024

int					get_next_line(const int fd, char **line);

typedef struct		s_gl
{
	char			*s;
	int				fd;
}					t_gl;

typedef struct		s_var
{
	char			*buff;
	char			*tmp;
	t_gl			*gnl;
}					t_var;

#endif
