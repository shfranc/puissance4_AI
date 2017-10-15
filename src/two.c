/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:40:44 by sfranc            #+#    #+#             */
/*   Updated: 2017/03/05 21:14:15 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		playerwin(int x, int y, char c)
{
	return (isline(x, y, c) || iscolumn(x, y, c) ||
			isdiago(x, y, c) || isantidiago(x, y, c));
}

void	delete_pos(int x, int y)
{
	t_cfour	*c;

	c = get_cfour();
	c->grid[y][x] = ' ';
}

int		are_in_line(int x, int y, char ch, int nb)
{
	t_cfour *c;
	int		i;
	int		count;
	int		j;

	count = 0;
	c = get_cfour();
	j = 3;
	i = x - 1;
	while (j > 0)
	{
		if (i > 0 && i < c->x && c->grid[y][i - 1] == ch)
			count++;
		else
			count = 0;
		if (count == nb)
			return (1);
		i++;
		j--;
	}
	return (0);
}
