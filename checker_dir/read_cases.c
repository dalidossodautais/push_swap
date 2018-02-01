/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 18:07:40 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/07/27 18:07:41 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_register_cases(t_lst *l, const char c, short int *b)
{
	if (c == 'e' && *b)
		ft_end(*l, -2);
	else if (c == 'e')
		*b = 1;
	else if (c == 'h' && l->h)
		ft_end(*l, -2);
	else if (c == 'h')
		l->h = 1;
	else if (c == 'v' && l->v)
		ft_end(*l, -2);
	else if (c == 'v')
		l->v = 1;
	else
		ft_end(*l, -3);
}

void		ft_read_cases(t_lst *l, int argc, char **argv)
{
	short	a;
	short	b;

	a = 0;
	while (++a < argc)
		if (argv[a][0] == '-' && !(b = 0))
			while (argv[a][++b])
				(argv[a][b] == 'e') ? l->e = 1 : 0;
	a = 0;
	b = 0;
	while (argv[++a] && argv[a][0] == '-' && (argv[a][1] < '0' ||
		argv[a][1] > '9'))
	{
		(!argv[a][1]) ? ft_end(*l, -1) : 0;
		while (++(argv[a]) && *argv[a])
			ft_register_cases(l, *argv[a], &b);
	}
	(a + 1 > argc) ? ft_end(*l, -4) : 0;
	while (argv[a] && ((argv[a][0] >= '0' && argv[a][0] <= '9') ||
		(argv[a][0] == '-' && argv[a][1] >= '0' && argv[a][1] <= '9')))
		a++;
	(a + 1 < argc) ? ft_end(*l, -5) : 0;
}
