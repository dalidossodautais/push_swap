/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 18:07:47 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/07/27 18:07:49 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_insert(t_lst *l, int n)
{
	int		a;
	int		*t;

	if (!(t = (int *)malloc(sizeof(int) * (l->sa + 1))))
		exit(1);
	a = -1;
	while (++a < l->sa)
	{
		if (n == l->la[a])
		{
			free(t);
			ft_end(*l, -8);
		}
		t[a] = l->la[a];
	}
	free(l->la);
	l->la = t;
	l->la[l->sa] = n;
	l->sa++;
}

void		ft_include_param(t_lst *l, char *s)
{
	long	n;
	short	a;

	if (*s == ' ')
		ft_end(*l, -9);
	while (*s)
	{
		a = (*s == '-' && ++s) ? -1 : 1;
		n = 0;
		while (*s >= '0' && *s <= '9')
		{
			n = n * 10 + *s - '0';
			if (n * a > 2147483647 || n * a < -2147483648)
				ft_end(*l, -6);
			++s;
		}
		n *= a;
		ft_insert(l, n);
		if (*s == ' ' && *(s + 1))
			++s;
		if (*s == ' ')
			ft_end(*l, -9);
		if (*s && (*s < '0' || *s > '9'))
			ft_end(*l, -7);
	}
}

void		ft_read_param(t_lst *l, int argc, char **argv)
{
	int	a;

	a = 1;
	while (argv[a] && argv[a][0] == '-' && (argv[a][1] < '0' ||
		argv[a][1] > '9'))
		++a;
	while (a < argc)
	{
		ft_include_param(l, argv[a]);
		++a;
	}
}
