/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 18:07:31 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/07/27 18:07:32 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	t_lst	l;

	ft_initialize(&l);
	ft_read_cases(&l, argc, argv);
	ft_read_param(&l, argc, argv);
	ft_read_instr(&l);
	ft_verif_instr(l);
	return (0);
}
