/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 05:27:59 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/07/27 05:28:00 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_useless_push_case(t_lst *l)
{
	int	a;
	int	b;

	a = -1;
	while (++a + 1 < l->si)
		if (l->li[a] == PA || l->li[a] == PB)
		{
			b = 0;
			while (a + ++b + 1 < l->si && l->li[a + b] == CLR)
				;
			if (l->li[a] + l->li[a + b] == PA + PB)
			{
				l->li[a] = CLR;
				l->li[a + b] = CLR;
				a = -1;
			}
		}
}

void	ft_useless_left_side(t_lst *l)
{
	int	a;
	int	b;

	a = -1;
	while (++a + 1 < l->si)
		if (l->li[a] == SA || l->li[a] == RA || l->li[a] == RRA)
		{
			b = 0;
			while (a + ++b + 1 < l->si && (l->li[a + b] == SB ||
				l->li[a + b] == RB || l->li[a + b] == RRB ||
				l->li[a + b] == CLR))
				;
			if ((l->li[a] == SA && l->li[a + b] == SA) ||
				(l->li[a] == RA && l->li[a + b] == RRA) ||
				(l->li[a] == RRA && l->li[a + b] == RA))
			{
				l->li[a] = CLR;
				l->li[a + b] = CLR;
				a = -1;
			}
		}
}

void	ft_useless_right_side(t_lst *l)
{
	int	a;
	int	b;

	a = -1;
	while (++a + 1 < l->si)
		if (l->li[a] == SB || l->li[a] == RB || l->li[a] == RRB)
		{
			b = 0;
			while (a + ++b + 1 < l->si && (l->li[a + b] == SA ||
				l->li[a + b] == RA || l->li[a + b] == RRA ||
				l->li[a + b] == CLR))
				;
			if ((l->li[a] == SB && l->li[a + b] == SB) ||
				(l->li[a] == RB && l->li[a + b] == RRB) ||
				(l->li[a] == RRB && l->li[a + b] == RB))
			{
				l->li[a] = CLR;
				l->li[a + b] = CLR;
				a = -1;
			}
		}
}

void	ft_too_much_left_rotate(t_lst *l)
{
	int	a;
	int	b;
	int	*tl;
	int	ts;

	tl = (int *)malloc(sizeof(int) * l->sa);
	a = -1;
	while (++a < l->sa)
		tl[a] = l->la[a];
	ts = l->sa;
	a = -1;
	while (++a + 1 < l->si)
	{
		if (l->li[a] == RA || l->li[a] == RRA)
		{
			b = 0;
			while (a + ++b < l->si && b < l->sa && l->li[a] == l->li[a + b])
				;
			if (b == l->sa)
				while (b--)
					l->li[a + b] = CLR;
		}
		ft_test_instr(l, l->li[a]);
	}
	ft_come_back(l, tl, ts);
}

void	ft_too_much_right_rotate(t_lst *l)
{
	int	a;
	int	b;
	int	*tl;
	int	ts;

	tl = (int *)malloc(sizeof(int) * l->sa);
	a = -1;
	while (++a < l->sa)
		tl[a] = l->la[a];
	ts = l->sa;
	a = -1;
	while (++a + 1 < l->si)
	{
		if (l->li[a] == RB || l->li[a] == RRB)
		{
			b = 0;
			while (a + ++b < l->si && b < l->sb && l->li[a] == l->li[a + b])
				;
			if (b == l->sb)
				while (b--)
					l->li[a + b] = CLR;
		}
		ft_test_instr(l, l->li[a]);
	}
	ft_come_back(l, tl, ts);
}
