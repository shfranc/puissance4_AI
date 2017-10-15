/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduval <lduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:20:11 by lduval            #+#    #+#             */
/*   Updated: 2017/03/05 22:55:50 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		check_size(char *av1, char *av2, int *lin, int *col)
{
	if (!ft_isnumber(av1) || !ft_isnumber(av2))
		return (0);
	*lin = ft_atoi(av1);
	*col = ft_atoi(av2);
	return (((*lin >= 6 && *lin <= XVALMAX)
				&& (*col >= 7 && *col <= YVALMAX)));
}

int		check_input(char *line)
{
	int		i;
	int		j;
	int		max;
	t_cfour	*c;

	c = get_cfour();
	max = c->x;
	i = 0;
	if (ft_isnumber(line))
	{
		j = c->y - 1;
		i = ft_atoi(line);
		if (i > 0 && i <= max)
		{
			while (j >= 0 && c->grid[j][i - 1] != ' ')
				j--;
			i = (j == -1) ? 0 : i;
		}
		else
		{
			ft_printf("\e[91mEntre 1 et %d!\e[0m\n", c->y);
			i = 0;
		}
	}
	return (i);
}

int		get_input(void)
{
	char	*line;
	int		erreur;
	int		i;

	i = 0;
	ft_putendl("In which column do you want to play ?");
	while (!i && (erreur = get_next_line(0, &line)) > 0)
	{
		i = check_input(line);
		ft_strdel(&line);
		if (i == 0)
			ft_putendl("Try again:");
	}
	if (erreur == -1)
		ft_error("Fail get_next_line", &free_cfour);
	return (i);
}
