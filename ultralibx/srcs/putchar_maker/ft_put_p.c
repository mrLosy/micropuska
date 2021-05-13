/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 18:35:27 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hep(t_printf *list, long int value)
{
	long int		remainder;
	int				i;
	int				j;
	char			hepa[16];

	i = 0;
	j = 0;
	while (value)
	{
		remainder = value % 16;
		if (remainder < 10)
			hepa[j++] = 48 + remainder;
		else
			hepa[j++] = 55 + remainder;
		value = value / 16;
	}
	i = j - 1;
	while (i >= 0)
	{
		ft_putchar_fd_count(list, ft_tolower(hepa[i]), 1);
		i--;
	}
}

int		len_hep(long int value)
{
	long int		remainder;
	int				i;
	int				j;
	long int		cpval;
	char			hepa[16];

	i = 0;
	j = 0;
	cpval = value;
	while (cpval)
	{
		remainder = cpval % 16;
		if (remainder < 10)
			hepa[j++] = 48 + remainder;
		else
			hepa[j++] = 55 + remainder;
		cpval = cpval / 16;
	}
	return (value == 0 ? 2 : j + 2);
}

int		ft_put_p(t_printf *list, va_list *name)
{
	long int	value;

	value = va_arg(*name, long int);
	ft_write_p(list, value);
	return (list->count);
}
