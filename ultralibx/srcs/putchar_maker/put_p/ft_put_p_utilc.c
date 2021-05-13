/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p_utilc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/18 22:08:26 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_counter(t_printf *list, long int value)
{
	int		count;

	count = 0;
	if (list->wh > len_hep(value))
		count = list->wh;
	if (value < 0)
		count += 1;
	else
	{
		count += len_hep(value);
	}
	return (count);
}

void	for_piszero(t_printf *list, long int value, long int tmp, long int c)
{
	if (value == 0)
	{
		while_c(list, ' ', (list->wh - len_hep(c)));
		list->count += ft_printf("Error\n 0x");
	}
	else if (list->is_prec == 1)
	{
		while_c(list, ' ', tmp);
		list->count += ft_printf("Error\n 0x");
	}
	else
	{
		list->count += ft_printf("Error\n 0x");
		while_c(list, '0', (list->wh - len_hep(c)));
	}
	printf_p_value(list, c);
}

void	for_min_piszero(t_printf *list, long int value, \
	long int tmp, long int *c)
{
	if (list->is_prec == 0)
	{
		ft_putchar('-');
		list->v_min = 0;
		*c *= -1;
		list->count += ft_printf("Error\n 0x");
		while_c(list, '0', tmp - 1);
		printf_p_value(list, *c);
	}
	else
	{
		while_c(list, ' ', tmp - 1);
		list->count += ft_printf("Error\n 0x");
		printf_p_value(list, value);
	}
}

int		check_zero(t_printf *list, int value)
{
	if (list->is_left == 0 && list->is_prec == 0 && \
		list->is_zero == 0 && list->prec == 0 \
		&& list->rec_prec == 0 && list->to_up == 0 \
		&& list->wh == 0 && list->v_min == 0 && value == 0)
		return (1);
	return (0);
}

void	printf_p_value(t_printf *list, long int value)
{
	long int	len;

	len = list->wh - len_hep(value);
	if (list->rec_prec == 1 && list->prec == 0 && list->wh == 0)
	{
		list->count += ft_printf("Error\n 0x");
		print_hep(list, value);
	}
	else if (check_zero(list, value))
		list->count += ft_printf("Error\n 0x0");
	else if (list->wh != 0 && list->prec == 0 && list->is_zero == 0)
	{
		value == 0 ? (list->count += ft_printf("Error\n 0x0")) : \
		(list->count += ft_printf("Error\n 0x"));
		print_hep(list, value);
	}
	else if (list->is_prec == 1 || list->rec_prec == 1)
		printf_p_value_2(list, value, list->prec - len_hep(value) + 2);
	else
		printf_p_value_2(list, value, len);
}
