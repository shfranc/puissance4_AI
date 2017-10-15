/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:38:24 by sfranc            #+#    #+#             */
/*   Updated: 2017/03/07 15:36:58 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	rand_player(int (*f1)(void), int (*f2)(void))
{
	int		i;
	t_cfour	*c;

	c = get_cfour();
	srand(time(NULL));
	i = get_rand_int(0, 2);
	print_tab(c->grid);
	c->p = i;
	if (i)
	{
		c->ia_char = 'X';
		manage_player(f1, f2);
	}
	else
	{
		c->ia_char = 'O';
		manage_player(f2, f1);
	}
}

int		check_diff(char *str)
{
	if (ft_strequ(str, "1"))
		return (1);
	if (ft_strequ(str, "2"))
		return (2);
	if (ft_strequ(str, "3"))
		return (3);
	else
		return (1);
}

int		setdifficulty(void)
{
	char	*line;
	int		i;
	int		erreur;
	t_cfour	*c;

	c = get_cfour();
	i = 0;
	line = NULL;
	erreur = 0;
	ft_putendl("choose a level from beginner (1) or medium (2) or hard(3):");
	while (!i && (erreur = get_next_line(0, &line)) > 0)
	{
		i = check_diff(line);
		ft_strdel(&line);
		if (i != 0)
			ft_putendl("Try again:");
	}
	if (erreur == -1)
		ft_error("Fail get_next_line", &free_cfour);
	c->diff = i;
	return (i);
}

int		main(int ac, char **av)
{
	t_cfour	*c;

	system("clear");
	if (ac < 3)
		ft_error("wrong input", NULL);
	c = get_cfour();
	create_grid(av[1], av[2]);
	if (ac == 3)
		rand_player(&get_input, &get_iaput);
	else if (ac == 4 && ft_strequ(av[3], "-p2"))
	{
		c->player = 1;
		rand_player(&get_input, &get_input);
	}
	else if (ac == 4 && ft_strequ("-setd", av[3]))
	{
		setdifficulty();
		rand_player(&get_input, &get_iaput);
	}
	else
		ft_error("wrong input", NULL);
	return (1);
}
