/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d_undersize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 18:36:14 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	d_isleft(t_printf *list, int value)
{
	int		tmp;

	tmp = list->wh - len_value(list, value);
	if (list->is_prec == 1 && list->prec == 0 && value == 0)
		while_c(list, ' ', list->wh);
	else if (list->wh > 0 && list->prec == 0 && list->rec_prec == 0 && \
		value == 0)
	{
		if (list->is_left == 1)
		{
			printf_value(list, value);
			while_c(list, ' ', tmp);
		}
		else
		{
			while_c(list, ' ', tmp);
			printf_value(list, value);
		}
	}
	else if (list->prec == 0 && value == 0 && list->wh != 0)
		while_c(list, ' ', list->wh);
	else
		d_isleft_2(list, value);
}

void	d_isleft_2(t_printf *list, int value)
{
	if (list->v_min == 1)
	{
		printf_value(list, value);
		while_c(list, ' ', (list->wh - len_value(list, value) - 1));
	}
	else
	{
		if (list->is_left == 1)
		{
			printf_value(list, value);
			while_c(list, ' ', (list->wh - len_value(list, value)));
		}
		else
		{
			while_c(list, ' ', (list->wh - len_value(list, value)));
			printf_value(list, value);
		}
	}
}
