/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_project.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:22:30 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:22:32 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		redirect_sec(t_all *all, char *f)
{
	if (all->argv[all->con].in != -1)
		close(all->argv[all->con].in);
	all->argv[all->con].in = open(f, O_RDONLY, 00644);
	if (all->argv[all->con].in == -1)
		ft_error(f, ": ", strerror(errno), errno);
	all->flag[all->con].s_m = 0;
}

void		redirect(t_all *all, char *f)
{
	if (all->flag[all->con].d_l != 0)
	{
		if (all->argv[all->con].out != -1)
			close(all->argv[all->con].out);
		all->argv[all->con].out = open(f, O_WRONLY | O_APPEND | O_CREAT, 00644);
		if (all->argv[all->con].out == -1)
			ft_error(f, ": ", strerror(errno), errno);
		all->flag[all->con].d_l = 0;
	}
	else if (all->flag[all->con].s_l != 0)
	{
		if (all->argv[all->con].out != -1)
			close(all->argv[all->con].out);
		all->argv[all->con].out = open(f, O_WRONLY | O_TRUNC | O_CREAT, 00644);
		if (all->argv[all->con].out == -1)
			ft_error(f, ": ", strerror(errno), errno);
		all->flag[all->con].s_l = 0;
	}
	else if (all->flag[all->con].s_m != 0)
		redirect_sec(all, f);
}

char		*ft_strdup_n(const char *s1, short int h)
{
	char		*str;
	short int	i;

	i = 0;
	if (!s1)
		return (NULL);
	str = ft_calloc(sizeof(char *), (ft_strlen((char *)s1) + 1));
	if (!str)
		exit(ft_error("Error in malloc", "", "", 2));
	while (s1[i] && i < h)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int			ft_error(char *line, char *str, char *error, int err)
{
	ft_putstr_fd(line, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	g_status = err;
	return (g_status);
}
