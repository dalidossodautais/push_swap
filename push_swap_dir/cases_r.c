/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_cases.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:06:18 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/04 15:06:22 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_lst *l)
{
	int	t;
	int	a;

	a = -1;
	t = l->la[0];
	while (++a < l->sa - 1)
		l->la[a] = l->la[a + 1];
	l->la[l->sa - 1] = t;
}

void	ft_rb(t_lst *l)
{
	int	t;
	int	a;

	a = -1;
	t = l->lb[0];
	while (++a < l->sb - 1)
		l->lb[a] = l->lb[a + 1];
	l->lb[l->sb - 1] = t;
}

void	ft_rr(t_lst *l)
{
	int	t;
	int	a;

	a = -1;
	t = l->la[0];
	while (++a < l->sa - 1)
		l->la[a] = l->la[a + 1];
	l->la[l->sa - 1] = t;
	a = -1;
	t = l->lb[0];
	while (++a < l->sb - 1)
		l->lb[a] = l->lb[a + 1];
	l->lb[l->sb - 1] = t;
}
