/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:20:32 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:20:34 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		struct_free(t_all *all)
{
	all->i = 0;
	free(all->line);
	all->line = ft_strdup("");
	ft_bzero(all->line, ft_strlen(all->line));
}

void		struct_null(t_all *all)
{
	all->error = 0;
	all->com[all->con].echo = 0;
	all->argv[all->con].i = 0;
	all->com[all->con].n = 0;
	all->ec.space_s = 1;
	all->com[all->con].cd = 0;
	all->com[all->con].pwd = 0;
	all->com[all->con].exp = 0;
	all->com[all->con].unset = 0;
	all->com[all->con].exit = 0;
	all->com[all->con].env = 0;
	all->com[all->con].a_c = 0;
	all->argv[all->con].dst = ft_strdup("");
	all->argv[all->con].doll = ft_strdup("");
	all->argv[all->con].file = ft_strdup("");
	if (!all->argv[all->con].doll ||\
	!all->argv[all->con].dst || !all->argv[all->con].file)
		exit(ft_error("Error in strdup", "", "", 2));
}

void		strcut_zero_help(t_all *all)
{
	t_argument		*tmp;
	t_commands		*lrp;
	short int		i;

	i = 0;
	lrp = all->com;
	all->com = ft_calloc(all->con + 1, sizeof(t_commands));
	while (i < all->con)
	{
		all->com[i] = lrp[i];
		i++;
	}
	i = 0;
	free(lrp);
	tmp = all->argv;
	all->argv = ft_calloc(all->con + 1, sizeof(t_argument));
	while (i < all->con)
	{
		all->argv[i] = tmp[i];
		i++;
	}
	i = 0;
	free(tmp);
}

void		struct_zero(t_all *all)
{
	t_flags			*ptr;
	short int		i;

	strcut_zero_help(all);
	i = 0;
	ptr = all->flag;
	all->flag = ft_calloc(all->con + 1, sizeof(t_flags));
	while (i < all->con)
	{
		all->flag[i] = ptr[i];
		i++;
	}
	free(ptr);
	if (!all->flag || !all->argv || !all->com)
		exit(ft_error("Error in malloc", "", "", 2));
	all->argv[all->con].out = -1;
	all->argv[all->con].in = -1;
	all->flag[all->con].d_l = 0;
	all->flag[all->con].s_l = 0;
	all->flag[all->con].s_m = 0;
	all->flag[all->con].end = 0;
	all->flag[all->con].pipe = 0;
}
