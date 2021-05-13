/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils_sec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:20:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:20:19 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		rewrite_s_q(t_all *all, short int h, char *tmp)
{
	if (h == 1)
	{
		tmp = all->argv[all->con].dst;
		all->argv[all->con].dst = ft_strjoin(all->argv[all->con].dst,\
		all->ec.s_q);
	}
	else
	{
		tmp = all->argv[all->con].str;
		all->argv[all->con].str = ft_strjoin(all->argv[all->con].str,\
		all->ec.s_q);
	}
	if (!all->argv[all->con].dst || !all->argv[all->con].str)
		exit(ft_error("Error in strdup", "", "", 2));
	free(tmp);
}

void		parser_echo(t_all *all)
{
	all->com[all->con].echo = 1;
	ft_skipspace(all->line, &all->i);
	flag_n(all);
	while (all->line[all->i])
		pars_echo(all, all->m.env);
}
