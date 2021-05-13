/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:20:22 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 23:39:49 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_pars_pipe(t_all *all, char **env)
{
	all->flag[all->con].pipe = 1;
	check_space(all);
	all->i++;
	all->con++;
	ft_pars(all, env);
}

void		ft_pars_new_com(t_all *all, char **env)
{
	all->flag[all->con].end = 1;
	check_space(all);
	all->i++;
	all->parser_complete = 1;
	all_denis_work(all);
	all->con = 0;
	ft_pars(all, env);
}

void		pars_d_l(t_all *all)
{
	short int	i;

	check_space(all);
	all->ec.space_s = 0;
	all->flag[all->con].d_l = 1;
	all->i += 2;
	ft_skipspace(all->line, &all->i);
	i = all->i;
	while (all->line[all->i] != ' ' && all->line[all->i] != '\0')
		check_slash(all);
	redirect(all, ft_strdup_n(&all->line[i], all->i - i));
	if (all->line[all->i] == ' ')
		ft_skipspace(all->line, &all->i);
	ft_checker(all, all->m.env);
}

void		pars_s_m(t_all *all)
{
	short int	i;

	check_space(all);
	all->ec.space_s = 0;
	all->flag[all->con].s_m = 2;
	all->i++;
	ft_skipspace(all->line, &all->i);
	i = all->i;
	while (all->line[all->i] != ' ' && all->line[all->i] != '\0')
		check_slash(all);
	redirect(all, ft_strdup_n(&all->line[i], all->i - i));
	if (all->line[all->i] == ' ')
		ft_skipspace(all->line, &all->i);
	ft_checker(all, all->m.env);
}

void		pars_s_l(t_all *all)
{
	short int	i;
	char		*tmp;

	check_space(all);
	all->ec.space_s = 0;
	all->flag[all->con].s_l = 1;
	all->i++;
	ft_skipspace(all->line, &all->i);
	i = all->i;
	while (all->line[all->i] != ' ' && all->line[all->i] != '\0')
		check_slash(all);
	tmp = ft_strdup_n(&all->line[i], all->i - i);
	redirect(all, tmp);
	if (all->line[all->i] == ' ')
		ft_skipspace(all->line, &all->i);
	free(tmp);
	ft_checker(all, all->m.env);
}
