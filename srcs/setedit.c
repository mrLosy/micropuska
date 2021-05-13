/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setedit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:22:12 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:22:12 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_edit2(t_all *all)
{
	all->valuefromarr = NULL;
	all->keyfromstr = NULL;
	all->valuefromstr = NULL;
	all->check_eq = 0;
	all->check_eqarra = 0;
	all->str_inarr = 0;
}

void	set_edit3(t_all *all, char *str)
{
	all->keyfromstr = get_key_from_str(str);
	all->str_inarr = find_order_by_key(all->m.env, all->keyfromstr);
	all->check_eqarra = findch(all->m.env[all->str_inarr], '=');
	all->check_eq = findch(str, '=');
	all->valuefromarr = get_value_by_key(all->m.env, all->keyfromstr);
	all->valuefromstr = get_value_from_str(str);
	if (all->valuefromstr || all->check_eq)
	{
		if (all->check_eq && all->valuefromstr)
			rewrite_array(all, str);
		else if (!all->valuefromarr && !all->check_eqarra && all->check_eq)
			rewrite_array(all, str);
	}
}

void	set_edit(t_all *all, char *str)
{
	set_edit2(all);
	if (!boolarrvalue(all->m.env, str))
		all->m.env = add_arrayelem(all->m.env, str);
	else
		set_edit3(all, str);
	if (all->valuefromstr)
		free(all->valuefromstr);
	if (all->keyfromstr)
		free(all->keyfromstr);
	if (all->valuefromarr)
		free(all->valuefromarr);
}
