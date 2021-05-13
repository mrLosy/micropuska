/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:47:42 by mdenys            #+#    #+#             */
/*   Updated: 2021/03/17 20:25:09 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			szero(t_printf *params)
{
	params->is_left = 0;
	params->is_prec = 0;
	params->is_zero = 0;
	params->prec = 0;
	params->rec_prec = 0;
	params->to_up = 0;
	params->wh = 0;
	params->v_min = 0;
	params->count = 0;
}

int				parser_prtf(char **str, va_list *arg)
{
	t_printf	params;
	int			result;

	result = 0;
	szero(&params);
	if (**str == '%')
	{
		result += write(1, "%", 1);
		(*str) += 1;
		return (result);
	}
	while (**str)
	{
		if (is_flag(str, &params))
			continue ;
		else if (is_star(str, arg, &params))
			continue ;
		else if (is_digit(str, &params))
			continue ;
		else if (is_type(str, &result, arg, &params))
			break ;
		else
			(*str) += 1 && result++;
	}
	return (result);
}

int				is_flag(char **str, t_printf *params)
{
	int	result;

	result = 0;
	if (**str == '-' && ++result)
	{
		if (params->rec_prec)
		{
			params->is_prec = 0;
			params->rec_prec = 0;
		}
		params->is_left = 1;
	}
	else if (**str == '.' && ++result)
	{
		params->prec = 0;
		params->is_prec = 1;
		params->rec_prec = 1;
	}
	(*str) += result;
	return (result);
}

void			is_star2(int *value, t_printf *params)
{
	if (params->rec_prec)
	{
		if (*value < 0)
			params->is_prec = 0;
		else
			params->prec = *value;
		params->rec_prec = 0;
	}
	else
	{
		if (*value < 0)
		{
			params->is_left = 1;
			params->wh = *value * -1;
		}
		else
			params->wh = *value;
	}
}

int				is_star(char **str, va_list *arg, t_printf *params)
{
	int	result;
	int	value;

	result = 0;
	if (**str == '*' && ++result)
	{
		value = va_arg(*arg, int);
		is_star2(&value, params);
	}
	(*str) += result;
	return (result);
}
