/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <lduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 02:14:38 by lduval            #+#    #+#             */
/*   Updated: 2017/03/05 21:08:09 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		bestscor(t_list *l1, t_list *l2)
{
	t_vect	*v1;
	t_vect	*v2;

	v1 = (t_vect *)(l1->content);
	v2 = (t_vect *)(l2->content);
	return (v1->score > v2->score);
}

int		get_solution(t_list *l, int diff)
{
	int i;

	i = ft_lstlen(l);
	ft_putnbr(i);
	if (diff == 3)
		i += 0;
	if (diff == 2)
		i /= 2;
	if (diff == 1)
		i /= 3;
	while (l->next && i)
	{
		l = l->next;
		i--;
	}
	return (((t_vect *)l->content)->pos + 1);
}

void	freevect(void *content, size_t content_size)
{
	t_vect *c;

	c = (t_vect *)content;
	free(c);
	(void)content_size;
}

int		get_iaput(void)
{
	int		i;
	t_vect	*v;
	t_cfour *c;
	t_list	*l;

	c = get_cfour();
	i = 0;
	!(v = (t_vect *)malloc(sizeof(t_vect))) ?
		ft_error("Unable to malloc", &free_cfour) : NULL;
	while (i < c->x)
	{
		v->pos = i;
		v->score = grade(i, c->ia_char);
		!(l = ft_lstnew(v, sizeof(t_vect))) ?
			ft_error("Unable to malloc", &free_cfour) : NULL;
		ft_lstinsert(&c->list, l, &bestscor);
		i++;
	}
	i = get_solution(c->list, c->diff);
	if (c->list)
		ft_lstdel(&c->list, &freevect);
	free(v);
	return (i);
}

int		manage_player(int (*p1)(void), int (*p2)(void))
{
	int		i;
	int		j;
	int		y;
	int		x;
	t_cfour *c;

	c = get_cfour();
	i = 0;
	j = c->x * c->y;
	while (i < j)
	{
		if (!(i % 2))
		{
			x = (*p1)();
			y = modif_grid(x, 'O');
		}
		else if ((x = (*p2)()) || 1)
			y = modif_grid(x, 'X');
		system("clear");
		print_tab(c->grid);
		isend(x, y, i) ? printwinner() : NULL;
		i++;
	}
	ft_putstr("la partie est nulle !\n");
	return (1);
}
