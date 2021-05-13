/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x_utilc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 18:36:14 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	for_xiszero(t_printf *list, unsigned int value, int tmp, unsigned int c)
{
	if (value == 0)
		while_c(list, ' ', (list->wh - len_x_value(list, c)));
	else if (list->is_prec == 1)
		while_c(list, ' ', tmp);
	else
		while_c(list, '0', (list->wh - len_x_value(list, c)));
	printf_x_value(list, c);
}

void	for_min_xiszero(t_printf *list, unsigned int value, \
	int tmp, unsigned int *c)
{
	if (list->is_prec == 0)
	{
		ft_putchar('-');
		list->v_min = 0;
		*c *= -1;
		while_c(list, '0', tmp - 1);
		printf_x_value(list, *c);
	}
	else
	{
		while_c(list, ' ', tmp - 1);
		printf_x_value(list, value);
	}
}
