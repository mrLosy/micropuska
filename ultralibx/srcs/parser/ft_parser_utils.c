/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:33:20 by mdenys            #+#    #+#             */
/*   Updated: 2021/03/18 10:42:33 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_value(t_printf *list, int value)
{
	int			len;
	long int	cpval;

	cpval = value;
	len = len_value(list, value);
	if (list->v_min == 1)
	{
		ft_putchar_fd_count(list, '-', 1);
		list->v_min = 0;
		cpval *= -1;
	}
	if (list->rec_prec == 1 && list->prec == 0 && list->wh == 0)
		ft_putnbr_fd_count(list, cpval, 1);
	else if (list->prec < lennbr(value))
		ft_putnbr_fd_count(list, cpval, 1);
	else
	{
		while_c(list, '0', len - lennbr(cpval));
		ft_putnbr_fd_count(list, cpval, 1);
	}
}

void	printf_u_value(t_printf *list, unsigned int value)
{
	unsigned int	len;
	unsigned int	cpval;

	cpval = value;
	len = len_u_value(list, value);
	if (list->v_min == 1)
	{
		ft_putchar_fd_count(list, '-', 1);
		list->v_min = 0;
		cpval *= -1;
	}
	if (list->rec_prec == 1 && list->prec == 0 && list->wh == 0)
		;
	else if (list->prec < u_lennbr(value))
		ft_putnbr_u_fd_count(list, cpval, 1);
	else
	{
		while_c(list, '0', len - u_lennbr(cpval));
		ft_putnbr_u_fd_count(list, cpval, 1);
	}
}

void	printf_x_value(t_printf *list, unsigned int value)
{
	unsigned int	len;
	unsigned int	cpval;

	cpval = value;
	len = len_x_value(list, value);
	if (list->is_prec == 1 && list->prec == 0 && list->wh == 1 && value == 0)
		while_c(list, ' ', list->wh);
	else if (list->prec == 0 && list->is_prec == 1 && \
		value == 0 && list->wh == 0)
		;
	else if (list->rec_prec == 1 && list->prec == 0 && list->wh == 0)
		;
	else if (list->prec < len_hex(value))
		print_hex(cpval, list);
	else
	{
		while_c(list, '0', len - len_hex(cpval));
		print_hex(cpval, list);
	}
}

int		is_digit(char **str, t_printf *params)
{
	int	result;
	int	value;

	result = 0;
	if (ft_isdigit(**str) && ++result)
	{
		while (**str == '0')
		{
			params->is_zero = 1;
			(*str)++;
		}
		if (ft_isdigit(**str))
		{
			value = ft_atoi(*str);
			(*str) += lennbr(value);
			if (params->rec_prec)
			{
				params->rec_prec = 0;
				params->prec = value;
			}
			else
				params->wh = value;
		}
	}
	return (result);
}

int		is_type(char **str, int *cout, va_list *arg, t_printf *params)
{
	int	result;

	result = 0;
	if (**str == 'c' && ++result)
		*cout = ft_put_c(params, arg);
	else if (**str == 's' && ++result)
		*cout = ft_put_s(params, arg);
	else if (**str == 'p' && ++result)
		*cout = ft_put_p(params, arg);
	else if ((**str == 'd' || **str == 'i') && ++result)
		*cout = ft_put_d(params, arg);
	else if (**str == 'u' && ++result)
		*cout = ft_put_u(params, arg);
	else if (**str == '%' && ++result)
		*cout = ft_put_percent(params);
	else if (**str == 'x' && ++result)
		*cout = ft_put_x(params, arg);
	else if (**str == 'X' && ++result)
	{
		params->to_up = 1;
		*cout = ft_put_x(params, arg);
	}
	(*str) += result;
	return (result);
}
