/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_soluce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 21:13:58 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/06/10 21:14:00 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_state(int *l, int s, int color)
{
	long	t;
	int		a;
	char	c;

	a = -1;
	write(1, "|", 1);
	while (++a < s)
	{
		(color) ? write(1, "\033[32m", 5) : write(1, "\033[35m", 5);
		t = 1;
		while (l[a] / 10 / t)
			t *= 10;
		while (t)
		{
			if (l[a] < 0)
				write(1, "-", 1);
			c = ((l[a] < 0) ? -l[a] : l[a]) / t % 10 + '0';
			write(1, &c, 1);
			t /= 10;
		}
		write(1, "\033[0m", 4);
		write(1, "|", 1);
	}
	(color) ? write(1, "\n", 1) : write(1, "===", 3);
}

static void	ft_print_ins_spe(int i)
{
	if (i == SA)
		write(1, "\033[35msa\033[0m\n", 12);
	if (i == SB)
		write(1, "\033[35msb\033[0m\n", 12);
	if (i == SS)
		write(1, "\033[35mss\033[0m\n", 12);
	if (i == PA)
		write(1, "\033[36mpa\033[0m\n", 12);
	if (i == PB)
		write(1, "\033[36mpb\033[0m\n", 12);
	if (i == RA)
		write(1, "\033[32mra\033[0m\n", 12);
	if (i == RB)
		write(1, "\033[32mrb\033[0m\n", 12);
	if (i == RR)
		write(1, "\033[32mrr\033[0m\n", 12);
	if (i == RRA)
		write(1, "\033[33mrra\033[0m\n", 13);
	if (i == RRB)
		write(1, "\033[33mrrb\033[0m\n", 13);
	if (i == RRR)
		write(1, "\033[33mrrr\033[0m\n", 13);
}

static void	ft_print_ins(int i)
{
	if (i == SA)
		write(1, "sa\n", 3);
	if (i == SB)
		write(1, "sb\n", 3);
	if (i == SS)
		write(1, "ss\n", 3);
	if (i == PA)
		write(1, "pa\n", 3);
	if (i == PB)
		write(1, "pb\n", 3);
	if (i == RA)
		write(1, "ra\n", 3);
	if (i == RB)
		write(1, "rb\n", 3);
	if (i == RR)
		write(1, "rr\n", 3);
	if (i == RRA)
		write(1, "rra\n", 4);
	if (i == RRB)
		write(1, "rrb\n", 4);
	if (i == RRR)
		write(1, "rrr\n", 4);
}

void		ft_print_soluce(t_lst *l, const t_bns b)
{
	int	a;

	a = -1;
	while (++a < l->si)
	{
		if (b.v)
		{
			l->sa ? ft_print_state(l->la, l->sa, 0) : write(1, "EMPTY===", 8);
			l->sb ? ft_print_state(l->lb, l->sb, 1) : write(1, "EMPTY\n", 6);
		}
		if (b.c && a + 1 == l->si)
		{
			write(1, "\033[31m", 5);
			ft_print_ins(l->li[a]);
			write(1, "\033[0m", 4);
		}
		else
			b.h ? ft_print_ins_spe(l->li[a]) : ft_print_ins(l->li[a]);
		ft_test_instr(l, l->li[a]);
	}
	if (b.v)
	{
		l->sa ? ft_print_state(l->la, l->sa, 0) : write(1, "EMPTY===", 8);
		l->sb ? ft_print_state(l->lb, l->sb, 1) : write(1, "EMPTY\n", 6);
	}
}
