/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 11:39:06 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/08 11:39:08 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_print_error(const int e)
{
	if (e == -1)
		write(2, "Les options sont manquantes.\n", 29);
	if (e == -2)
		write(2, "Il y a des options repetees.\n", 29);
	if (e == -3)
		write(2, "Il y a des options inconnues.\n", 30);
	if (e == -4)
		write(2, "Il n'y a pas de parametres pour les valeurs.\n", 45);
	if (e == -5)
		write(2, "Il y a des paramètres supplementaires.\n", 39);
	if (e == -6)
		write(2, "Il y a des nombres qui n'entrent pas dans un int.\n", 50);
	if (e == -7)
		write(2, "Il y a des variables qui ne sont pas des nombres.\n", 50);
	if (e == -8)
		write(2, "Il y a des nombres identiques.\n", 31);
	if (e == -9)
		write(2, "Il y a des espaces en trop dans votre liste.\n", 45);
	if (e == -10)
		write(2, "Il y a des instructions inconnues.\n", 34);
	if (e == -11)
		write(2, "Il y a une erreur dans la lecture.\n", 34);
}

static void	ft_print_fail(const int e)
{
	if (e == 1)
		write(2, "Il reste des nombres dans la deuxième pile.\n", 44);
	if (e == 2)
		write(2, "Les nombres ne sont pas triés.\n", 31);
}

void		ft_end(struct s_lst l, const int e)
{
	if (e < 0 && e != -4)
		write(2, "Error\n", 6);
	else if (e > 0)
		write(1, "KO\n", 3);
	else if (!e)
		write(1, "OK\n", 3);
	if (e < 0 && l.e)
		ft_print_error(e);
	else if (e > 0 && l.e)
		ft_print_fail(e);
	free(l.la);
	free(l.lb);
	free(l.li);
	exit(1);
}
