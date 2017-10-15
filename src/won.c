/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   won.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <lduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 08:47:38 by lduval            #+#    #+#             */
/*   Updated: 2017/03/05 22:13:33 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	printwin(int i, char *s)
{
	t_cfour *c;

	c = get_cfour();
	ft_putstr(s);
	if (c->player)
	{
		ft_putstr("Player ");
		ft_putnbr(i);
		ft_putendl(" is the winner !\e[0m");
	}
	else
	{
		if (c->lec == c->ia_char)
			ft_putendl("You loose...");
		else
			ft_putendl("You are the winner !");
	}
}

void	printwinner(void)
{
	t_cfour *c;

	c = get_cfour();
	if (c->lec == 'X')
		printwin(2, "\e[93m");
	else
		printwin(1, "\e[91m");
	free_cfour();
	exit(1);
}
