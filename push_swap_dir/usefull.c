/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 14:18:03 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/06/11 14:18:05 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_remove_useless_case(t_lst *l)
{
	int	*t;
	int	a;
	int	b;

	a = -1;
	b = 0;
	while (++a < l->si)
		if (l->li[a])
			++b;
	if (b == l->si)
		return (0);
	if (!(t = (int *)malloc(sizeof(int) * b)))
		exit(0);
	a = -1;
	b = 0;
	while (++a < l->si)
		if (l->li[a])
		{
			t[b] = l->li[a];
			++b;
		}
	free(l->li);
	l->li = t;
	l->si = b;
	return (1);
}

void	ft_new_ins(t_lst *l, short n)
{
	int	*t;
	int	a;

	a = -1;
	if (!(t = (int *)malloc(sizeof(int) * (l->si + 1))))
		exit(0);
	while (++a < l->si)
		t[a] = l->li[a];
	free(l->li);
	l->li = t;
	l->li[l->si] = n;
	++l->si;
	ft_test_instr(l, n);
}

void	ft_exit(t_lst l, const short b, const short e)
{
	write(2, "Error\n", 6);
	if (b && e == -1)
		write(2, "Les options sont manquantes.\n", 29);
	if (b && e == -2)
		write(2, "Il y a des options repetees.\n", 29);
	if (b && e == -3)
		write(2, "Il y a des options inconnues.\n", 30);
	if (b && e == -4)
		write(2, "Les options doivent se trouver avant les nombres.", 49);
	if (b && e == -5)
		write(2, "Il y a des paramètres supplementaires.\n", 39);
	if (b && e == -6)
		write(2, "Il y a des nombres qui n'entrent pas dans un int.\n", 50);
	if (b && e == -7)
		write(2, "Il y a des variables qui ne sont pas des nombres.\n", 50);
	if (b && e == -8)
		write(2, "Il y a des nombres identiques.\n", 31);
	if (b && e == -9)
		write(2, "Il y a des espaces en trop dans votre liste.\n", 45);
	free(l.la);
	free(l.lb);
	free(l.li);
	exit(1);
}

void	ft_save_before(t_lst *l, int **tl, int *ts)
{
	int	a;

	*tl = (int *)malloc(sizeof(int) * l->sa);
	a = -1;
	while (++a < l->sa)
		(*tl)[a] = l->la[a];
	*ts = l->sa;
}

void	ft_come_back(t_lst *l, int *tl, int ts)
{
	free(l->la);
	free(l->lb);
	l->la = tl;
	l->sa = ts;
	l->lb = NULL;
	l->sb = 0;
}
