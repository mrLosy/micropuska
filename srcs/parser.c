/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:22:06 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 23:25:01 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			count_paths(char *temp)
{
	int i = 0;
	int j = 0;
	while (temp[i])
	{
		if (temp[i] == '=' && i == 4)
		{
			while (temp[i])
			{
				if (temp[i] == ':')
					j++;
				i++;
			}
		}
		i++;
	}
	return (j + 1);
}

int			findch(char *str, char c)
{
	int i = 0;

	while(str[i])
	{
		if (str[i] == c)
		{
			return(i);
		}
		i++;
	}
	return (0);
}

int			findchar(char *str, char c)
{
	int i = 0;

	while(str[i])
	{
		if (str[i] == c)
		{
			return(i);
		}
		i++;
	}
	return (i);
}

char		**write_arr_paths(char *temp, char **paths)
{
	int o = 0;
	while(*temp)
	{
		if (*temp == '/')
		{
			if (findch(temp, ':'))
			{
				paths[o++] = ft_substr(temp, 0, findch(temp, ':'));
				temp += findch(temp, ':');
				temp++;
			}
			else
			{
				paths[o++] = ft_substr(temp, 0, ft_strlen(temp));
				temp += ft_strlen(temp);
			}
		}
		else
			temp++;
	}
	return (paths);
}

int			get_order_paths(t_all *all)
{
	int i;

	i = 0;

	while(all->m.env[i])
	{
		if (ft_strncmp(all->m.env[i], "PATH", 4)  == 0 )
		{
			return (i);
		}
		i++;
	}
	return (0);
}

int			check_path(t_all *all, char *str)
{
	(void)all;
	if (!execpathtest(str, 0))
	{
		return (0);
	}
	return (1);
}

int			get_paths(t_all *all)
{
	if (!all->paths)
	{
		all->paths = (char **)ft_calloc(count_paths(all->m.env[get_order_paths(all)]) + 1, sizeof(char *));
		all->paths = write_arr_paths(all->m.env[get_order_paths(all)], all->paths);
		return (1);
	}
	else if (all->paths)
	{
		if (boolarrvalue(all->m.env, "PATH"))
		{
			all->paths = (char **)ft_calloc(count_paths(all->m.env[get_order_paths(all)]) + 1, sizeof(char *));
			all->paths = write_arr_paths(all->m.env[get_order_paths(all)], all->paths);
			return (1);
		}
		else
		{
			return(0);
		}
	}
	return (1);
}
void 		Run(t_all *all, int i)
{
	char *tmp = NULL;

    tmp = get_path(all, all->argv[i].ac[0]);
    pid_t pid = fork();
	if (pid == -1)
		ft_printf("Unable to fork\n");
	else if (pid > 0)
		waitpid(pid, &g_status, 0);
	else
	{
		if (execve(tmp, all->argv[i].ac, all->m.env) == -1)
		{
			if(!execpathtest(all->argv->str, 0) && !is_path(all->argv->str))
			{
				ft_printf("%s: No such file or directory\n", all->argv->str);
				exit(1);
			}
			else
			{
				execpathtest(all->argv->str, 1);
				exit(0);
			}
		}
	}
	if (tmp)
		free(tmp);

}

char	*get_path(t_all *all, char *str)
{
	int i;

	i = 0;
	int len_arr;;
	char *tmp = NULL;
	char *tmp2 = NULL;

	len_arr = 0;
	if (str)
	{
		len_arr = pp_count_array(all->paths);
		if (check_path(all, str))
			return (ft_strdup(str));
		else
		{
			while (i < len_arr)
			{
				tmp = ft_strjoin(all->paths[i], "/");
				tmp2 = ft_strjoin(tmp, str);
				if (!tmp || !tmp2)
					ft_error("Error in malloc", "", "", 2);
				free(tmp);
				if (!check_path(all, tmp2))
					free(tmp2);
				else
					return (tmp2);
				i++;
			}
		}
	}
	return (NULL);
}

void		ft_parsing(t_all *all)
{
	int	i;

	i = ft_strlen(all->argv[all->con].str);
	if (i == 4 && ft_strncmp(all->argv[all->con].str, "echo", 4) == 0)
		parser_echo(all);
	else if (i == 2 && ft_strncmp(all->argv[all->con].str, "cd", 2) == 0)
		ft_parser_cd(all, all->m.env);
	else if (i == 3 && ft_strncmp(all->argv[all->con].str, "pwd ", 3) == 0)
		ft_pars_pwd(all, all->m.env);
	else if (i == 6 && ft_strncmp(all->argv[all->con].str, "export ", 6) == 0)
		ft_parser_export(all, all->m.env);
	else if (i == 5 && ft_strncmp(all->argv[all->con].str, "unset", 5) == 0)
		ft_parser_unset(all, all->m.env);
	else if (i == 3 && ft_strncmp(all->argv[all->con].str, "env", 3) == 0)
		ft_parser_env_add(all, all->m.env);
	else if (i == 4 && ft_strncmp(all->argv[all->con].str, "exit", 4) == 0)
		parser_exit(all);
	else if (all->line[0] != '\0')
		ft_another_com(all, all->m.env);
}

void		ft_parser_str(t_all *all, char **env)
{
	short int	h;

	h = 0;
	while (all->line[all->i] && all->line[all->i] != ' ' &&\
	all->line[all->i] != '|' && all->line[all->i] != ';' &&\
	all->line[all->i] != '<' && all->line[all->i] != '>')
	{
		if (all->line[all->i] == '\"')
			ft_pars_d_q(all, env, 0);
		else if (all->line[all->i] == '\'')
			ft_pars_s_q(all, 0);
		else if (all->line[all->i] == '$')
			ft_pars_dol(all, env, 0);
		else if (all->line[all->i] == '\\')
			ft_parser_slash(all, 1, 0);
		else
			ft_add_char(all, all->line[all->i], 0);
		all->i++;
	}
}

void		ft_pars(t_all *all, char **env)
{
	short int	h;

	struct_zero(all);
	struct_null(all);
	ft_skipspace(all->line, &all->i);
	h = all->i;
	all->argv[all->con].str = ft_strdup("");
	ft_parser_str(all, env);
	ft_parsing(all);
	struct_free(all);
	all->kostily = all->con;
}

void		ft_parser(t_all *all, char *line)
{
	char		*str;

	all->history->up = 0;
	if (!(ft_strnstr(line, "\n", ft_strlen(line))))
	{
		str = all->line;
		all->line = ft_strjoin(all->line, line);
		free(str);
	}
	else if (ft_strnstr(line, "\n", ft_strlen(line)))
	{
		if (ft_strlen(all->line) > 1)
		{
			if (ft_strlen(all->line) > 1 && all->line[0] != '\n')
				add_history(all);
			all->i = 0;
			ft_pars(all, all->m.env);
			tputs(save_cursor, 1, ft_putchar);
			all_denis_work(all);
		}
	}
}
