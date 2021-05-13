/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:40 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 09:58:22 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		error_exit(t_all *all, char **ex)
{
	if (all->error == 2)
		exit(ft_error("exit: ", ex[0], " : numeric argument required", 255));
	else if (all->error == 1)
		ft_error("exit: ", ex[0], " : too many arguments", 1);
}

void		ft_ex(t_all *all, char **ex, short int i)
{
	while (ex[0][i])
	{
		if (all->line[all->i] == '\"')
			ft_pars_d_q(all, all->m.env, 1);
		else if (all->line[all->i] == '\'')
			ft_pars_s_q(all, 1);
		else if (all->line[all->i] == '$')
			ft_pars_dol(all, all->m.env, 1);
		else if (all->line[all->i])
			ft_sec_argv(all, all->line[all->i]);
		i++;
		all->i++;
	}
	if (ex[1])
		all->error = 1;
	i = 0;
	while (all->argv[all->con].dst[i])
	{
		if (!ft_isdigit(all->argv[all->con].dst[i]))
			all->error = 2;
		i++;
	}
}

void		parser_exit(t_all *all)
{
	short int	i;

	all->com[all->con].exit = 1;
	ft_skipspace(all->line, &all->i);
	all->m.ex = ft_split(&all->line[all->i], ' ');
	if (!all->m.ex)
		exit(ft_error("Error in malloc", "", "", 2));
	i = 0;
	if (all->m.ex[0])
		ft_ex(all, all->m.ex, i);
	all->g_status = ft_atoi(all->argv[all->con].dst);
	g_status = all->g_status;
}
