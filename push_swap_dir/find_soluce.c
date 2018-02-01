/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_soluce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:21:25 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/06/10 20:21:28 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_verif(t_lst *l, int s, char c)
{
	int	a;

	a = 0;
	if (c == 'a')
	{
		while (++a < s)
			if (l->la[a - 1] > l->la[a])
				return (0);
	}
	else
		while (++a < s)
			if (l->lb[a - 1] < l->lb[a])
				return (0);
	return (1);
}

static void	ft_useless_case(t_lst *l)
{
	ft_useless_push_case(l);
	ft_useless_left_side(l);
	ft_useless_right_side(l);
	ft_remove_useless_case(l);
	ft_too_much_left_rotate(l);
	ft_too_much_right_rotate(l);
	if (ft_remove_useless_case(l))
		ft_useless_case(l);
}

void		ft_test_instr(t_lst *l, int i)
{
	if (i == SA)
		ft_sa(l);
	else if (i == SB)
		ft_sb(l);
	else if (i == SS)
		ft_ss(l);
	else if (i == PA)
		ft_pa(l);
	else if (i == PB)
		ft_pb(l);
	else if (i == RA)
		ft_ra(l);
	else if (i == RB)
		ft_rb(l);
	else if (i == RR)
		ft_rr(l);
	else if (i == RRA)
		ft_rra(l);
	else if (i == RRB)
		ft_rrb(l);
	else if (i == RRR)
		ft_rrr(l);
}

void		ft_find_soluce(t_lst *l)
{
	int		*t;
	int		a;

	if (!(t = (int *)malloc(sizeof(int) * l->sa)))
		exit(0);
	a = -1;
	while (++a < l->sa)
		t[a] = l->la[a];
	ft_left_side(l, l->sa);
	ft_useless_case(l);
	ft_reverse_or_not_left(l);
	ft_reverse_or_not_right(l);
	ft_remove_useless_case(l);
	ft_fusion_swap(l);
	ft_fusion_rotate(l);
	ft_fusion_reverse_rotate(l);
	ft_remove_useless_case(l);
	free(l->la);
	l->la = t;
	l->sa = a;
	free(l->lb);
	l->lb = NULL;
	l->sb = 0;
}
