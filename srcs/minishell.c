/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:11 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 09:54:22 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int g_status;

void	builtin_runner_export(t_all *all, int i)
{
	int a;

	a = 0;
	if (all->com[i].exp_add)
	{
		while (all->argv[i].exp[a])
		{
			if(!ft_check_export(all->argv[i].exp[a]))
				ft_error("export: `", \
				all->argv[i].exp[a], "\': not a valid identifier", 1);
			else
				set_edit(all, all->argv[i].exp[a]);
			a++;
		}
	}
	else
		ft_export(all);
}

void	builtin_runner_unset(t_all *all, int i)
{
	int b;

	b = 0;
	(void)all;
	(void)i;
	while (all->argv->dell[b])
	{
		unset_edit(all, all->argv->dell[b]);
		b++;
	}
}

void	builtin_runner_exit(t_all *all)
{
	if (all->error > 0)
		error_exit(all, all->m.exp);
	else
	{
		ft_printf("exit\n");
		if (all->error)
			exit(g_status);
		exit(g_status);
	}
}

void	builtin_runner(t_all *all, int i)
{
	if (all->com[i].echo)
		if (all->com[i].n)
			ft_printf("%s", all->argv[all->con].dst);
		else
			ft_printf("%s\n", all->argv[all->con].dst);
	else if (all->com[i].cd)
		chdir(all->argv[i].dst);
	else if (all->com[i].pwd)
		ft_printf("%s\n", all->argv[i].dst);
	else if (all->com[i].exp)
		builtin_runner_export(all, i);
	else if (all->com[i].unset)
		builtin_runner_unset(all, i);
	else if (all->com[i].env)
		print_env(all->m.env);
	else if (all->com[i].exit)
		builtin_runner_exit(all);
}
