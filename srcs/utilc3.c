/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 04:22:18 by mdenys            #+#    #+#             */
/*   Updated: 2021/04/29 23:06:50 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_array(char **array)
{
	int len;
	int i;

	i = 0;
	len = pp_count_array(array);
	while (i < len)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

char	**arr_dup(char **array)
{
	int len;
	char **tmp;
	int i;

	len = pp_count_array(array);
	tmp = (char **)ft_calloc(len + 1, sizeof(char *));
	i = 0;
	while (i < len)
	{
		tmp[i] = ft_strdup(array[i]);
		i++;
	}
	tmp[len] = NULL;
	return (tmp);
}


char	*get_key_from_str(char *str)
{
	int i;
	char *tmp;
	int	stop;

	i = 0;
	stop = 0;
	tmp = NULL;
	while(str[i])
	{
		if (str[i] == '=')
		{
			stop = i;
			tmp = ft_substr(str, 0, stop);
			break;
		}
		i++;
	}
	if (!tmp)
	{
		tmp = ft_substr(str, 0, ft_strlen(str));
	}
	return (tmp);
}

char	*get_value_from_str(char *str)
{
	int i;
	char *tmp;
	int	start;

	i = 0;
	start = 0;
	tmp = NULL;
	while(str[i])
	{
		if (str[i] == '=')
		{
			start = i + 1;
			if (start != ft_strlen(str))
				tmp = ft_substr(str, start, ft_strlen(str));
			return (tmp);
		}
		i++;
	}
	return (tmp);
}
