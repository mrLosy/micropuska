/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:51:16 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 18:35:27 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_prints(t_printf *list, char *value)
{
	int i;
	int len;

	len = ft_strlen(value);
	i = 0;
	if (list->is_prec == 1)
		while (i < list->prec && i < len)
		{
			ft_putchar_fd_count(list, value[i], 1);
			i++;
		}
	else
		while (value[i])
		{
			ft_putchar_fd_count(list, value[i], 1);
			i++;
		}
	return (i);
}

int		count_tab(t_printf *list, char *value)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(value);
	if (list->wh > 0 && list->prec == 0 && list->is_prec == 0)
		i = list->wh - (list->prec > len ? list->prec : len);
	else
		i = list->wh - (list->prec > len ? len : list->prec);
	return (i);
}

char	*get_line(va_list *name)
{
	char *line;

	if ((line = va_arg(*name, char *)) == NULL)
		line = "(null)";
	return (line);
}

int		put_string(t_printf *list, va_list *name)
{
	int		temp;
	int		count;
	char	*line;

	count = 0;
	line = get_line(name);
	temp = count_tab(list, line);
	if (list->is_left == 1)
	{
		count = ft_prints(list, line) + temp;
		while_c(list, ' ', temp);
	}
	else if ((list->wh > 0 && list->is_prec >= 0) || (list->wh > 0))
	{
		list->is_zero == 0 ? while_c(list, ' ', temp) \
		: while_c(list, '0', temp);
		count = ft_prints(list, line) + temp;
	}
	else
		count = ft_prints(list, line);
	return (count);
}

int		ft_put_s(t_printf *list, va_list *name)
{
	put_string(list, name);
	return (list->count);
}
