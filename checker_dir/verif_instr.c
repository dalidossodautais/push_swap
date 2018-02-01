/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:17:20 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/08 16:17:22 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static void	ft_call_print_state(t_lst l)
{
	l.sa ? ft_print_state(l.la, l.sa, 0) : write(1, "EMPTY===", 8);
	l.sb ? ft_print_state(l.lb, l.sb, 1) : write(1, "EMPTY\n", 6);
}

static void	ft_test_instr(t_lst *l, int i)
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

static void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb < 10)
	{
		c = nb + 48;
		write(1, &c, 1);
	}
}

void		ft_verif_instr(t_lst l)
{
	int		a;

	a = -1;
	while (++a < l.si)
	{
		(l.v) ? ft_call_print_state(l) : 0;
		ft_test_instr(&l, l.li[a]);
	}
	(l.v) ? ft_call_print_state(l) : 0;
	a = -1;
	while (l.h && ++a < l.sa)
	{
		ft_putnbr(l.la[a]);
		write(1, " ", 1);
	}
	if (l.h)
		write(1, "\n", 1);
	if (l.sb)
		ft_end(l, 1);
	a = 0;
	while (++a < l.sa)
		if (l.la[a - 1] > l.la[a])
			ft_end(l, 2);
	ft_end(l, 0);
}
