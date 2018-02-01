/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_or_not.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 05:54:51 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/07/27 05:54:53 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_or_not_left(t_lst *l)
{
	int	a;
	int	b;
	int	c;
	int	*tl;
	int	ts;

	ft_save_before(l, &tl, &ts);
	a = -1;
	while (++a + 1 < l->si)
	{
		if (l->li[a] == RA || l->li[a] == RRA)
		{
			b = 0;
			while (a + ++b < l->si && l->li[a] == l->li[a + b])
				;
			c = -1;
			while (b > l->sa / 2 && b + ++c < l->sa)
				l->li[a + c] = ((l->li[a + b - 1] == RA) ? RRA : RA);
			while (b > l->sa / 2 && c++ < b)
				l->li[a + c - 1] = CLR;
		}
		ft_test_instr(l, l->li[a]);
	}
	ft_come_back(l, tl, ts);
}

void	ft_reverse_or_not_right(t_lst *l)
{
	int	a;
	int	b;
	int	c;
	int	*tl;
	int	ts;

	ft_save_before(l, &tl, &ts);
	a = -1;
	while (++a + 1 < l->si)
	{
		if (l->li[a] == RB || l->li[a] == RRB)
		{
			b = 0;
			while (a + ++b < l->si && l->li[a] == l->li[a + b])
				;
			c = -1;
			while (b > l->sb / 2 && b + ++c < l->sb)
				l->li[a + c] = ((l->li[a + b - 1] == RB) ? RRB : RB);
			while (b > l->sb / 2 && c++ < b)
				l->li[a + c - 1] = CLR;
		}
		ft_test_instr(l, l->li[a]);
	}
	ft_come_back(l, tl, ts);
}
