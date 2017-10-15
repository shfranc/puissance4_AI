/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfour.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <lduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:17:32 by lduval            #+#    #+#             */
/*   Updated: 2017/03/07 15:33:38 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	printcfour(void)
{
	t_cfour *c;

	c = get_cfour();
	ft_putstr("x: ");
	ft_putnbr(c->x);
	ft_putstr(" y: ");
	ft_putnbr(c->y);
	ft_putstr(" lex: ");
	ft_putnbr(c->lex);
	ft_putstr(" ley: ");
	ft_putnbr(c->ley);
	ft_putstr(" fini: ");
	ft_putnbr(c->fini);
	ft_putstr(" diff: ");
	ft_putnbr(c->diff);
	ft_putstr(" p: ");
	ft_putnbr(c->p);
	ft_putstr(" lec: ");
	ft_putchar(c->lec);
	ft_putstr(" ia_char: ");
	ft_putchar(c->ia_char);
	ft_putendl("");
}

void	free_cfour(void)
{
	t_cfour *c;

	c = get_cfour();
	c && c->grid ? ft_freetab(c->grid) : NULL;
	c && c->grid ? free(c->grid) : NULL;
	c ? free(c) : NULL;
	get_next_line(-2, NULL);
}

t_cfour	*get_cfour(void)
{
	static t_cfour *s = NULL;

	if (!s)
	{
		if (!(s = (t_cfour *)malloc(sizeof(t_cfour))))
			ft_error("Unable to malloc cfour's struct", &free_cfour);
		s->grid = NULL;
		s->x = 0;
		s->y = 0;
		s->lex = 0;
		s->ley = 0;
		s->fini = 0;
		s->diff = 3;
		s->p = 0;
		s->lec = 0;
		s->ia_char = 0;
		s->player = 0;
		s->list = NULL;
	}
	return (s);
}
