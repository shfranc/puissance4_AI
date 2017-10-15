/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:15:41 by lduval            #+#    #+#             */
/*   Updated: 2016/11/20 00:57:12 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = NULL;
	if ((list = (t_list *)malloc(sizeof(t_list))))
	{
		if (content)
		{
			if ((list->content = ft_memalloc(content_size)))
			{
				ft_memcpy(list->content, content, content_size);
				list->content_size = content_size;
			}
		}
		else
		{
			list->content = NULL;
			list->content_size = 0;
		}
		list->next = NULL;
	}
	return (list);
}
