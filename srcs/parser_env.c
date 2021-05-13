/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:37 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/30 03:58:41 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_strlen_d_с(char **str)
{
	short int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_add_env(t_all *all, char **env, char s, char **tmp)
{
	while (all->line[all->i] != '\0' && all->line[all->i] != ';' &&\
		all->line[all->i] != '|' && all->line[all->i] != '>' &&\
		all->line[all->i] != '<')
	{
		if (all->line[all->i] == ' ')
		{
			ft_add_char(all, s, 1);
			all->i++;
			ft_skipspace(all->line, &all->i);
		}
		else if (all->line[all->i] == '$')
			ft_pars_dol(all, env, 1);
		else
		{
			ft_add_char(all, all->line[all->i], 1);
			all->i++;
		}
	}
	*tmp = ft_strdup(all->argv[all->con].dst);
	ft_checker(all, env);
}

void		ft_parser_env_add(t_all *all, char **env)
{
	short int	j;
	short int	h;

	h = all->con;
	all->com[all->con].env = 1;
	ft_skipspace(all->line, &all->i);
	while (all->line[all->i] != '\0' && all->line[all->i] != ';' &&\
		all->line[all->i] != '|' && all->line[all->i] != '>' &&\
		all->line[all->i] != '<')
		all->i++;
	ft_checker(all, env);
	j = all->con;
	all->con = h;
	if (all->argv[all->con].dst[0] == '\0')
		all->com[all->con].env_add = 0;
	else
		all->com[all->con].env_add = 1;
	all->con = j;
}

void		ft_parser_env(t_all *all, char **env)
{
	all->m.count = ft_strlen_d_с(env);
	all->m.env = arr_dup(env);
}
