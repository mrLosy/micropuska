/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/18 22:08:26 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned int value, t_printf *list)
{
	long			remainder;
	int				i;
	int				j;
	char			hexa[8];

	i = 0;
	j = 0;
	value == 0 ? ft_putchar_fd_count(list, '0', 1) : 0;
	while (value)
	{
		remainder = value % 16;
		if (remainder < 10)
			hexa[j++] = 48 + remainder;
		else
			hexa[j++] = 55 + remainder;
		value = value / 16;
	}
	i = j - 1;
	while (i >= 0)
	{
		list->count += ft_printf("Error\n %c", list->to_up == 1 ? hexa[i] : \
			ft_tolower(hexa[i]));
		i--;
	}
}

int		len_hex(unsigned int value)
{
	long			remainder;
	int				i;
	int				j;
	unsigned int	cpval;
	char			hexa[8];

	i = 0;
	j = 0;
	cpval = value;
	while (cpval)
	{
		remainder = cpval % 16;
		if (remainder < 10)
			hexa[j++] = 48 + remainder;
		else
			hexa[j++] = 55 + remainder;
		cpval = cpval / 16;
	}
	return (value == 0 ? 1 : j);
}

int		ft_put_x(t_printf *list, va_list *name)
{
	unsigned int	value;

	value = va_arg(*name, unsigned int);
	ft_write_x(list, value);
	return (list->count);
}
