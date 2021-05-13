/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utilc4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:20:57 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/30 01:18:35 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int command_call(t_all *all, int i)
{

	int  fd_stdin;
	int  fd_stdout;

	fd_stdin = dup(STDIN_FILENO);
	fd_stdout = dup(STDOUT_FILENO);
	command_call2(all, i);
	dup2(fd_stdout, 1);
	dup2(fd_stdin, 0);



	return (1);
}

void	op_red(t_all *all, int i)
{
	if (all->argv[i].in != -1)
	{
		close(STD_IN);
		dup2(all->argv[i].in, STD_IN);
	}
	if (all->argv[i].out != -1)
	{
		close(STD_OUT);
		dup2(all->argv[i].out, STD_OUT);
	}
}

void	close_redirections(t_all *all, int i)
{
	if (all->argv[i].in != -1 || all->argv[i].out != -1)
	{
		if (all->argv[i].out != -1 && all->flag[i].pipe)
			;
		else
		{
			dup2(all->oldfd_stdout, STD_OUT);
			dup2(all->oldfd_stdin, STD_IN);
		}
	}
}

void all_denis_work2(t_all *all)
{
	if (what_run(all, all->con))
	{
		op_red(all, all->con);
		builtin_runner(all, all->con);
		close_redirections(all, all->con);
	}
	else
	{
		op_red(all, all->con);
		Run(all, all->con);
		close_redirections(all, all->con);
	}
	tputs(save_cursor, 1, ft_putchar);
}

void all_denis_work(t_all *all)
{
	get_paths(all);
	canon_term_on(all);
	all->oldfd_stdin = dup(0);
	all->oldfd_stdout = dup(1);
	if (all->con == 0)
		all_denis_work2(all);
	else if (all->con >= 1 )
	{
		run_pipes2(all);
		tputs(save_cursor, 1, ft_putchar);
	}
	canon_term_off(all);
	finish_free(all);
}
