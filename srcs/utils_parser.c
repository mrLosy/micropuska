/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:22:21 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:22:24 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		add_space(t_all *all)
{
	if ((all->flag[all->con].s_l == 1 || all->flag[all->con].d_l == 1 ||\
	all->flag[all->con].s_m == 1) && all->ec.space_s == 0)
	{
		ft_add_char(all, ' ', 1);
		all->ec.space_s++;
	}
}

void		check_space(t_all *all)
{
	short int	i;

	i = 0;
	if (all->ec.space == 0)
	{
		while (all->argv[all->con].dst[i])
			i++;
		if (all->argv[all->con].dst[i - 1] == ' ')
			all->argv[all->con].dst[i - 1] = '\0';
	}
}

void		ft_add_char(t_all *all, char s, short int h)
{
	char		*tmp;
	char		*mpt;

	tmp = ft_calloc(sizeof(char *), 2);
	if (!tmp)
		exit(ft_error("Error in strdup", "", "", 2));
	tmp[0] = s;
	tmp[1] = '\0';
	if (h == 1)
	{
		mpt = all->argv[all->con].dst;
		all->argv[all->con].dst = ft_strjoin(all->argv[all->con].dst, tmp);
	}
	else
	{
		mpt = all->argv[all->con].str;
		all->argv[all->con].str = ft_strjoin(all->argv[all->con].str, tmp);
	}
	if (!all->argv[all->con].dst || !all->argv[all->con].str)
		exit(ft_error("Error in strdup", "", "", 2));
	free(tmp);
	free(mpt);
}

void		flag_n(t_all *all)
{
	short int	h;

	if (all->line[all->i] == '-' && all->line[all->i + 1] == 'n')
	{
		h = all->i;
		all->i += 2;
		while (all->line[all->i] == 'n')
			all->i++;
		if (all->line[all->i] == ' ')
			all->com[all->con].n = 1;
		else
			all->i = h;
		ft_skipspace(all->line, &all->i);
	}
}

void		ft_sec_argv(t_all *all, char s)
{
	all->ec.space = 0;
	add_space(all);
	ft_add_char(all, s, 1);
}
