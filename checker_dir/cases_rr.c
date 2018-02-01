/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:06:27 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/04 15:06:29 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rra(t_lst *l)
{
	int	t;
	int	a;

	if (l->sa > 1)
	{
		a = l->sa - 1;
		t = l->la[l->sa - 1];
		while (a--)
			l->la[a + 1] = l->la[a];
		l->la[0] = t;
	}
}

void	ft_rrb(t_lst *l)
{
	int	t;
	int	a;

	if (l->sb > 1)
	{
		a = l->sb - 1;
		t = l->lb[l->sb - 1];
		while (a--)
			l->lb[a + 1] = l->lb[a];
		l->lb[0] = t;
	}
}

void	ft_rrr(t_lst *l)
{
	int	t;
	int	a;

	if (l->sa > 1)
	{
		a = l->sa - 1;
		t = l->la[l->sa - 1];
		while (a--)
			l->la[a + 1] = l->la[a];
		l->la[0] = t;
	}
	if (l->sb > 1)
	{
		a = l->sb - 1;
		t = l->lb[l->sb - 1];
		while (a--)
			l->lb[a + 1] = l->lb[a];
		l->lb[0] = t;
	}
}
