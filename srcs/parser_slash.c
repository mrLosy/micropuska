/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_slash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:57 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:21:59 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_pars_slash_d_q(t_all *all, unsigned int l)
{
	if (all->line[all->i + 1] == '$' || all->line[all->i + 1] == '\'')
	{
		ft_add_char(all, all->line[++all->i], l);
		all->i++;
	}
	else if (all->line[all->i + 1] == '\\' || all->line[all->i + 1] == '\"')
	{
		ft_add_char(all, all->line[++all->i], l);
		all->i++;
	}
	else
		ft_add_char(all, all->line[all->i++], l);
}

void		ft_parser_slash(t_all *all, unsigned int k, unsigned int l)
{
	if (k == 1)
		ft_add_char(all, all->line[++all->i], l);
	else if (k == 2)
		ft_pars_slash_d_q(all, l);
}

void		check_slash(t_all *all)
{
	if (all->line[all->i] == '\\')
		ft_parser_slash(all, 1, 1);
	all->i++;
}
