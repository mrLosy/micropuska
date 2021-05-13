/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:22:02 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/30 04:00:20 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_parser_unset(t_all *all, char **env)
{
	short int	h;
	short int	j;
	char		*tmp;

	tmp = NULL;
	h = all->con;
	all->com[all->con].unset = 1;
	ft_skipspace(all->line, &all->i);
	ft_add_env(all, env, '+', &tmp);
	free(tmp);
	j = all->con;
	all->con = h;
	all->argv[all->con].dell = ft_split(all->argv[all->con].dst, '+');
	if (!all->argv[all->con].dell)
		exit(ft_error("Error in malloc", "", "", 2));
	all->con = j;
}
