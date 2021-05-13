/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_utilc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 18:36:14 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	for_uiszero(t_printf *list, unsigned int value, int tmp, unsigned int c)
{
	if (value == 0)
		while_c(list, ' ', (list->wh - len_value(list, c)));
	else if (list->is_prec == 1)
		while_c(list, ' ', tmp);
	else
		while_c(list, '0', (list->wh - len_value(list, c)));
	printf_u_value(list, c);
}

void	for_min_uiszero(t_printf *list, unsigned int value,\
	int tmp, unsigned int *c)
{
	if (list->is_prec == 0)
	{
		ft_putchar('-');
		list->v_min = 0;
		*c *= -1;
		while_c(list, '0', tmp - 1);
		printf_u_value(list, *c);
	}
	else
	{
		while_c(list, ' ', tmp - 1);
		printf_u_value(list, value);
	}
}

int		len_u_value(t_printf *list, unsigned int value)
{
	unsigned int	count;

	count = 0;
	if (list->prec == 0 || list->prec <= u_lennbr(value))
	{
		count = u_lennbr(value);
		value < 0 ? list->v_min = 1 : 0;
	}
	else if (value < 0)
	{
		list->v_min = 1;
		count = u_lennbr(value) + ((list->prec - u_lennbr(value) > 0) ?\
			list->prec - u_lennbr(value) : 0);
	}
	else if (list->prec > u_lennbr(value))
	{
		count = list->prec;
	}
	return (count);
}

int		u_lennbr(unsigned int n)
{
	int digits;

	digits = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
