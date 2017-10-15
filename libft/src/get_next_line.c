/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 04:55:39 by lduval            #+#    #+#             */
/*   Updated: 2017/03/03 08:38:17 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

t_list	*isfd(const int fd, t_list **tab)
{
	t_list	*temp;
	t_gl	*content;

	temp = *tab;
	while (temp)
	{
		if (((t_gl*)(temp->content))->fd == fd)
			break ;
		temp = temp->next;
	}
	if (!temp)
	{
		if (!(content = (t_gl *)malloc(sizeof(t_gl))))
			return (NULL);
		temp = ft_lstnew(content, sizeof(t_gl ));
		free(content);
		ft_lstadd(tab, temp);
		((t_gl *)(temp->content))->fd = fd;
		((t_gl *)(temp->content))->s = ft_strnew(0);
	}
	return (temp);
}

int		splitgnl(char **ln, t_list *tp, char *tm, t_list **tab)
{
	t_gl *temp;

	(void)tab;
	temp = (t_gl *)(tp->content);
	if (!tm && temp->s[0] == '\0')
	{
		return (0);
	}
	if (tm)
	{
		*ln = ft_strsub(temp->s, 0, tm - temp->s);
		temp->s = ft_strcpy(temp->s, ++tm);
	}
	else
	{
		*ln = ft_strdup(temp->s);
		temp->s = ft_strdup("\0");
	}
	return (1);
}

void	freegl(void *content, size_t size)
{
	t_gl *g;

	(void)size;
	g = (t_gl *)content;
	ft_strdel(&g->s);
	free(g);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*tab = NULL;
	t_list			*tmp;
	t_var			v;
	int				ret;

	v.tmp = NULL;
	ret = 0;
	(fd == -2 && !line) ? ft_lstdel(&tab, &freegl) : NULL;
	if (fd < 0 || !line || (read(fd, v.tmp, 0)) == -1 || BUFF_SIZE <= 0
		|| !(v.buff = (char *)malloc(BUFF_SIZE + 1)))
		return (-1);
	*line = NULL;
	tmp = isfd(fd, &tab);
	v.gnl = (t_gl *)(tmp->content);
	(v.tmp = ft_strchr((v.gnl)->s, '\n'));
	while (line && !v.tmp && (ret = read(fd, v.buff, BUFF_SIZE)) > 0)
	{
		v.buff[ret] = '\0';
		if ((v.tmp = ft_strjoin((v.gnl)->s, v.buff)))
			((v.gnl)->s) ? free((v.gnl)->s) : NULL;
		(v.gnl)->s = v.tmp;
		v.tmp = ft_strchr((v.gnl)->s, '\n');
	}
	v.buff ? free(v.buff) : NULL;
	return (ret == (-1) ? -1 : splitgnl(line, tmp, v.tmp, &tab));
}
