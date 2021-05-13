/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 18:36:14 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_isleft(t_printf *list, unsigned int value)
{
	unsigned int	tmp;

	tmp = list->wh - len_u_value(list, value);
	if (list->wh > 0 && list->is_prec == 1 && list->prec == 0 && value == 0)
		while_c(list, ' ', list->wh);
	else if (list->wh > 0 && list->prec == 0 && list->rec_prec == 0 && \
		value == 0)
	{
		printf_u_value(list, value);
		while_c(list, ' ', tmp);
	}
	else if (list->prec == 0 && value == 0 && list->wh != 0)
		while_c(list, ' ', list->wh);
	else
		u_isleft_ext(list, value);
}

void	u_isleft_ext(t_printf *list, unsigned int value)
{
	if (list->v_min == 1)
	{
		printf_u_value(list, value);
		while_c(list, ' ', (list->wh - len_u_value(list, value) - 1));
	}
	else
	{
		printf_u_value(list, value);
		while_c(list, ' ', (list->wh - len_u_value(list, value)));
	}
}

void	u_iszero(t_printf *list, unsigned int value)
{
	unsigned int	c;
	unsigned int	tmp;

	c = value;
	tmp = list->wh - len_u_value(list, value);
	if (list->wh > 0 && list->is_prec == 1 && list->prec == 0 && value == 0)
		while_c(list, ' ', list->wh);
	else if (list->rec_prec == 1 && value == 0)
		while_c(list, ' ', list->wh);
	else if (value == 0 && list->wh != 0 && list->prec == 0)
		while_c(list, '0', list->wh);
	else
		for_uiszero(list, value, tmp, c);
}

void	u_isprec(t_printf *list, unsigned int value)
{
	unsigned int	tmp;

	tmp = list->wh - len_u_value(list, value);
	if (list->wh > 0 && list->is_prec == 1 && list->prec == 0 && value == 0)
		while_c(list, ' ', list->wh);
	else if (list->wh != 0 && list->prec == 0 && list->rec_prec == 1)
		while_c(list, ' ', list->wh);
	else
	{
		while_c(list, ' ', tmp);
		printf_u_value(list, value);
	}
}

void	ft_write_u(t_printf *list, unsigned int value)
{
	if ((list->wh > len_u_value(list, value)))
	{
		if (list->is_left == 1)
			u_isleft(list, value);
		else if (list->is_zero == 1)
			u_iszero(list, value);
		else if (list->is_prec == 1)
			u_isprec(list, value);
		else
			u_isprec(list, value);
	}
	else if (list->rec_prec == 1)
		u_isprec(list, value);
	else if (list->is_prec == 1 && list->prec == 0 && value == 0)
		while_c(list, ' ', list->wh);
	else
		printf_u_value(list, value);
}
