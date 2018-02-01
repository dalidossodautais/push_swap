/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 06:45:10 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/03/04 06:45:12 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_lst	l;
	t_bns	b;

	b.b = 0;
	b.c = 0;
	b.e = 0;
	b.h = 0;
	b.v = 0;
	l.la = NULL;
	l.sa = 0;
	l.lb = NULL;
	l.sb = 0;
	l.li = NULL;
	l.si = 0;
	ft_read_cases(l, &b, ac, av);
	ft_read_param(&l, b.e, ac, av);
	ft_find_soluce(&l);
	ft_print_soluce(&l, b);
	free(l.la);
	free(l.lb);
	free(l.li);
	return (0);
}
