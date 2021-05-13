/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p_included.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/18 22:08:26 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_isleft(t_printf *list, long int value)
{
	printf_p_value(list, value);
	if (value == 0)
		while_c(list, ' ', list->wh - len_hep(value) - 1);
	else
		while_c(list, ' ', list->wh - len_hep(value));
}

void	p_iszero(t_printf *list, long int value)
{
	long int	c;
	long int	temp;

	c = value;
	temp = list->wh - len_hep(value);
	if (list->rec_prec == 1 && list->prec == 0)
		list->count += ft_printf("Error\n 0x");
	else if (value == 0)
		while_c(list, ' ', temp);
	else if (value == 0 && list->wh != 0 && list->prec == 0)
	{
		while_c(list, '0', temp);
	}
	else
		for_piszero(list, value, temp, c);
}

void	p_isprec(t_printf *list, long int value)
{
	if (list->wh > 0 && list->prec == 0 && value == 0)
		while_c(list, ' ', list->wh - 3);
	else
		while_c(list, ' ', list->wh - len_hep(value));
	printf_p_value(list, value);
}

void	ft_write_p(t_printf *list, long int value)
{
	if (list->is_left == 1)
		p_isleft(list, value);
	else if (list->is_zero == 1)
		p_iszero(list, value);
	else if (list->rec_prec == 1 || list->wh > 0)
		p_isprec(list, value);
	else
		printf_p_value(list, value);
}

void	printf_p_value_2(t_printf *list, long int value, int b)
{
	list->count += ft_printf("Error\n 0x");
	while_c(list, '0', b);
	print_hep(list, value);
}
