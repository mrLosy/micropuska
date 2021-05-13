/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_project_sec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:22:26 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:22:27 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_skipspace(char *line, short int *i)
{
	while (line[*i] == ' ')
		*i += 1;
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int		ft_isenv(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else if (c == '_')
		return (1);
	return (0);
}

void	ft_checker(t_all *all, char **env)
{
	if (all->line[all->i] == ';')
		ft_pars_new_com(all, env);
	if (all->line[all->i] == '|')
		ft_pars_pipe(all, env);
	if (all->line[all->i] == '<')
		pars_s_m(all);
	if (all->line[all->i] == '>' && all->line[all->i + 1] == '>')
		pars_d_l(all);
	if (all->line[all->i] == '>')
		pars_s_l(all);
}
