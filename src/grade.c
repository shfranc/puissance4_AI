/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 21:00:20 by sfranc            #+#    #+#             */
/*   Updated: 2017/03/07 15:47:04 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int	grade2(int x, int y, t_cfour *cf)
{
	int score;

	score = 0;
	if (x == (cf->x / 2))
		score = 3;
	else
	{
		if (((x >= cf->x / 3) && (x < cf->x / 2))
				|| ((x > cf->x / 2) && (x <= cf->x * (2 / 3))))
			score = 2;
		else
			score = 1;
	}
	if (y == 0)
		score *= 1;
	else
	{
		if (y < cf->y / 2)
			score *= 3;
		else
			score *= 10;
	}
	return (score);
}

int			checkoppwin(int i, char c, int score)
{
	int y;

	y = modif_grid(i + 1, c);
	if ((playerwin(i + 1, y, c)))
		score = -999;
	delete_pos(i, y);
	return (score);
}

int			grade(int x, char player)
{
	int		score;
	int		i;
	int		y;
	char	c;
	t_cfour *cf;

	score = 1;
	if (!(column_isfull(x)))
		return (-1000);
	c = (player == 'X') ? 'O' : 'X';
	cf = get_cfour();
	y = modif_grid(x + 1, player);
	i = 0;
	if (playerwin(x + 1, y, player))
		score = 10000;
	score += grade2(x, y, cf);
	while (i < cf->x)
	{
		if (!column_isfull(i) && i++)
			continue ;
		score = checkoppwin(i, c, score);
		i++;
	}
	delete_pos(x, y);
	return (score);
}
