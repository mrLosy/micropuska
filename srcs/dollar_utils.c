/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:19:53 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:19:56 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		rewrite_argv(t_all *all, short int h, char *tmp)
{
	if (h == 1)
	{
		tmp = all->argv[all->con].dst;
		all->argv[all->con].dst = ft_strjoin(all->argv[all->con].dst,\
		all->argv[all->con].doll);
	}
	else
	{
		tmp = all->argv[all->con].str;
		all->argv[all->con].str = ft_strjoin(all->argv[all->con].str,\
		all->argv[all->con].doll);
	}
	if (!all->argv[all->con].dst || !all->argv[all->con].str)
		exit(ft_error("Error in strdup", "", "", 2));
	free(tmp);
}

void		slash_dol(t_all *all, short int h)
{
	all->argv[all->con].doll = ft_strdup("");
	ft_add_char(all, all->line[all->i - 1], h);
	ft_parser_slash(all, 1, h);
}
