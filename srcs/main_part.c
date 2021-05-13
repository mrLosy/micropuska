/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:20:36 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:20:42 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	main_part2(t_all *all)
{
	all->term.c_lflag &= ~(ECHO);
	all->term.c_lflag &= ~(ICANON);
	all->term.c_lflag &= ~(ISIG);
	tcsetattr(0, TCSANOW, &all->term);
	all->line = ft_strdup("");
	if (!all->line)
		exit(ft_error("Error in malloc", "", "", 2));
	ft_putstr_fd("\033[32mminishell$ \x1b[0m", 1);
	tputs(save_cursor, 1, ft_putchar);
}

void	main_part3(t_all *all, char *str, char **env)
{
	(void)env;
	ft_putstr_fd(str, 1);
	ft_parser(all, str);
	if (ft_strnstr(str, "\n", 1))
	{
		ft_putstr_fd("\033[32mminishell$ \x1b[0m", 1);
		tputs(save_cursor, 1, ft_putchar);
	}
}

void	main_part4(t_all *all)
{
	if (ft_strlen(all->line) > 0)
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(delete_character, 1, ft_putchar);
		delete_last_character(&all->line);
	}
}

void	main_part5(t_all *all, int l, char *str, char **env)
{
	while (ft_strcmp(str, "\4"))
	{
		l = read(0, str, 1024);
		str[l] = 0;
		if (!ft_strcmp(str, "\e[A"))
			get_next_command(all);
		else if (!ft_strcmp(str, "\e[B"))
			get_previos_command(all);
		else if (!ft_strcmp(str, "\3"))
		{
			ctrl_c();
			break;
		}
		else if (!ft_strcmp("\4", str))
			ctrl_d();
		else if (!ft_strcmp(str, "\177"))
			main_part4(all);
		else if (is_unprint(str))
			continue ;
		else
			main_part3(all, str, env);
	}
}

int		main(int argc, char **argv, char **env)
{
	t_all		*all;
	char		str[1024];
	int			l;

	(void)argc;
	(void)argv;
	all = mini_start(env);
	l = 0;
	while (ft_strcmp(str, "\4"))
	{
		main_part2(all);
		main_part5(all, l, str, env);
	}
}
