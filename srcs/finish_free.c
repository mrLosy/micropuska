/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:20:27 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 23:04:55 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	flags_free(t_flags *flag)
{
	flag->d_l = 0;
	flag->end = 0;
	flag->pipe = 0;
	flag->s_l = 0;
	flag->s_m = 0;
}

void	command_free(t_commands *com)
{
	com->a_c = 0;
	com->cd = 0;
	com->echo = 0;
	com->env = 0;
	com->env_add = 0;
	com->exit = 0;
	com->exp = 0;
	com->exp_add = 0;
	com->n = 0;
	com->pwd = 0;
	com->unset = 0;
}

void	argv_free(t_all *all, t_argument *argv, short int h)
{
	short int	i;

	free(argv->str);
	free(argv->dst);
	free(argv->doll);
	free(argv->file);
	i = 0;
	if (all->com[h].exp_add == 1)
		free_array(argv->exp);
	i = 0;
	if (all->com[h].unset == 1)
	{
		while (argv->dell[i])
			free(argv->dell[i++]);
		free(argv->dell);
	}
	i = 0;
	if (all->com[h].a_c == 1)
	{
		while (argv->ac[i])
			free(argv->ac[i++]);
		free(argv->ac);
	}
}

void	finish_free(t_all *all)
{
	short int		i;

	i = 0;
	all->con = 0;
	while (i <= all->kostily)
	{
		argv_free(all, &all->argv[i], i);
		command_free(&all->com[i]);
		flags_free(&all->flag[i]);
		i++;
	}
	if (all->paths[0])
		free_array(all->paths);
}
