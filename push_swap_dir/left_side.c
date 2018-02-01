/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 04:43:58 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/07/27 04:44:00 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_return_to_left(t_lst *l, int s, int t)
{
	int	u;
	int	v;

	u = 0;
	v = 0;
	while (u++ < s - t)
		ft_new_ins(l, RA);
	while (v < t)
	{
		if (l->la[l->sa - 1] > l->lb[0] && --u > 0)
			ft_new_ins(l, RRA);
		else if (++v)
			ft_new_ins(l, PA);
	}
	while (--u > 0)
		ft_new_ins(l, RRA);
}

static void	ft_left_special_case(t_lst *l)
{
	if (l->sa == 3)
	{
		while (l->la[0] > l->la[2] || l->la[1] > l->la[2])
			ft_new_ins(l, RA);
		if (l->la[0] > l->la[1])
			ft_new_ins(l, SA);
	}
	else
	{
		if (l->la[0] > l->la[1])
			ft_new_ins(l, SA);
		ft_new_ins(l, RA);
		if (l->la[0] > l->la[1])
			ft_new_ins(l, SA);
		ft_new_ins(l, RRA);
		if (l->la[0] > l->la[1])
			ft_new_ins(l, SA);
	}
}

void		ft_left_side(t_lst *l, int s)
{
	int	t;
	int	a;

	if (!ft_verif(l, s, 'a'))
	{
		if (s == 2 && l->la[0] > l->la[1])
			ft_new_ins(l, SA);
		else if (s == 3)
			ft_left_special_case(l);
		else if (s > 3)
		{
			t = s % 3;
			while (t + 3 <= s / 2)
				t += 3;
			a = 0;
			while (a++ < t)
				ft_new_ins(l, PB);
			ft_right_side(l, t);
			ft_left_side(l, s - t);
			ft_return_to_left(l, s, t);
		}
	}
}
