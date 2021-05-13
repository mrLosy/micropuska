/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:25 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:21:26 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*ft_cd(t_all *all, char *str)
{
	char		*tmp;
	short int	i;

	tmp = NULL;
	if (ft_strlen(str) == 0)
	{
		i = 0;
		while (all->m.env[i] && ft_strncmp(all->m.env[i], "HOME=", 5))
			i++;
		if (ft_strncmp(all->m.env[i], "HOME=", 5) == 0)
		{
			tmp = str;
			free(tmp);
			str = ft_strdup(&all->m.env[i][5]);
		}
	}
	return (str);
}

void		ft_parser_cd(t_all *all, char **env)
{
	short int	h;
	char		*tmp;

	tmp = all->argv[all->con].dst;
	ft_skipspace(all->line, &all->i);
	all->com[all->con].cd = 1;
	h = all->i;
	while (all->line[all->i] != ' ' && all->line[all->i] != '\0' &&\
			all->line[all->i] != ';' && all->line[all->i] != '|' &&\
			all->line[all->i] != '>' && all->line[all->i] != '<')
		all->i++;
	all->argv[all->con].dst = ft_strdup_n(&all->line[h], all->i - h);
	if (!all->argv[all->con].dst)
		exit(ft_error("Error in strdup", "", "", 2));
	all->argv[all->con].dst = ft_cd(all, all->argv[all->con].dst);
	ft_checker(all, env);
	free(tmp);
}
