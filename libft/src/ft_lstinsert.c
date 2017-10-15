/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <lduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:55:31 by lduval            #+#    #+#             */
/*   Updated: 2017/03/05 08:11:19 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **alst, t_list *new, int (*f)(t_list *, t_list *))
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp2 = NULL;
	tmp3 = NULL;
	if (!alst || !new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp && (*f)(new, tmp))
	{
		tmp3 = tmp2;
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (!tmp2)
		*alst = new;
	else
		tmp2->next = new;
	new->next = tmp;
}
