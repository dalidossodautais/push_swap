/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cases.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:06:00 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/04 15:06:04 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_lst *l)
{
	int	t;

	if (l->sa > 1)
	{
		t = l->la[0];
		l->la[0] = l->la[1];
		l->la[1] = t;
	}
}

void	ft_sb(t_lst *l)
{
	int	t;

	if (l->sb > 1)
	{
		t = l->lb[0];
		l->lb[0] = l->lb[1];
		l->lb[1] = t;
	}
}

void	ft_ss(t_lst *l)
{
	int	t;

	if (l->sa > 1)
	{
		t = l->la[0];
		l->la[0] = l->la[1];
		l->la[1] = t;
	}
	if (l->sb > 1)
	{
		t = l->lb[0];
		l->lb[0] = l->lb[1];
		l->lb[1] = t;
	}
}
