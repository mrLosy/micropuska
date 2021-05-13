/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:34 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:21:34 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_check_d_q(t_all *all)
{
	short int	i;

	i = all->i;
	if (!all->line[i])
		ft_error("No second [\"]", "", "", 2);
	while (all->line[i] != '\"' && all->line[i] != '\0')
		i++;
	if (all->line[i] != '\"')
		ft_error("No second [\"]", "", "", 2);
}

void		ft_pars_d_q(t_all *all, char **env, short int h)
{
	short int	i;

	all->ec.space++;
	all->i++;
	i = all->i;
	while (all->line[all->i] != '\"' && all->line[all->i] != '\0')
	{
		if (all->line[all->i] == '$')
			ft_pars_dol(all, env, 1);
		else if (all->line[all->i] == '\\')
			ft_parser_slash(all, 2, 1);
		else
		{
			ft_add_char(all, all->line[all->i], h);
			all->i++;
		}
		ft_check_d_q(all);
	}
}

void		ft_pars_s_q(t_all *all, short int h)
{
	short int	i;
	char		*tmp;

	all->ec.space++;
	tmp = all->ec.s_q;
	all->i++;
	i = all->i;
	while (all->line[all->i] != '\'' && all->line[all->i] != '\0')
		all->i++;
	if (all->line[all->i] != '\'')
		ft_error("No second [\']", "", "", 2);
	all->ec.s_q = ft_strdup_n(&all->line[i], all->i - i);
	if (!all->ec.s_q)
		exit(ft_error("Error in strdup", "", "", 2));
	free(tmp);
	rewrite_s_q(all, h, tmp);
}

void		pars_echo(t_all *all, char **env)
{
	if (all->line[all->i] == '\"')
		ft_pars_d_q(all, env, 1);
	else if (all->line[all->i] == '\'')
		ft_pars_s_q(all, 1);
	else if (all->line[all->i] == '\\')
		ft_parser_slash(all, 1, 1);
	else if (all->line[all->i] == '|')
		ft_pars_pipe(all, env);
	else if (all->line[all->i] == ';')
		ft_pars_new_com(all, env);
	else if (all->line[all->i] == '$')
		ft_pars_dol(all, env, 1);
	else if (all->line[all->i] == '<')
		pars_s_m(all);
	else if (all->line[all->i] == '>' && all->line[all->i + 1] == '>')
		pars_d_l(all);
	else if (all->line[all->i] == '>')
		pars_s_l(all);
	else if (all->line[all->i] && !(all->line[all->i] == ' '\
	&& all->line[all->i - 1] == ' '))
		ft_sec_argv(all, all->line[all->i]);
	if (all->line[all->i])
		all->i++;
}
