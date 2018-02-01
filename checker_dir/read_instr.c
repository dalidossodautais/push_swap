/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 02:35:49 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/03/04 02:35:51 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_realloc_char(char **s, int size)
{
	char	*t;
	int		a;

	a = -1;
	if (!(t = (char *)malloc(sizeof(char) * size)))
		exit(1);
	while ((*s)[++a])
		t[a] = (*s)[a];
	t[a] = 0;
	free(*s);
	*s = t;
}

static void	ft_read_file(t_lst l, char **s)
{
	int			a;
	int			b;
	int			size_read;
	char		t[BUFF_SIZE];

	if (!(*s = (char *)malloc(sizeof(char))))
		exit(1);
	a = 0;
	(*s)[0] = 0;
	while ((size_read = read(0, t, BUFF_SIZE)) > 0)
	{
		b = -1;
		if (size_read < 0)
		{
			free(s);
			ft_end(l, -11);
		}
		ft_realloc_char(s, a + size_read + 1);
		while (++b < size_read)
		{
			(*s)[a] = t[b];
			a++;
		}
		(*s)[a] = 0;
	}
}

static int	ft_insert_instr(t_lst l, char *s)
{
	if (*s == 's' && *(s + 1) == 'a')
		return (1);
	if (*s == 's' && *(s + 1) == 'b')
		return (2);
	if (*s == 's' && *(s + 1) == 's')
		return (3);
	if (*s == 'p' && *(s + 1) == 'a')
		return (4);
	if (*s == 'p' && *(s + 1) == 'b')
		return (5);
	if (*s == 'r' && *(s + 1) == 'r' && *(s + 2) == 'a')
		return (9);
	if (*s == 'r' && *(s + 1) == 'r' && *(s + 2) == 'b')
		return (10);
	if (*s == 'r' && *(s + 1) == 'r' && *(s + 2) == 'r')
		return (11);
	if (*s == 'r' && *(s + 1) == 'a')
		return (6);
	if (*s == 'r' && *(s + 1) == 'b')
		return (7);
	if (*s == 'r' && *(s + 1) == 'r')
		return (8);
	ft_end(l, -10);
	return (0);
}

void		ft_read_instr(t_lst *l)
{
	char	*s;
	int		i;
	int		a;

	ft_read_file(*l, &s);
	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			++l->si;
	if (!(l->li = (int *)malloc(sizeof(int) * l->si)))
		exit(1);
	a = 0;
	i = 0;
	while (s[i])
	{
		l->li[a] = ft_insert_instr(*l, s + i);
		i += 3;
		if (l->li[a] > 8)
			++i;
		++a;
	}
	free(s);
}
