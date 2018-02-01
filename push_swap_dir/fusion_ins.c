/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_ins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 07:50:23 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/07/27 07:50:24 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fusion_swap(t_lst *l)
{
	int	a;

	a = -1;
	while (++a + 1 < l->si)
	{
		if ((l->li[a] == SA || l->li[a] == SB) &&
			l->li[a] + l->li[a + 1] == SA + SB)
		{
			l->li[a] = SS;
			l->li[a + 1] = CLR;
		}
	}
}

void	ft_fusion_rotate(t_lst *l)
{
	int	a;
	int	b;

	a = -1;
	while (++a + 1 < l->si)
	{
		if (l->li[a] == RA || l->li[a] == RB)
		{
			b = 1;
			while (a + b + 1 < l->si &&
				(l->li[a] == l->li[a + b] || l->li[a] == CLR))
				++b;
			if (l->li[a] + l->li[a + b] == RA + RB)
			{
				l->li[a] = RR;
				l->li[a + b] = CLR;
			}
		}
	}
}

void	ft_fusion_reverse_rotate(t_lst *l)
{
	int	a;
	int	b;

	a = -1;
	while (++a + 1 < l->si)
	{
		if (l->li[a] == RRA || l->li[a] == RRB)
		{
			b = 1;
			while (a + b + 1 < l->si &&
				(l->li[a] == l->li[a + b] || l->li[a] == CLR))
				++b;
			if (l->li[a] + l->li[a + b] == RRA + RRB)
			{
				l->li[a] = RRR;
				l->li[a + b] = CLR;
			}
		}
	}
}
