/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:52 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:21:55 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*pwdstr(t_all *all)
{
	char	*cwd;
	char	buff[4096 + 1];

	getcwd(buff, 4096);
	cwd = ft_strdup(buff);
	free(all->argv[all->con].dst);
	return (cwd);
}

void		ft_pars_pwd(t_all *all, char **env)
{
	short int	h;

	h = all->i;
	all->com[all->con].pwd = 1;
	ft_skipspace(all->line, &all->i);
	while (all->line[all->i] != ' ' && all->line[all->i] != '\0' &&\
			all->line[all->i] != ';' && all->line[all->i] != '|' &&\
			all->line[all->i] != '>' && all->line[all->i] != '<')
		all->i++;
	all->argv[all->con].dst = pwdstr(all);
	if (!all->argv[all->con].dst)
		exit(ft_error("Error in strdup", "", "", 2));
	ft_checker(all, env);
}
