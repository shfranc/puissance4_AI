/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:43:06 by sfranc            #+#    #+#             */
/*   Updated: 2017/03/05 22:56:34 by lduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define XVALMAX 90
# define YVALMAX 90

typedef struct	s_cfour
{
	char		**grid;
	int			x;
	int			y;
	int			lex;
	int			ley;
	int			fini;
	int			diff;
	int			p;
	char		lec;
	char		ia_char;
	int			player;
	t_list		*list;
}				t_cfour;

typedef	struct	s_vect
{
	int	pos;
	int	score;
}				t_vect;

/*
** main.c
** void			rand_player(int (*f1)(void), int (*f2)(void));
** int			check_diff(char *str);
** int			setdifficulty(void);
*/

/*
** cfour.c
*/
void			printcfour(void);
void			free_cfour(void);
t_cfour			*get_cfour(void);

/*
** grid.c
*/
void			create_grid(char *av1, char *av2);
void			printheader(void);
void			print_tab(char **tab);
int				modif_grid(int move, char player);
int				column_isfull(int x);

/*
** get.c
*/
int				check_size(char *av1, char *av2, int *lin, int *col);
int				check_input(char *line);
int				get_input(void);

/*
** rand.c
*/
int				get_rand_int(int inf, int max);

/*
** play.c
*/
int				bestscor(t_list *l1, t_list *l2);
int				get_solution(t_list *l, int diff);
void			freevect(void *content, size_t content_size);
int				get_iaput(void);
int				manage_player(int (*p1)(void), int (*p2)(void));

/*
** isend.c
*/
int				isantidiago(int x, int y, char ch);
int				isdiago(int x, int y, char ch);
int				iscolumn(int x, int y, char ch);
int				isline(int x, int y, char ch);
int				isend(int x, int y, int i);

/*
** won.c
*/
void			printwinner(void);
void			printwin(int i, char *s);
int				playerwin(int x, int y, char c);
/*
** two.c
*/
void			delete_pos(int x, int y);
int				are_in_line(int x, int y, char ch, int nb);

/*
** grade.c
*/
int				grade(int x, char player);

#endif
