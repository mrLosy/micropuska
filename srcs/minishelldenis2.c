/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishelldenis2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:17 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:21:17 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	t_puts_tmp(void)
{
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
}

void	get_previos_command2(t_all *data)
{
	t_puts_tmp();
	if (!(data->history->current_order_id == data->history->len_array))
	{
		data->line = data->history->save_pointer;
		ft_putstr_fd(data->line, 1);
		data->history->current_order_id++;
	}
	else
	{
		ft_putstr_fd(data->line, 1);
		data->history->save_pointer = NULL;
		data->history->up = 0;
	}
}

void	get_previos_command(t_all *data)
{
	if (data->history->current_order_id + 1 < data->history->len_array)
	{
		t_puts_tmp();
		data->line = ft_strdup(data->history->history_array\
			[data->history->current_order_id + 1]);
		ft_putstr_fd(data->history->history_array\
			[data->history->current_order_id + 1], 1);
		data->history->current_order_id++;
	}
	else if (data->history->current_order_id + 1 == data->history->len_array\
		|| data->history->current_order_id == data->history->len_array)
		get_previos_command2(data);
}

void	add_history2(t_all *data, int i, int len_array, char **tmp)
{
	while (i < len_array)
	{
		tmp[i] = data->history->history_array[i];
		i++;
	}
}

void	add_history(t_all *data)
{
	char	**tmp;
	int		i;
	int		len_array;

	i = 0;
	len_array = count_array(data);
	tmp = (char **)ft_calloc(sizeof(char *), (len_array + 2));
	add_history2(data, i, len_array, tmp);
	if (len_array == 0)
	{
		tmp[0] = ft_strdup(data->line);
		data->history->history_array = tmp;
		data->history->count++;
		data->history->current_order_id = len_array + 1;
	}
	else
	{
		data->history->count++;
		tmp[len_array] = ft_strdup(data->line);
		free(data->history->history_array);
		data->history->history_array = tmp;
		data->history->current_order_id = len_array + 1;
	}
	data->history->len_array = count_array(data);
}
