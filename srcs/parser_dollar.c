/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:28 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:21:31 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_check_env(t_all *all, char *str)
{
	short int	i;
	short int	flag;
	char		*tmp;

	flag = 0;
	i = ft_strlen(all->argv[all->con].doll);
	if (ft_strncmp(str, all->argv[all->con].doll, i) == 0)
	{
		tmp = all->argv[all->con].doll;
		all->argv[all->con].doll = ft_strdup(&str[i]);
		if (!all->argv[all->con].doll)
			exit(ft_error("Error in strdup", "", "", 2));
		free(tmp);
		flag++;
	}
	return (flag);
}

int			ft_search_env(t_all *all, char **env, char c)
{
	short int	i;
	short int	h;
	short int	flag;

	h = 0;
	i = 0;
	flag = 0;
	while (env[h])
	{
		if (env[h][0] == c)
			flag += ft_check_env(all, env[h]);
		if (flag == 1)
			return (1);
		h++;
	}
	return (0);
}

void		ft_error_in_en(t_all *all)
{
	char	*tmp;

	tmp = all->argv[all->con].doll;
	all->argv[all->con].doll = ft_strdup("");
	if (!all->argv[all->con].doll)
		exit(ft_error("Error in malloc", "", "", 2));
	free(tmp);
}

void		rewrite_dol(t_all *all, short int i, char c)
{
	char	*tmp;

	i = all->i;
	while (ft_isenv(all->line[all->i]))
		all->i++;
	tmp = ft_strdup_n(&all->line[i], all->i - i);
	all->argv[all->con].doll = ft_calloc(sizeof(char *), all->i - i + 1);
	if ((!tmp) || (!all->argv[all->con].doll))
		exit(ft_error("Error in strdup", "", "", 2));
	ft_strcpy(all->argv[all->con].doll, tmp);
	all->argv[all->con].doll[all->i - i] = '=';
	all->argv[all->con].doll[all->i - i + 1] = '\0';
	if (ft_search_env(all, all->m.env, c) != 1)
		ft_error_in_en(all);
	free(tmp);
}

void		ft_pars_dol(t_all *all, char **env, short int h)
{
	short int	i;
	char		*tmp;
	char		c;
	char		*rmp;

	tmp = NULL;
	(void)env;
	i = 0;
	rmp = all->argv[all->con].doll;
	c = all->line[++all->i];
	if (c == '?' && (all->line[all->i + 1] == ' ' ||\
	all->line[all->i + 1] == '\0'))
		all->argv[all->con].doll = ft_itoa(g_status);
	else if (c == '\\')
		slash_dol(all, h);
	else
		rewrite_dol(all, i, c);
	free(rmp);
	rewrite_argv(all, h, tmp);
}
