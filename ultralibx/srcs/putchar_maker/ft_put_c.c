/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 18:35:27 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_c(t_printf *list, va_list *name)
{
	char	c;
	int		d;

	d = list->wh - 1;
	c = va_arg(*name, int);
	if (list->wh != 0 && list->is_left == 0)
	{
		while_c(list, ' ', d);
		ft_putchar_fd_count(list, c, 1);
		return (list->count);
	}
	else if (list->wh != 0 && list->is_left == 1)
	{
		ft_putchar_fd_count(list, c, 1);
		while_c(list, ' ', d);
		return (list->count);
	}
	else
	{
		ft_putchar_fd_count(list, c, 1);
		return (list->count);
	}
}

int		ft_put_percent(t_printf *list)
{
	int		d;

	d = list->wh - 1;
	if (list->wh != 0 && list->is_left == 0)
	{
		list->is_zero == 0 ? while_c(list, ' ', d) : while_c(list, '0', d);
		ft_putchar_fd_count(list, '%', 1);
		return (list->wh);
	}
	else if (list->wh != 0 && list->is_left == 1)
	{
		ft_putchar_fd_count(list, '%', 1);
		while_c(list, ' ', d);
		return (list->wh);
	}
	else
	{
		ft_putchar_fd_count(list, '%', 1);
		return (1);
	}
}
