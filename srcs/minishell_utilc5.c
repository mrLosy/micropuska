/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utilc5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:00 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/30 01:16:56 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		only_delete_key(t_all *all, char *str)
{
	char *key = get_key(all->m.env, str);
	int find_order = find_order_by_key(all->m.env, key);
	all->m.env = delete_arrayelem(all->m.env, find_order);
	if (key)
		free(key);
	return(0);
}

void	unset_edit(t_all *all, char *str)
{
	if (boolarrvalue(all->m.env, str))
		only_delete_key(all, str);
}

void	ft_export(t_all *all)
{
	int i;
	char **tmp;

	i = 0;
	tmp = arr_dup(all->m.env);
	sort_by_ascii(tmp);
	print_array_export2(tmp);
	free_array(tmp);
	tmp =  NULL;
}

bool	execpathtest(char *path, int i)
{
	if (is_directory(path))
	{
		if (i)
			puterror_three(NULL, path, ": is a directory", 126);
		return (false);
	}
	else if (!fl_exist(path))
	{
		if (i)
			puterror_three(NULL, path,
				": No such file or directory", 127);
		return (false);
	}
	else if (!can_exec(path))
	{
		if (i)
			puterror_three(NULL, path, ": Permission denied", 126);
		return (false);
	}
	return (true);
}

void	command_call2(t_all *all, int i)
{
	if (all->argv[i].out > 2)
	{
		dup2(all->argv[i].out, 1);
		close(all->argv[i].out);
	}
	if (all->argv[i].in > 2)
	{
		dup2(all->argv[i].in, 0);
		close(all->argv[i].in);
	}


	if (what_run(all, i))
	{

		builtin_runner(all, i);
		exit(0);
	}
	else
	{
		char *tmp = NULL;
		tmp = get_path(all, all->argv[i].ac[0]);
		execve(tmp, all->argv[i].ac, all->m.env);
		free(tmp);
		exit(0);
	}

}
