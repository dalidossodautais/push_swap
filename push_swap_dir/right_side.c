/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_side.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 04:45:31 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/07/27 04:45:32 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_return_to_right(t_lst *l, int s, int t)
{
	int	u;
	int	v;

	u = 0;
	v = 0;
	while (u++ < s - t)
		ft_new_ins(l, RB);
	while (v < t)
	{
		if (l->lb[l->sb - 1] < l->la[0] && --u > 0)
			ft_new_ins(l, RRB);
		else if (++v)
			ft_new_ins(l, PB);
	}
	while (--u > 0)
		ft_new_ins(l, RRB);
}

void		ft_right_special_case(t_lst *l)
{
	if (l->sb == 3)
	{
		while (l->lb[0] < l->lb[2] || l->lb[1] < l->lb[2])
			ft_new_ins(l, RB);
		if (l->lb[0] < l->lb[1])
			ft_new_ins(l, SB);
	}
	else
	{
		if (l->lb[0] < l->lb[1])
			ft_new_ins(l, SB);
		ft_new_ins(l, RB);
		if (l->lb[0] < l->lb[1])
			ft_new_ins(l, SB);
		ft_new_ins(l, RRB);
		if (l->lb[0] < l->lb[1])
			ft_new_ins(l, SB);
	}
}

void		ft_right_side(t_lst *l, int s)
{
	int	t;
	int	a;

	if (!ft_verif(l, s, 'b'))
	{
		if (s == 2 && l->lb[0] < l->lb[1])
			ft_new_ins(l, SB);
		else if (s == 3)
			ft_right_special_case(l);
		else if (s > 3)
		{
			t = s % 3;
			while (t + 3 <= s / 2)
				t += 3;
			a = 0;
			while (a++ < t)
				ft_new_ins(l, PA);
			ft_left_side(l, t);
			ft_right_side(l, s - t);
			ft_return_to_right(l, s, t);
		}
	}
}
