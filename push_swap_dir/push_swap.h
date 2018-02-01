/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:02:51 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/02/04 15:02:52 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
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
	int		sa;
	int		*lb;
	int		sb;
	int		*li;
	int		si;
}				t_lst;

typedef struct	s_bns
{
	short	b;
	short	c;
	short	e;
	short	h;
	short	v;
}				t_bns;

int				main(int argc, char **argv);
void			ft_read_cases(t_lst l, t_bns *b, int argc, char **argv);
void			ft_read_param(t_lst *l, const short b, int argc, char **argv);
void			ft_new_ins(t_lst *l, short n);
void			ft_test_instr(t_lst *l, int i);
void			ft_exit(t_lst l, const short b, const short e);
void			ft_find_soluce(t_lst *l);
void			ft_left_side(t_lst *l, int s);
void			ft_right_side(t_lst *l, int s);
void			ft_useless_push_case(t_lst *l);
void			ft_useless_left_side(t_lst *l);
void			ft_useless_right_side(t_lst *l);
void			ft_too_much_left_rotate(t_lst *l);
void			ft_too_much_right_rotate(t_lst *l);
void			ft_reverse_or_not_left(t_lst *l);
void			ft_reverse_or_not_right(t_lst *l);
void			ft_fusion_swap(t_lst *l);
void			ft_fusion_rotate(t_lst *l);
void			ft_fusion_reverse_rotate(t_lst *l);
void			ft_save_before(t_lst *l, int **tl, int *ts);
void			ft_come_back(t_lst *l, int *tl, int ts);
int				ft_remove_useless_case(t_lst *l);
void			ft_print_soluce(t_lst *l, const t_bns b);

int				ft_verif(t_lst *l, int s, char c);

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
