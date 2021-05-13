/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utilc3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:20:48 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 23:59:06 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	incshlvl(t_all *all)
{
	char	*gtvl;
	int		shlvl;
	char	*tmp;
	char	*tmpvalue;

	gtvl = get_value_by_key(all->m.env, "SHLVL");
	shlvl = ft_atoi(gtvl);
	tmp = NULL;
	tmpvalue = NULL;
	shlvl++;
	tmpvalue = ft_itoa(shlvl);
	tmp = ft_strjoin("SHLVL=", tmpvalue);
	set_edit(all, tmp);
	free(tmp);
	free(tmpvalue);
	free(gtvl);
}

void	handle_signals(int signal_code)
{
	int	status;

	wait(&status);
	if (status == SIGINT || status == SIGQUIT)
	{
		if (signal_code == SIGINT)
		{
			g_status = 128 + status;
			write(1, "\n", 1);
		}
		else if (signal_code == SIGQUIT)
		{
			g_status = 128 + status;
			ft_putstr_fd("Quit: 3\n", 1);
		}
	}
}

void	ft_termcap(t_all *all)
{
	struct	termios term;
	char	*term_name;

	term_name = "xterm-256color";
	tgetent(0, term_name);
	tcgetattr(0, &term);
	all->term = term;
}

t_all	*mini_start(char **env)
{
	t_all	*all;

	all = NULL;
	all = ft_calloc(sizeof(t_all), 1);
	all->history = ft_calloc(sizeof(t_history), 1);
	all->history->current_order_id = 0;
	all->history->count = 0;
	ft_parser_env(all, env);
	ft_termcap(all);
	if (boolarrvalue(all->m.env, "SHLV"))
		incshlvl(all);
	all->parser_complete = 0;
	all->con = 0;
	struct_zero(all);
	g_status = 0;
	signal(SIGINT, handle_signals);
	signal(SIGQUIT, handle_signals);
	return (all);
}

int	ctrl_c()
{
	write(1, "\n", 1);
	return (0);
}
