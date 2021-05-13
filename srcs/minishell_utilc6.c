/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utilc6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:04 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/30 01:02:49 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		is_path(char *path)
{
	int i;

	i = 0;
	while(path[i])
	{
		if (path[i] == '/' || path[i] == '.')
		{
			return(1);
		}
		i++;
	}
	return (0);
}

int	is_unprint(char *str)
{
	if (*str < 32 && (*str != '\n' && *str != 3 && *str != 4))
		return (1);
	return (0);
}

int		what_run(t_all *all, int i)
{
	// ft_putstr_fd("test\n", 2);
	// ft_putnbr_fd(i, 2);
	if (all->com[i].echo)
		return (1);
	if (all->com[i].cd)
		return (1);
	if (all->com[i].pwd)
		return (1);
	if (all->com[i].exp)
		return (1);
	if (all->com[i].exp_add)
		return (1);
	if (all->com[i].env_add)
		return (1);
	if (all->com[i].unset)
		return (1);
	if (all->com[i].exit)
		return (1);
	if (all->com[i].env)
		return (1);
	else
		return (0);
}

int		rewrite_array(t_all *all, char *str)
{
	char *key = get_key(all->m.env, str);
	int find_order = find_order_by_key(all->m.env, key);
	all->m.env = delete_arrayelem(all->m.env, find_order);
	all->m.env = add_arrayelem(all->m.env, str);
	if (key)
		free(key);
	return(0);
}
