/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 07:00:12 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/03/04 07:00:16 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_register_cases(t_lst l, t_bns *b, const char c, short *a)
{
	if (c == 'b' && b->b)
		ft_exit(l, b->e, -2);
	else if (c == 'b')
		b->b = 1;
	else if (c == 'c' && b->c)
		ft_exit(l, b->e, -2);
	else if (c == 'c')
		b->c = 1;
	else if (c == 'e' && *a)
		ft_exit(l, b->e, -2);
	else if (c == 'e')
		*a = 1;
	else if (c == 'h' && b->h)
		ft_exit(l, b->e, -2);
	else if (c == 'h')
		b->h = 1;
	else if (c == 'v' && b->v)
		ft_exit(l, b->e, -2);
	else if (c == 'v')
		b->v = 1;
	else
		ft_exit(l, b->e, -3);
}

void		ft_read_cases(t_lst l, t_bns *b, int ac, char **av)
{
	short	a;
	short	c;

	a = 0;
	while (++a < ac)
		if (av[a][0] == '-' && !(c = 0))
			while (av[a][++c])
				(av[a][c] == 'e') ? b->e = 1 : 0;
	a = 0;
	c = 0;
	while (av[++a] && av[a][0] == '-' && (av[a][1] < '0' ||
		av[a][1] > '9'))
	{
		(!av[a][1]) ? ft_exit(l, b->e, -1) : 0;
		while (++(av[a]) && *av[a])
			ft_register_cases(l, b, *av[a], &c);
	}
	(a + 1 > ac) ? exit(0) : 0;
	while (av[a] && ((av[a][0] >= '0' && av[a][0] <= '9') ||
		(av[a][0] == '-' && av[a][1] >= '0' && av[a][1] <= '9')))
		++a;
	if (a < ac)
		(av[a][0] == '-') ? ft_exit(l, b->e, -4) : ft_exit(l, b->e, -5);
}
