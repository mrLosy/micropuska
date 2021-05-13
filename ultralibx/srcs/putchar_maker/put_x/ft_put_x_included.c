/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 18:36:14 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_isleft(t_printf *list, unsigned int value)
{
	unsigned int	tmp;

	tmp = list->wh - len_x_value(list, value);
	if (list->rec_prec == 0 && list->prec == 0 && \
		list->wh > 0 && list->is_left == 1 && list->is_prec == 1 && value == 0)
		while_c(list, ' ', list->wh);
	else if (list->wh > 0 && list->prec == 0 && list->rec_prec == 0 && \
		value == 0)
	{
		printf_x_value(list, value);
		while_c(list, ' ', tmp);
	}
	else if (list->prec == 0 && value == 0 && list->wh != 0)
		while_c(list, ' ', list->wh);
	else
	{
		printf_x_value(list, value);
		while_c(list, ' ', tmp);
	}
}

void	x_iszero(t_printf *list, unsigned int value)
{
	unsigned int	c;
	unsigned int	tmp;

	c = value;
	tmp = list->wh - len_x_value(list, value);
	if (list->rec_prec == 0 && list->prec == 0 && \
		list->wh > 0 && list->is_zero == 1 && list->is_prec == 1 && value == 0)
		while_c(list, ' ', list->wh);
	else if (list->rec_prec == 1 && value == 0)
		while_c(list, ' ', list->wh);
	else if (value == 0 && list->wh != 0 && list->prec == 0)
		while_c(list, '0', list->wh);
	else
		for_xiszero(list, value, tmp, c);
}

void	x_isprec(t_printf *list, unsigned int value)
{
	unsigned int	tmp;

	tmp = list->wh - len_x_value(list, value);
	if (list->wh != 0 && list->prec == 0 && list->rec_prec == 1)
		while_c(list, ' ', list->wh);
	else if (list->wh > 0 && list->is_prec == 1 \
		&& list->prec == 0 && value == 0)
		while_c(list, ' ', list->wh);
	else
	{
		while_c(list, ' ', tmp);
		printf_x_value(list, value);
	}
}

int		len_x_value(t_printf *list, unsigned int value)
{
	unsigned int	count;

	count = 0;
	if (list->prec == 0 || list->prec <= len_hex(value))
	{
		count = len_hex(value);
		value < 0 ? list->v_min = 1 : 0;
	}
	else if (list->prec > len_hex(value))
	{
		count = list->prec;
	}
	return (count);
}

void	ft_write_x(t_printf *list, unsigned int value)
{
	if ((list->wh > len_x_value(list, value)))
	{
		if (list->is_left == 1)
			x_isleft(list, value);
		else if (list->is_zero == 1)
			x_iszero(list, value);
		else if (list->is_prec == 1)
			x_isprec(list, value);
		else
			x_isprec(list, value);
	}
	else if (list->is_left == 1)
		x_isleft(list, value);
	else if (list->rec_prec == 1)
		x_isprec(list, value);
	else
		printf_x_value(list, value);
}
