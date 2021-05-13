/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d_utilc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 18:36:14 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	for_diszero(t_printf *list, int value, int tmp, int c)
{
	if (value == 0)
		while_c(list, ' ', (list->wh - len_value(list, c)));
	else if (list->is_prec == 1)
		while_c(list, ' ', tmp);
	else
		while_c(list, '0', (list->wh - len_value(list, c)));
	printf_value(list, c);
}

void	for_min_diszero(t_printf *list, int value, int tmp, int *c)
{
	if (list->is_prec == 0)
	{
		ft_putchar_fd_count(list, '-', 1);
		list->v_min = 0;
		*c *= -1;
		while_c(list, '0', tmp - 1);
		printf_value(list, *c);
	}
	else
	{
		while_c(list, ' ', tmp - 1);
		printf_value(list, value);
	}
}

int		lennbr(long int n)
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

void	while_c(t_printf *list, char c, int i)
{
	if (i > 0)
	{
		while (i--)
			ft_putchar_fd_count(list, c, 1);
	}
}

int		len_value(t_printf *list, long int value)
{
	int		count;

	count = 0;
	if (list->prec == 0 || list->prec <= lennbr(value))
	{
		count = lennbr(value);
		value < 0 ? list->v_min = 1 : 0;
	}
	else if (value < 0)
	{
		list->v_min = 1;
		count = lennbr(value) + ((list->prec - lennbr(value) > 0) ?\
			list->prec - lennbr(value) : 0);
	}
	else if (list->prec > lennbr(value))
	{
		count = list->prec;
	}
	return (count);
}
