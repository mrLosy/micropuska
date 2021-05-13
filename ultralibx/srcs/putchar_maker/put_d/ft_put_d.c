/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 18:36:14 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	d_iszero(t_printf *list, int value)
{
	int		c;
	int		tmp;

	c = value;
	tmp = list->wh - len_value(list, value);
	if (list->v_min == 1)
		for_min_diszero(list, value, tmp, &c);
	else if (list->rec_prec == 1 && value == 0)
		while_c(list, ' ', list->wh);
	else if (value == 0 && list->wh != 0 && list->prec == 0)
		while_c(list, '0', list->wh);
	else
		for_diszero(list, value, tmp, c);
}

void	d_isprec(t_printf *list, int value)
{
	int		tmp;

	tmp = list->wh - len_value(list, value);
	if (list->v_min == 1)
		tmp--;
	if (list->wh != 0 && list->prec == 0 && list->rec_prec == 1)
		while_c(list, ' ', list->wh);
	else
	{
		while_c(list, ' ', tmp);
		printf_value(list, value);
	}
}

void	ft_write_d(t_printf *list, int value)
{
	if ((list->wh > len_value(list, value)))
		ft_write_d_2(list, value);
	else if (list->is_left == 1 || (list->is_prec == 1 && list->wh > 0))
		d_isleft(list, value);
	else if (list->wh == 0 && list->is_prec == 1 && list->rec_prec == 1)
		d_iszero(list, value);
	else if (list->is_prec == 1 && list->rec_prec == 1)
		d_iszero(list, value);
	else if (list->rec_prec == 1)
		d_isprec(list, value);
	else if (list->is_prec == 1 && list->prec == 0 && value == 0)
		;
	else
		printf_value(list, value);
}

void	ft_write_d_2(t_printf *list, int value)
{
	if (list->is_left == 1)
		d_isleft(list, value);
	else if (list->is_left == 0 && list->is_prec == 1 && value != 0)
		d_isprec(list, value);
	else if (list->is_prec == 1 && list->prec == 0)
		d_isleft(list, value);
	else if (list->is_zero == 1)
		d_iszero(list, value);
	else if (list->is_prec == 1)
		d_isprec(list, value);
	else
		d_isprec(list, value);
}

int		ft_put_d(t_printf *list, va_list *name)
{
	int		value;

	value = va_arg(*name, int);
	ft_write_d(list, value);
	return (list->count);
}
