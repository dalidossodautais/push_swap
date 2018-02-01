/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 11:10:00 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/08 11:10:10 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 1
# define CLR 0
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct	s_lst
{
	int		*la;
	int		*lb;
	int		*li;
	int		sa;
	int		sb;
	int		si;
	int		e;
	int		h;
	int		v;
}				t_lst;

void			ft_initialize(t_lst *l);
void			ft_read_cases(t_lst *l, int argc, char **argv);
void			ft_read_param(t_lst *l, int argc, char **argv);
void			ft_read_instr(t_lst *l);
void			ft_verif_instr(t_lst l);
void			ft_end(t_lst l, const int e);

void			ft_sa(t_lst *l);
void			ft_sb(t_lst *l);
void			ft_ss(t_lst *l);
void			ft_pa(t_lst *l);
void			ft_pb(t_lst *l);
void			ft_ra(t_lst *l);
void			ft_rb(t_lst *l);
void			ft_rr(t_lst *l);
void			ft_rra(t_lst *l);
void			ft_rrb(t_lst *l);
void			ft_rrr(t_lst *l);

#endif
