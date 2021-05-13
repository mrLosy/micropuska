/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_another_com.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:22 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 23:57:08 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_another_com_pars(t_all *all, char **ptr)
{
	short int	i;
	char		*tmp;
	// char		*tmp2;

	i = 0;
	while (ptr[i++])
		;
	all->argv[all->con].ac = (char **)ft_calloc(i + 2, sizeof(char *));
	i = 0;
	while (ptr[i])
	{
		all->argv[all->con].ac[i + 1] = ptr[i];
		i++;
	}
	tmp = all->argv[all->con].ac[0];
	all->argv[all->con].ac[0] = ft_strdup(all->argv[all->con].str);
	if (!all->argv[all->con].ac[0])
		exit(ft_error("Error in malloc", "", "\n", 2));
	free(tmp);
}

void		ft_another_com(t_all *all, char **env)
{
	short int	h;
	char		*tmp;
	char		**ptr;

	all->com[all->con].a_c = 1;
	tmp = all->argv[all->con].dst;
	ft_skipspace(all->line, &all->i);
	h = all->i;
	while (all->line[all->i] != '|' && all->line[all->i] != ';' &&\
		all->line[all->i] != '\0' && all->line[all->i] != '>' &&\
		all->line[all->i] != '<')
		all->i++;
	all->argv[all->con].dst = ft_strdup_n(&all->line[h], all->i - h);
	if (!all->argv[all->con].dst)
		exit(ft_error("Error in malloc", "", "\n", 2));
	ptr = ft_split(all->argv[all->con].dst, ' ');
	if (!ptr)
		exit(ft_error("Error in malloc", "", "\n", 2));
	ft_another_com_pars(all, ptr);
	ft_checker(all, env);
	free(tmp);
	h = 0;
	free(ptr);
}
