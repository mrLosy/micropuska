/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:22:09 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/30 01:19:34 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_pipes2_part(t_all *all)
{
	all->pipe_num = all->con;
	all->i_pipe = -1;
	all->fd = (int **)ft_calloc(all->pipe_num + 1, sizeof(int *));
	all->pid = (int *)ft_calloc(all->pipe_num + 1, sizeof(int));
	while (++all->i_pipe < all->pipe_num)
	{
		all->fd[all->i_pipe] = (int *)ft_calloc(2, sizeof(int));
		pipe(all->fd[all->i_pipe]);
	}
}

void	run_pipes2_part2(t_all *all)
{
	all->pid[all->i_pipe] = fork();
	if (all->pid[all->i_pipe] == 0)
	{
		if (all->i_pipe == 0)
		{
			close_fds(all->i_pipe, all->fd, all->pipe_num);
			dup2(all->fd[all->i_pipe][1], 1);
			command_call(all, all->i_pipe);
		}
		else if (all->i_pipe == all->pipe_num)
		{
			close_fds(all->i_pipe, all->fd, all->pipe_num);
			dup2(all->fd[all->i_pipe - 1][0], 0);
			dup2(all->oldfd_stdout, 1);
			command_call(all, all->i_pipe);
		}
		else
		{
			close_fds(all->i_pipe, all->fd, all->pipe_num);
			dup2(all->fd[all->i_pipe - 1][0], 0);
			dup2(all->fd[all->i_pipe][1], 1);
			command_call(all, all->i_pipe);
		}
	}
}

void	run_pipes2_part3(t_all *all)
{
	waitpid(all->pid[all->i_pipe], &all->status, 0);
	if (all->status > 0)
	{
		if (!(g_status == 130 || g_status == 131))
			g_status = all->status;
	}
	if (g_status == 256)
		g_status = 1;
	if (all->i_pipe == 0)
		close(all->fd[all->i_pipe][1]);
	else if (all->i_pipe == all->pipe_num)
	{
		close(all->fd[all->i_pipe - 1][0]);
		dup2(all->oldfd_stdin, 0);
		dup2(all->oldfd_stdout, 1);
	}
	else
	{
		close(all->fd[all->i_pipe - 1][0]);
		close(all->fd[all->i_pipe][1]);
	}
}

int	run_pipes2(t_all *all)
{
	run_pipes2_part(all);
	all->fd[all->i_pipe] = NULL;
	all->i_pipe = -1;
	while (++all->i_pipe <= all->pipe_num)
		run_pipes2_part2(all);
	all->i_pipe = -1;
	while (++all->i_pipe <= all->pipe_num)
		run_pipes2_part3(all);
	all->i_pipe = -1;
	while (++all->i_pipe <= all->pipe_num)
		free(all->fd[all->i_pipe]);
	free(all->fd);
	free(all->pid);
	return (0);
}
