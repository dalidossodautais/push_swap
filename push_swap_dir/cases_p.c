/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cases.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:06:09 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/04 15:06:13 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_lst *l)
{
	int	*t;
	int	a;

	if (!(t = (int *)malloc(sizeof(int) * (l->sa + 1))))
		exit(1);
	a = -1;
	while (++a < l->sa)
		t[a + 1] = l->la[a];
	free(l->la);
	l->la = t;
	l->la[0] = l->lb[0];
	if (!(t = (int *)malloc(sizeof(int) * (l->sb - 1))))
		exit(1);
	a = -1;
	while (++a < l->sb - 1)
		t[a] = l->lb[a + 1];
	free(l->lb);
	l->lb = t;
	l->sa += 1;
	l->sb -= 1;
}

void	ft_pb(t_lst *l)
{
	int	*t;
	int	a;

	if (!(t = (int *)malloc(sizeof(int) * (l->sb + 1))))
		exit(1);
	a = -1;
	while (++a < l->sb)
		t[a + 1] = l->lb[a];
	free(l->lb);
	l->lb = t;
	l->lb[0] = l->la[0];
	if (!(t = (int *)malloc(sizeof(int) * (l->sa - 1))))
		exit(1);
	a = -1;
	while (++a < l->sa - 1)
		t[a] = l->la[a + 1];
	free(l->la);
	l->la = t;
	l->sb += 1;
	l->sa -= 1;
}
