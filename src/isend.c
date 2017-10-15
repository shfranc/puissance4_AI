/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isend.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <lduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 02:17:10 by lduval            #+#    #+#             */
/*   Updated: 2017/03/05 21:48:44 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		isantidiago(int x, int y, char ch)
{
	t_cfour *c;
	int		i1;
	int		i2;
	int		count;
	int		j;

	count = 0;
	c = get_cfour();
	j = 7;
	i1 = x + 3;
	i2 = y - 3;
	while (j > 0)
	{
		if (i1 > 0 && i2 >= 0 && i1 <= c->x && i2 < c->y
				&& c->grid[i2][i1 - 1] == ch)
			count++;
		else
			count = 0;
		if (count == 4)
			return (1);
		i1--;
		i2++;
		j--;
	}
	return (0);
}

int		isdiago(int x, int y, char ch)
{
	t_cfour *c;
	int		i1;
	int		i2;
	int		count;
	int		j;

	count = 0;
	c = get_cfour();
	j = 7;
	i1 = x - 3;
	i2 = y - 3;
	while (j > 0)
	{
		if (i1 > 0 && i2 > 0 && i1 <= c->x && i2 < c->y
				&& c->grid[i2][i1 - 1] == ch)
			count++;
		else
			count = 0;
		if (count == 4)
			return (1);
		i1++;
		i2++;
		j--;
	}
	return (0);
}

int		iscolumn(int x, int y, char ch)
{
	t_cfour *c;
	int		i;
	int		count;
	int		j;

	count = 0;
	c = get_cfour();
	j = 7;
	i = y - 3;
	while (j > 0)
	{
		if (i >= 0 && i < c->y && c->grid[i][x - 1] == ch)
			count++;
		else
			count = 0;
		if (count == 4)
			return (1);
		i++;
		j--;
	}
	return (0);
}

int		isline(int x, int y, char ch)
{
	t_cfour *c;
	int		i;
	int		count;
	int		j;

	count = 0;
	c = get_cfour();
	j = 7;
	i = x - 3;
	while (j > 0)
	{
		if (i > 0 && i <= c->x && c->grid[y][i - 1] == ch)
			count++;
		else
			count = 0;
		if (count == 4)
			return (1);
		i++;
		j--;
	}
	return (0);
}

int		isend(int x, int y, int i)
{
	char	c;
	t_cfour	*cfour;

	cfour = get_cfour();
	c = !(i % 2) ? 'O' : 'X';
	if (isline(x, y, c))
		cfour->fini = 1;
	if (iscolumn(x, y, c))
		cfour->fini = 2;
	if (isdiago(x, y, c))
		cfour->fini = 3;
	if (isantidiago(x, y, c))
		cfour->fini = 4;
	if (cfour->fini)
	{
		cfour->lex = x;
		cfour->ley = y;
		cfour->lec = c;
	}
	return (cfour->fini);
}
