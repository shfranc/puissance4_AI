/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:04:48 by lduval            #+#    #+#             */
/*   Updated: 2016/11/19 22:31:01 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *tempsrc;
	t_list *tempresult;

	tempsrc = lst;
	result = NULL;
	tempresult = NULL;
	if (!lst || !f)
		return (NULL);
	if ((result = (*f)(lst)))
	{
		tempresult = result;
		while (tempsrc->next)
		{
			tempsrc = tempsrc->next;
			if (!(tempresult->next = (*f)(tempsrc)))
				return (NULL);
			tempresult = tempresult->next;
		}
		tempresult->next = NULL;
	}
	return (result);
}
