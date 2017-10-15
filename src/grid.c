/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:27:03 by sfranc            #+#    #+#             */
/*   Updated: 2017/03/05 22:53:28 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	create_grid(char *av1, char *av2)
{
	int		i;
	t_cfour	*c;

	c = get_cfour();
	if (!(check_size(av1, av2, &(c->y), &(c->x))))
		ft_error("Wrong size input", NULL);
	if (!(c->grid = (char**)malloc((sizeof(char*) * (c->y + 1)))))
		ft_error("Unable to malloc column", NULL);
	c->grid[c->y] = 0;
	i = 0;
	while (i < c->y)
	{
		if (!(*(c->grid + i) = ft_strnew(c->x)))
			ft_error("Unable to malloc line", NULL);
		ft_memset(*(c->grid + i), ' ', c->x);
		i++;
	}
}

void	printheader(void)
{
	int	size;
	int i;

	size = get_cfour()->x;
	i = 0;
	while (i++ < size)
	{
		ft_putchar(' ');
		if (i <= 9)
			ft_putchar(' ');
		ft_putnbr(i);
		ft_putchar(' ');
	}
	ft_putendl("");
}

void	print_tab(char **tab)
{
	int		i;
	char	c;

	printheader();
	while (*tab)
	{
		ft_putchar('|');
		i = 0;
		c = (*tab)[i];
		while (c)
		{
			ft_putchar(' ');
			if (c == 'O')
				ft_putstr("\e[91mO\e[0m");
			else if (c == 'X')
				ft_putstr("\e[93mO\e[0m");
			else
				ft_putchar(c);
			ft_putstr(" |");
			i++;
			c = (*tab)[i];
		}
		ft_putchar('\n');
		tab++;
	}
}

int		modif_grid(int move, char player)
{
	t_cfour *c;
	int		i;

	c = get_cfour();
	i = c->y - 1;
	while (i >= 0)
	{
		if (c->grid[i][move - 1] != ' ')
			i--;
		else
		{
			(c->grid[i][move - 1]) = player;
			break ;
		}
	}
	return (i);
}

int		column_isfull(int x)
{
	t_cfour *c;
	int		i;

	c = get_cfour();
	i = c->y - 1;
	while (i >= 0 && (c->grid[i][x] != ' '))
		i--;
	if (i == -1)
		return (0);
	return (1);
}
