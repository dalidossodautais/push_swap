/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 07:56:00 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/03/04 07:56:10 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_insert(t_lst *l, const short b, int n)
{
	int		a;
	int		*t;

	if (!(t = (int *)malloc(sizeof(int) * (l->sa + 1))))
		exit(0);
	a = -1;
	while (++a < l->sa)
	{
		if (n == l->la[a])
		{
			free(t);
			ft_exit(*l, b, -8);
		}
		t[a] = l->la[a];
	}
	free(l->la);
	l->la = t;
	l->la[l->sa] = n;
	l->sa++;
}

void		ft_include_param(t_lst *l, const short b, char *s)
{
	long	n;
	short	a;

	while (*s)
	{
		a = (*s == '-' && ++s) ? -1 : 1;
		n = 0;
		while (*s >= '0' && *s <= '9')
		{
			n = n * 10 + *s - '0';
			if (n * a > 2147483647 || n * a < -2147483648)
				ft_exit(*l, b, -6);
			++s;
		}
		n *= a;
		ft_insert(l, b, n);
		if (*s == ' ' && *(s + 1))
			++s;
		if (*s == ' ')
			ft_exit(*l, b, -9);
		if (*s && !((*s >= '0' && *s <= '9') || (*s == '-' &&
			*(s + 1) >= '0' && *(s + 1) <= '9')))
			ft_exit(*l, b, -7);
	}
}

void		ft_read_param(t_lst *l, const short b, int ac, char **av)
{
	int	a;

	a = 1;
	l->la = NULL;
	l->sa = 0;
	while (av[a] && av[a][0] == '-' && (av[a][1] < '0' || av[a][1] > '9'))
		++a;
	--a;
	while (++a < ac)
		ft_include_param(l, b, av[a]);
}
