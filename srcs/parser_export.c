/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:45 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/30 04:02:27 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_check_export(char *str)
{
	short int	i;

	i = 0;
	if (ft_isdigit(str[i]))
		return (0);
	while (str[i] != '=' && str[i] != '\0')
	{
		if (str[i] == '\\')
			i++;
		else if (str[i] == '_' || ft_isalpha(str[i]) || ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void		ft_parser_export(t_all *all, char **env)
{
	short int	h;
	short int	j;
	char		*tmp;

	tmp = NULL;
	h = all->con;
	all->com[all->con].exp = 1;
	ft_skipspace(all->line, &all->i);
	ft_add_env(all, env, '+', &tmp);
	j = all->con;
	all->con = h;
	if (tmp[0] == '\0')
		all->com[all->con].exp_add = 0;
	else
	{
		all->argv[all->con].exp = ft_split(all->argv[all->con].dst, '+');
		if (!all->argv[all->con].exp)
			exit(ft_error("Error in malloc", "", "", 2));
		all->com[all->con].exp_add = 1;
	}
	free(tmp);
	all->con = j;
}
