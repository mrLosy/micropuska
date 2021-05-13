/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishelldenis3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:21:20 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 04:21:20 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	delete_last_character(char **str)
{
	int		len;
	char	*pointer;

	len = 0;
	pointer = *str;
	if (*str)
		len = ft_strlen(*str);
	if (len >= 1)
		pointer[len - 1] = '\0';
}

int		count_array(t_all *data)
{
	int i;

	i = 0;
	if (data->history->history_array)
		while (data->history->history_array[i])
			i++;
	return (i);
}

int		pp_count_array(char **data)
{
	int i;

	i = 0;
	if (data)
		while (data[i] != NULL)
			i++;
	return (i);
}

void	get_next_command(t_all *data)
{
	if (data->history->current_order_id >= 0 && data->history->count > 0 \
		&& (data->history->current_order_id - 1 >= 0))
	{
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		if (data->history->up != 1)
			data->history->save_pointer = data->line;
		data->history->up = 1;
		data->line = data->history->history_array\
            [data->history->current_order_id - 1];
		ft_putstr_fd(data->history->history_array\
			[data->history->current_order_id - 1], 1);
		data->history->current_order_id--;
	}
}
